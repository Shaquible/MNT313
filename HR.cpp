#include <stdio.h>
#define N 20
//Stack defined to do the opperations for the correct hiring firing practices
class Stack
{
public:
    //declares the array used for the stack and the top of the stack
    int stack[N];
    int top;
    //initializes the top of the stack to 0
    Stack()
    {
        top = 0;
    }
    //method to add a new element to the stack
    void push(int data)
    {
        stack[top] = data;
        top++;
    }
    //method to remove the top element  from the stack
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
    printf("Input the operations and IDs:\n");
    for (int i = 0; i < numberOfHROperations; i++)
    {
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        if (operation == '+')
        {
            //adds employee id to the stack when a + is included
            employees.push(id);
        }
        if (operation == '-')
        {
            //popping an employee from the stack reflects the proper firing decision
            employees.pop();
            //checks if the id removed from the stack matches the id that the command told to remove
            //if the employee fired was not the one at the top of the stack, FAIL is printed and  the program exits
            if (employees.stack[employees.top] != id)
            {
                printf("FAIL\n");
                return 0;
            }
        }
    }
    //if a failure condition is not met, the program prints PASS and exits
    printf("PASS\n");
    return 0;
}
