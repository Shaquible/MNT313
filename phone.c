//MNTC313 Assignment 2 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!
#include <stdio.h>
#include <math.h>

int main()
{
	
	float L, W, D, R; 
	
	scanf("%f, %f, %f, %f", &L, &W, &D, &R);
	//In the console, enter length, width, depth and radius on a single line, each separated by a comma and space
	float pi = atan(1) * 4.0;
	float radjust = R * R - pi * R * R;
	float SA = L * W -radjust;
}