#include<stdio.h>
#include<math.h>

int main()
{
	float time, initVel,initAng,initH;
	float pi = 3.14;
	scanf("%f, %f, %f, %f", &time, &initVel, &initAng, &initH);
//checks if time is positive, prints a statement, and ends the program if it's negative
	if (time < 0){
		printf("Projectile not released\n");
		return 0;
	}
	printf("Projectile released\n"); //prints statement if time is positive
	initAng = initAng * pi/180; //converts from deg to rad
	float vy = initVel * sin(initAng); //converts scalar velocity to vertical component of velocity
	vy = vy - (9.81 * time); //updates y velocity to the value at the given time
	float y = initVel * sin(initAng)* time - (4.905 * pow(time,2)) + initH; //computes position from velocity, time, and initial position
	printf("Position: %.2f meters\nVelocity value: %.2f meters/second\n", y, vy); //prints velocity and position
//prints ascending or descending, and above or below initial position based on the vertical velocity and position
	if (vy >= 0){
		printf("Projectile ascending\n");
	}
	else{
     	printf("Projectile descending\n");
	}
	if (y >= initH){
		printf("Projectile above initial position\n");
	}
	else{
		printf("Projectile below initial position\n");
	}
}