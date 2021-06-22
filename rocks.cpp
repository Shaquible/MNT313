#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
//function prototypes for functions that get a variable and print a message to the terminal
float getFloat(string phrase);
int getInt(string phrase);

int main(void)
{
    //defines variables to that will be set by the user input functions
    float y, depth1, deltaDepth, K, deltaK;
    y = getFloat("Input rock unit weight (kN/m3):\n");
    int Nd = getInt("Input number of depth values:\n");
    depth1 = getFloat("Input first depth value (m):\n");
    deltaDepth = getFloat("Input depth increment (m):\n");
    int Nk = getInt("Input number of k values:\n");
    K = getFloat("Input first k value (m):\n");
    deltaK = getFloat("Input k increment (m):\n");
    //initializes arbitrarily large array for the stress and depth values (it should be dynamically allocated, but we have not learned how to do this)
    float vertStress[50];
    float depth[50];
    float horzStress[50][50];
    //prints initial print statement and opens the output file
    printf("Vertical stress values (kPa):\n");
    FILE *outFile = fopen("outputFileA.txt", "w");

    for (int i = 0; i < Nd; i++)
    {
        //calculates depth and vertical stress at each index and prints vertical stress
        depth[i] = depth1 + (i * deltaDepth);
        vertStress[i] = y * depth[i];
        printf("%.0f\n", vertStress[i]);
        //adds depth column to the outfile
        fprintf(outFile, "%.0f,", depth[i]);
        for (int j = 0; j < Nk; j++)
        {
            //calculates the k values and then the horizontal stress values
            float newK = K + (j * deltaK);
            horzStress[i][j] = newK * vertStress[i];
            //adds horizontal stress values to the output file
            fprintf(outFile, "%.0f", horzStress[i][j]);
            //adds "," to each column but the last
            if (j != (Nk - 1))
            {
                fprintf(outFile, ",");
            }
        }
        //adds new line to the outfile
        fprintf(outFile, "\n");
    }
    //closes file
    fclose(outFile);
}
//function that gets a float from the user and prints the function argument
float getFloat(string phrase)
{
    float x;
    printf("%s", phrase.c_str());
    cin >> x;
    return x;
}

//function that gets a int from the user and prints the function argument
int getInt(string phrase)
{
    int x;
    printf("%s", phrase.c_str());
    cin >> x;
    return x;
}