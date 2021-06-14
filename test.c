#include <stdio.h>
int fact(int num, int facts[])
{
    int numfact = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            facts[numfact] = i;
            numfact += 1;
        }
    }
    return numfact;
}
int main(void)
{
    int num = 150;
    int facts[20000];
    int size = fact(num, facts);
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", facts[i]);
    }
}