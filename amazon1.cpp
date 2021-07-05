#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

//defining the payload struct
struct payload
{
    int numCustomer;
    float avgPrice;
    float avgWeight;
};

//definition of economics class
class economics
{
public:
    //defining the values that are not inputted by the user
    float const costPerKG = 4.7;
    float const targetRev = 36000;
    //declares the number of centers
    int numCent;
    //defines a vector of payloads for each center
    //vector is included as a member of the class so it does not have to be passed to each method for calculations
    vector<payload> center;
    //method that sums the total customers from each center in the vector and returns the sum
    int customers(void)
    {
        int totalCustomers = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalCustomers += center[i].numCustomer;
        }
        return totalCustomers;
    }
    //method that sums the total weight from each center in the vector and returns the sum
    float weight(void)
    {
        float totalWeight = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalWeight += center[i].numCustomer * center[i].avgWeight;
        }

        return totalWeight;
    }
    //method that returns the total profit accross all centers by calculating average profit per customer in each center multiplied by the total customers in that center
    float revenue(void)
    {
        float totalRev = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalRev += center[i].numCustomer * (center[i].avgPrice - (center[i].avgWeight * costPerKG));
        }

        return totalRev;
    }
    //method that prints if the company is profitable or not
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
    //gathers the number of centers
    printf("Input number of centers:\n");
    cin >> amazon.numCent;
    //resizes the vector to contain the number of elements defined by the user input
    amazon.center.resize(amazon.numCent);
    //gets data for each center and stores it in the struct member of the class. each data type is collected in a for loop that indexes each center in the vector
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
    //prints the results of the economic calculations to the terminals. The result is calculated in the print statement with the method in the class
    printf("Total customers: %i\n", amazon.customers());
    printf("Total weight: %.0f kg\n", amazon.weight());
    printf("Total revenue: $%.0f\n", amazon.revenue());
    printf("Average revenue: $%.0f\n", amazon.revenue() / amazon.numCent);
    //method is called to print if the company is profitable
    amazon.profitable();
}