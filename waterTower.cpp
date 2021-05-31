#include <stdio.h>
#include<math.h>
#include<stdbool.h>
int main()
{
	float pi =3.14;
	float g = 9.81;
	bool halfTank = false;
	float initialHeight, tankRad, pipeRad,avgV,ht,h30,v,flow;
	int finalT;
	
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	float tankArea = pi * pow(tankRad, 2);
	float pipeArea = pi *pow(pipeRad, 2);
	float curVol= tankArea * initialHeight;
	float curH = initialHeight;
	
	for (int t = 0; t <= finalT || t <= 1800; t++){
		v = sqrt(0.5*g*curH);
		flow = v * pipeArea;
		curVol -= flow;
		curH = curVol/tankArea;
		if (t == finalT){
			avgV = (initialHeight*tankArea -curVol)/(t*pipeArea);
		ht = curH;
			if (curH <= initialHeight/2){
			halfTank = true;
			}
		}
		if (t == 1800){
			h30 = curH;
		}
		}
	
			printf("Average velocity value: %.2f m/s\n", avgV);
			printf("Height value after 30 min: %.2f m\n", h30);
			printf("Height value after %i seconds: %.2f m\n", finalT, ht);
			if (halfTank == true){
				printf("Tank half drained\n");
			}
			else{
				printf("Tank still not half drained\n");
			}
}