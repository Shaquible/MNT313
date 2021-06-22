#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
float getFloat(string phrase)
{
    float x;
    printf("%s", phrase.c_str());
    cin >> x;
    printf("%f\n", x);
    return x;
}
int main(void)
{
    float x = getFloat("test\n");
    printf("%d\n", x);
}