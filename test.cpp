#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(void)
{
    int grades[15];
    string rawline, rawvalue;
    ifstream fileStream("grades.txt");
    for (int i = 0; i < 15; i++)
    {
        getline(fileStream, rawline);
        stringstream lineStream(rawline);
        getline(lineStream, rawvalue, ',');
        istringstream(rawvalue) >> grades[i];
        printf("%i\n", grades[i]);
    }
}