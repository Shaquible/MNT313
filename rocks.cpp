#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
float getFloat(string phrase);
int getInt(string phrase);

int main(void)
{
    float y, depth1, deltaDepth, K, deltaK;
    y = getFloat("Input rock unit weight (kN/m3):\n");
    int Nd = getInt("Input number of depth values:\n");
    depth1 = getFloat("Input first depth value (m):\n");
    deltaDepth = getFloat("Input depth increment (m):\n");
    int Nk = getInt("Input number of k values:\n");
    K = getFloat("Input first k value (m):\n");
    deltaK = getFloat("Input k increment (m):\n");

    float vertStress[50];
    float depth[50];

    printf("Vertical stress values (kPa):\n");
    for (int i = 0; i < Nd; i++)
    {
        depth[i] = depth1 + (i * deltaDepth);
        vertStress[i] = y * depth[i];
        printf("%.0f\n", vertStress[i]);
    }
    float horzStress[50][50];

    FILE *outFile = fopen("outputFileA.txt", "w");
    for (int i = 0; i < Nd; i++)
    {
        fprintf(outFile, "%.0f,", depth[i]);
        for (int j = 0; j < Nk; j++)
        {
            float newK = K + (j * deltaK);
            horzStress[i][j] = newK * vertStress[i];
            fprintf(outFile, "%.0f", horzStress[i][j]);
            if (j != (Nk - 1))
            {
                fprintf(outFile, ",");
            }
        }
        fprintf(outFile, "\n");
    }
    fclose(outFile);
}

float getFloat(string phrase)
{
    float x;
    printf("%s", phrase.c_str());
    cin >> x;
    return x;
}
int getInt(string phrase)
{
    int x;
    printf("%s", phrase.c_str());
    cin >> x;
    return x;
}