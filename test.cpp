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
  int num_word = 0;
  int test = 0;
  string word;
    string rawline, rawvalue;
    ifstream fileStream("grades.txt");
    while (getline(fileStream, rawline))
    {
        stringstream lineStream(rawline);
        while (lineStream >> word)
        {
          if (word.compare("test") == 0)
          {
            num_word +=1;
          }
          }
        }
     printf("%i", num_word);  
    }
//while (getline(fileStream, rawLine))  the stringstream lineStream(rawline) reads the line in line by line to a string
 //while(linestream >> string) coppies the line to a string word by word