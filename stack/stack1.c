#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX], top = -1;

void push();
void peek();
int pop();
void output();

int main()
{
    int option;

    while (!NULL)
    {
        printf("\nEnter 1 for push, 2 for peek, 3 for pop, or 0 for exit: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            exit(0);
        case 1:
            push();
            output();
            break;
        case 2:
            peek();
            break;
        case 3:
            pop();
            break;
        default:
            printf("Unknown input\n");
        }
    }
}

void push()
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int num;
        printf("Enter number to be pushed: ");
        scanf("%d", &num);
        stack[++top] = num;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d\n", stack[top]);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        output();
        printf("The popped element is %d \n", stack[top--]);
    }
}

void output()
{
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}
    