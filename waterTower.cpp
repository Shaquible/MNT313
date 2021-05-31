#include <stdio.h>
#include<math.h>
#include<stdbool.h>


int main() {
	//variables and constants are initialized before entering the for loop so they can be used outside the loop
	float pi =3.14;
	float g = 9.81;
	bool halfTank = false;
	float initialHeight, tankRad, pipeRad,avgV,heightT,height30,v,flow;
	int finalT;
	//gets parameters from the user
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	//establishes cross sectional area to be used when calculating height, volume, and velocity
	float tankArea = pi * pow(tankRad, 2);
	float pipeArea = pi *pow(pipeRad, 2);
	float curVol= tankArea * initialHeight;
	float curH = initialHeight;
	//the for loop iterates for each second to update the height and volume of the tank assmuing that velocity is constant for each second
	for (int t = 0; t <= finalT || t <= 1800; t++) {
		//calculates the velocity of water leaving the pipe
		v = sqrt(0.5*g*curH);
		//calculates the water flowing out of the tank in one second
		flow = v * pipeArea;
		//updates tank volume and water height based on the water flowing out of the tank
		curVol -= flow;
		curH = curVol/tankArea;
		//stores values of height, volume, and average velocity to be printed out if the time value is the user specified one or 30 mins
		if (t == finalT) {
			avgV = (initialHeight*tankArea -curVol)/(t*pipeArea);
			heightT = curH;
			//updates a boolean to check if the tank is half empty 
			if (curH <= initialHeight/2){
			halfTank = true;
			}
		}
		if (t == 1800) {
			height30 = curH;
		}
	}
	//prints values to the terminal
	printf("Average velocity value: %.2f m/s\n", avgV);
	printf("Height value after 30 min: %.2f m\n", height30);
	printf("Height value after %i seconds: %.2f m\n", finalT, heightT);
	//checks if the tank is half empty and prints the appropriate response
	if (halfTank == true) {
		printf("Tank half drained\n");
	}
	else {
		printf("Tank still not half drained\n");
	}
}