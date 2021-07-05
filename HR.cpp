#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define N 20
//Stack defined to do the opperations for the correct hiring firing practices
class Stack
{
public:
    int stack[N];
    int top;
    Stack()
    {
        top = 0;
    }
    void push(int data)
    {
        stack[top] = data;
        top++;
    }
    void pop()
    {
        top--;
    }
};
using namespace std;
int main(void)
{
    Stack employees;
    //Ask for the number of HR operations and read
    printf("Enter the number of HR operations:\n");
    //Ask for the operations and IDs
    int numberOfHROperations;
    scanf("%i", &numberOfHROperations);
    //vector used to store the ids of employees currently employed
    vector<int> ids;
    printf("Input the operations and IDs:\n");
    for (int i = 0; i < numberOfHROperations; i++)
    {
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        if (operation == '+')
        {
            employees.push(id);
            ids.push_back(id);
        }
        if (operation == '-')
        {
            employees.pop();
            vector<int>::iterator it = find(ids.begin(), ids.end(), id);
            ids.erase(it);
        }
    }

    //Solve the question
    for (int i = 0; i < employees.top; i++)
    {
        if (ids[i] == employees.stack[i])
        {
            continue;
        }
        cout << "FAIL" << endl;
        return 0;
    }
    cout << "PASS" << endl;
    return 0;
}
