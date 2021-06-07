#include <stdio.h>
#include <math.h>

#define N 12 //Number of coordinate values

int main() {
	float coordinates[N][2]; //Initialize array
	
	for (int i = 0; i < N; i++) {
		//In the console, enter the 12 coordinate values on a single line separated by comma and by spaces (ie. 1.1,5.6 5.5,8.2 etc.)
		scanf("%f, %f", &coordinates[i][0],&coordinates[i][1]);
		//prints the array to the terminal
	}
	//for loop that prints the coordinate array with special conditions for printing the last coordinate of each row
	for (int i = 0; i < N; i++) {
		if (i == 5) {
			printf("(%0.1f,%0.1f),\n", coordinates[i][0], coordinates[i][1]);
			continue;
		}
		if ( i == 11) {
			printf("(%0.1f,%0.1f)\n", coordinates[i][0], coordinates[i][1]);
			continue;
		}
		printf("(%0.1f,%0.1f),", coordinates[i][0], coordinates[i][1]);
	}
	printf("\n");

	//initializes the array to store the center x and y
	float center [2] = {0};
	//adds the x and y value of each coordinate on each iteration of the for loop and then divides by the total number of coordinates after exiting the loop to average the values
	for (int i = 0; i < N; i++) {
		center[0] += coordinates[i][0];
		center[1] += coordinates[i][1];
	}
	center[1] = center[1] / N;
	center[0] = center[0] / N;

	//initializes and two arrays to store the distance from each point to another and the average distance from one point to all others
	float distance[N][N];
	float avgDist[(N)];
	//calculates the distance from point i to j and sums the distances from i to each j to average them at the end of the j for loop
	for(int i = 0; i < N; i++) {
		avgDist[i] = 0;
		for (int j = 0; j < N; j++) {
			//calculates the x and y distances and then calculates the Euclidean distance with them
			float deltaX = coordinates[i][0] - coordinates[j][0];
			float deltaY = coordinates[i][1] - coordinates[j][1];
			distance[i][j] = pow(pow(deltaX, 2) + pow(deltaY, 2),0.5);
			avgDist[i] += distance[i][j];
		}
		avgDist[i] = avgDist[i] / 11;
	}

	//prints out the average center of the coordinates
	printf("Average center: (%0.1f,%0.1f)\n\n", center[0], center[1]);

	//prints out the point to point distance array in rows for each i
	for(int i = 0; i < N; i++) {
		printf("Distance from point %i to\n", (i + 1));
		for (int j = 0; j < N; j++) {
			//special condition for when the points are the same
			if (i == j && j != 11) {
				printf("%i.- 0.0, ", (j + 1));
				continue;
			}
			printf("%i.- %0.1f", (j + 1), distance[i][j]);
			//special condition for the last j in the row
			if (j == 11) {
				continue;
			}
			printf(", ");
		}
		printf("\n");
	}
	printf("\n");

	//prints out the average distance from each point i to the other points
	for (int i = 0; i < N; i++) {
		printf("Average distance from point %i: %0.1f km\n", (i + 1), avgDist[i]);
	}
}