#include <stdio.h>
#include <math.h>
int main()
{
	float costrate = 0.0183; //cost of phone per mm^3
	float batcostrate = 0.0095; // cost of battery per mm^3
	float L, W, D, R; 
	float pi = 3.14;
	scanf("%f, %f, %f, %f", &L, &W, &D, &R); //In the console, enter length, width, depth and radius on a single line, each separated by a comma and space
	float radjust = pow(R,2) - pi * pow(R,2) / 4; //calculates the area of the square corner minus the circle
	float A = L * W - 4 * radjust; //computes the area of the top of the phone by calculating it as a square and subtracting the missing corner space
	float V = A * D; // calculates volume
	int vol = round(V); // rounds volume to a whole number
	int surface = round(A * 2 + 2 * D * (L + W) - 8 * R * D + pi * R * 2 * D); // computes total surface area with area of top, sides, then subtracts the square corners and adds the area of the circles
	int matcost = round(costrate * V); //computes cost of materials with volume and cost per mm^3
	int batcost = round(batcostrate * V * 0.45); //computes cost of batter with the volume of 45% total and cost of bat per mm^3
	printf("iPhone surface area:\n%i mm2\niPhone volume:\n%i mm3\niPhone material cost:\n$%i\nbattery cost:\n$%i\n", surface, vol, matcost, batcost); // prints the calculated values
}