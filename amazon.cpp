struct payload
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

    int customers(payload center[], int numCent)
    {
        int totalCustomers = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalCustomers += center[i].numCustomer;
        }
        return totalCustomers;
    }

    int weight(payload center[], int numCent)
    {
        int totalWeight = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalWeight += center[i].numCustomer * center[i].avgWeight;
        }
        return totalWeight;
    }
    int revenue(payload center[], int numCent)
    {
        int totalRev = 0;
        for (int i = 0; i < numCent; i++)
        {
            totalRev += center[i].numCustomer * center[i].avgPrice;
        }
        return totalRev;
    }
};

int main(void)
{
}