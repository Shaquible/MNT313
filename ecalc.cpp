#include<stdio.h>

int fact(int i);
int pow(int x, int y);
int main(void)
{
	int x = 1;
	double e = 1;
	for (int i = 1; i < 34; i++){
	float k= pow(x,i);
	float t = fact(i);
	e += k/t;
	}
	printf("%f", e);
}

int fact(int i){
	unsigned long x=1;
	for (int j =1; j <= i; j++){
	x = x * j;
	}
	return x;
}

int pow(int x, int y){
	unsigned long j = x;
	for (int i = 1; i < y; i++){
	 j = j * x;
	}
	return j;
}