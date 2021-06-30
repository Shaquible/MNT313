#include <iostream>
#include <math.h>
#include <stdio.h>
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
    center center[50];
    int numCent;
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
            cout << "Company is profitable\n";
        }
        cout << "Company is not profitable\n";
    }
};

int main(void)
{
    economics amazon;
    cout << "Input number of centers:\n";
    cin >> amazon.numCent;
    cout << "Input customer data for all centers:\n";
    for (int i = 0; i < amazon.numCent; i++)
    {
        cin >> amazon.center[i].numCustomer;
    }
    cout << "Input item average price data for all centers:\n";
    for (int i = 0; i < amazon.numCent; i++)
    {
        cin >> amazon.center[i].avgPrice;
    }
    cout << "Input item average weight data for all centers:\n";
    for (int i = 0; i < amazon.numCent; i++)
    {
        cin >> amazon.center[i].avgWeight;
    }
    cout << "Total customers: " << amazon.customers() << '\n';
    cout << "Total weight: " << amazon.weight() << " kg" << '\n';
    cout << "Total revenue: $" << amazon.revenue() << '\n';
    cout << "Average revenue: $" << amazon.revenue() / amazon.numCent << '\n';
    amazon.profitable();
}