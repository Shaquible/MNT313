#include<stdio.h>
#include<stdbool.h>
int main(void)
{
	signed long max = 100;
	bool prime = false;
	int count = 0;
	for (int i = 2; i <= max; i++){
		prime = true;
		for (int j = 2; j < i; j++){
			float check = i%j;
			if (check == 0){
				prime = false;
				break;
			}
		}
		if (prime == true){
			printf("%i\n", i);
			count ++;
		}
	}
	printf("\n%i primes under %i\n", count, max);
}