// common libraries to include
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string>

//array stuff that might be needed
//to get the number of elements in an array
void size(void)
{
  int array[5] ={1,2,3,4,5};
  int x = sizeof(array)/sizeof(array[0]);
}
// definining an array
//an array can have  empty [] if you are filling it on the same line if not it needs a constant size or it  wont work
int array[] = {1,2,3,4,5,6};
//example of constant
float newArray[15];
//example of defined constant (dont include a ; or a = in this)
#define N 15
//can also define a constant variable for use in an array like this
const int constant = 16;
void garbage(void)
{
int otherArray[N];
int garbage[constant];
}
//baisic function definition wih second variable in pass by reference (don't include & when calling the function)
int func(int a, int &b);

int func(int a, int &b)
{
  int  x = 5;
  return x;
}

//some loop stuff
void bad(void)
{
for (int i = 0; i < 16; i++)
{
  if (i == 6){
    //continue skips the code in the loop for this itteration 
    continue;
  }
  if (i == 11)
  {
    //break exits the loop and does not complete this or any other iterations of the loop
    break;
  }
}
}

//notes on the string class
//make sure to include brackets on all . operations as you are calling a fucntion from the class which could just have void as an argument but still requires the ()
#include<string>
using namespace std;
void stringstuff(void)
{
  string str1 = "this is a string";
  string str2 = "this is another string";
  //retens the length of a sring
  int x = str1.length();
  //compares two strings, returns 0 if they are the same
  x = str1.compare(str2);
  //+=  will add more to the string
  str1 += "this appends the string and adds more to the end";
  //converts string  to a c string for use in fucntions that require std c srings like printf
  //if wanting to use c strings as arguments in functions just use const char* (don't know why but it works)
  const char *str3 = str1.c_str();
}

//notes on user input/output
//sample scanf()
#include<stdio.h>
#include<iostream>
using namespace std;
void out(void){
int  x;
float y;
scanf("%i, %f", &x,&y);
//cin and cout make sure to include iostream and using namespace std
//using cin
cin >> x;
//multiple variables with one cin
cin >> x >> y;
//usin cout (the endl is the equivilent of \n)
cout << "output text" << endl;
//to use variables in cout just seperate them from the string and type the variable name
cout << "output text" << x << y;
}

//fucntion that gets user input and asks them a question first
//uses string class and stdio and iostream
int getInt(string phrase)
{
    int x;
    printf("%s", phrase.c_str());
    cin >> x;
    return x;
}

//reading text files
//for all stuff that is file stream and such
#include<fstream>
//for all of the string stream stuff
#include<sstream>

//example of reading into data stored on a text file of known size and length
const int numLines = 16;
const int numValuesPerLine = 6;
//opens file and initializes the array
int datatable[numLines][numValuesPerLine];
string filename = "inFile.txt";
ifstream fileStream(filename);
string rawLine, rawValue;
for (int i = 0; i < numLines; i++)
{
  //gets the line from the fileStream and outputs it to the rawLine
  getline(fileStream, rawLine);
  //inputs the linestream to a string (from the binary to a string)
  sringstream lineStream(rawLine);
  //not needed but stores the string stream data as a actual string
  string temp = stringstream.str();
  for (int j = 0; j < numValuesPerLine; j++)
  {
    //takes the lineStream that is currently in a string and then outputs it to a new string but parses it at the delimeter ','
    getline(lineStream, rawValue, ',');
    //converts the string to an integer and outputs it to the array
    istringstream(rawValue) >> dataTable[i][j];
  }
}

