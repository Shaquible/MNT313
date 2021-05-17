//MNTC313 Assignment 2 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!
#include <stdio.h>
#include <math.h>
int main()
{
	float costrate = 0.0183;
	float batcostrate = 0.0095;
	float L, W, D, R; 
	float pi = 3.14;
	scanf("%f, %f, %f, %f", &L, &W, &D, &R); //In the console, enter length, width, depth and radius on a single line, each separated by a comma and space
	float radjust = R * R - pi * R* R / 4; //calculates the area of the square corner minus the circle
	float SA = L * W - 4 * radjust;
	float V = SA * D;
	int vol = round(V);
	int surface = round(SA * 2 + 2 * D * (L + W) - 8 * R * D + pi * R * 2 * D);
	int matcost = round(costrate * V);
	int batcost = round(batcostrate * V * 0.45);
	printf("iPhone surface area:\n%i mm2\niPhone volume:\n%i mm3\niPhone material cost:\n$ %i\nbattery cost:\n$ %i\n", surface, vol, matcost, batcost);
}