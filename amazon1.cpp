#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
struct center
{
    int numCustomer;
    float avgPrice;
    float avgWeight;
};

class economics
{
public:
    float costPerKG = 4.7;
    float targetRev = 36000;
    int numCent;
    vector<center> center;
    
    int customers(void)
    {
        int totalCustomers = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalCustomers += center[i].numCustomer;
        }
        return totalCustomers;
    }

    int weight(void)
    {
        float totalWeight = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalWeight += center[i].numCustomer * center[i].avgWeight;
        }
        int Weight = round(totalWeight);
        return Weight;
    }
    int revenue(void)
    {
        float totalRev = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalRev += center[i].numCustomer * (center[i].avgPrice - center[i].avgWeight * costPerKG);
        }
        int Rev = round(totalRev);
        return Rev;
    }
    void profitable(void)
    {
        if (revenue() >= targetRev)
        {
            printf("Company is profitable\n");
            return;
        }
        printf("Company is not profitable\n");
        return;
    }
};

int main(void)
{
    economics amazon;
    printf("Input number of centers:\n");
    cin >> amazon.numCent;
    amazon.center.resize(amazon.numCent);
    printf("Input customer data for all centers:\n");
    for (int i = 0; i < amazon.numCent; i++)
    {
        cin >> amazon.center[i].numCustomer;
    }
    printf("Input item average price data for all centers:\n");
    for (int i = 0; i < amazon.numCent; i++)
    {
        cin >> amazon.center[i].avgPrice;
    }
    printf("Input item average weight data for all centers:\n");
    for (int i = 0; i < amazon.numCent; i++)
    {
        cin >> amazon.center[i].avgWeight;
    }
    printf("Total customers: %i\n", amazon.customers());
    printf("Total weight: %i kg\n", amazon.weight());
    printf("Total revenue: $%i\n", amazon.revenue());
    printf("Average revenue: $%i\n", amazon.revenue()/amazon.numCent);
    amazon.profitable();
}