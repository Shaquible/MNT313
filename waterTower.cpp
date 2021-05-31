#include <stdio.h>
#include<math.h>
#include<stdbool.h>
int main()
{
	float pi =3.14;
	float g = 9.81;
	bool halfTank = false;
	float initialHeight, tankRad, pipeRad,avgV,ht,h30;
	int finalT;
	
	scanf("%f, %f, %f, %d", &initialHeight, &tankRad, &pipeRad, &finalT);
	float curVol= pow(tankRad, 2) * pi *initialHeight;
	float curH = initialHeight;
	for (int t = 0; t <= finalT || t <= 1800; t++){
		float v = 0.5 * sqrt(g*curH);
		float flow = v * pi * pow(pipeRad, 2);
		curVol = curVol - flow;
		curH = curVol/(pi *pow(tankRad, 2));
		if (t == finalT){
			//avgV = (volInit - curVol)/t;
			avgV = v;
		ht = curH;
			if (curH <= initialHeight/2){
			halfTank = true;
			}
		}
		if (t == 1800){
			h30 = curH;
		}
		}
	
			printf("Average velocity value: %.2f\n", avgV);
			printf("Height value after 30 min: %.2f\n", h30);
			printf("Height value after %i seconds: %.2f\n", finalT, ht);
			if (halfTank == true){
				printf("Tank half drained\n");
			}
			else{
				printf("Tank still not half drained\n");
			}
}