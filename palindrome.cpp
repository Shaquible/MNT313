#include<stdio.h>
#include<string>
using namespace std;
int main(void)
{
	string forward = "test";
	string reverse = forward;
	int len = forward.length();
	for (int i = 0; i < len; i++) 
	{
		int j = len - 1 - i;
		reverse[j] = forward[i];
	}
	int comp = forward.compare(reverse);
	if(comp == 0)
	{
		printf("palindrome\n");
		return 1;
	}
	printf("not palindrome\n");
}