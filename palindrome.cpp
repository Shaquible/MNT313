#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string forward;
	cout << "Enter your word:";
	getline (cin, forward);
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
		cout <<"\nPalindrome\n";
		return 1;
	}
	cout <<"\nNot a palindrome\n";
}