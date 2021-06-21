#include <stdio.h>
#include <stdbool.h>
#include <math.h>
//defining constants for the compressive and tensile strength of the matterials
#define tenStrength 5;
#define compStrength 30;

//function prototype for a function that calculates stress
float calcStress(float strain, float mod);

//function prototype for the function that checks if the bridge is safe based on the stress
bool checkStress(float stress);

int main(void)
{
	float mod, strain;
	scanf("%f, %f", &strain, &mod);
	//function that calculates the stress
	float stress = calcStress(strain, mod);
	//Calls the function and gets a bool back deterimining if the bridge is safe or if the strength is exceeded
	bool safe = checkStress(stress);
	//prints calculated stress to terminal
	printf("Stress value: %.2f MPa\n", stress);
	//prints appropriate statements to the terminal based on if the function determines if the bridge is safe and if the bridge is in tension or compression
	if (stress == 0)
	{
		printf("No stress in bridge");
		return 0;
	}
	if (stress > 0)
	{
		printf("Bridge deck in tension\n");
		if (safe == true)
		{
			printf("Bridge deck safe\n");
			return 0;
		}
		printf("Danger: tensile strength exceeded\n");
	}
	if (stress < 0)
	{
		printf("Bridge deck in compression\n");
		if (safe == true)
		{
			printf("Bridge deck safe\n");
			return 0;
		}
		printf("Danger: compressive strength exceeded\n");
	}
}
// function that calculates the stress on the bridge
float calcStress(float strain, float mod)
{
	float stress = mod * strain;
	return stress;
}
bool checkStress(float stress)
{
	//sets the threshold for safety based on if the bridge is in compression or tension
	float threshold = compStrength;
	if (stress > 0)
	{
		threshold = tenStrength;
	}
	//sets safety to true by default and switches it to false if the stress is greater than the threshold
	bool safe = true;
	if (fabs(stress) > threshold)
	{
		safe = false;
	}
	//returns if the bridge is safe or not
	return safe;
}