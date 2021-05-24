//MNTC313 Assignment 3 Starter Code
//You will need to add headers, variables, calculations and print statements to complete the code
//Variables for user input have been provided already
//Do not alter the user input statement unless you are comfortable with user input already!

#include<stdio.h>
#include<math.h>
int main()
{
	float time, initVel,initAng,initH;
	float pi = 3.14;
	scanf("%f, %f, %f, %f", &time, &initVel, &initAng, &initH);
	if (time < 0)
	{
		printf("Projectile not released\n");
		return 0;
	}
	printf("Projectile released\n");
	initAng = initAng * pi/180;
	float vy = initVel * sin(initAng);
	vy = vy - (9.81 * time);
	float y = initVel * sin(initAng)* time - (4.905 * pow(time,2)) + initH;
	printf("Position: %.2f meters\nVelocity value: %.2f meters/second\n", y, vy);
	if (vy >= 0)
	{
		printf("Projectile ascending\n");
	}
	else
	{
     printf("Projectile descending\n");
		}
	if (y >= initH)
	{
		printf("Projectile above initial position\n");
	}
	else
	{
		printf("Projectile below initial position\n");
	}
	//In the console, enter time, initial velocity, initial angle and initial heigth values on a single line separated by a comma and space. 
	
}