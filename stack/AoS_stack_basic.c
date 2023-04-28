#include <stdio.h>
#include <stdlib.h>

#define MAX 5
typedef struct Stack
{
    int stack[MAX];
    int top;
} Struct_stack;
Struct_stack stack1;


void push();
void peek();
void pop();
void output();

int main()
{
    int option;
    stack1.top = -1;
    while (!NULL)
    {
        printf("\nEnter 1 for push, 2 for peek, 3 for pop, or 0 for exit:");
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
            output();
            break;
        default:
            printf("Unknown input\n");
        }
    }
}

void push()
{
    if (stack1.top == (MAX - 1))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int num;
        printf("Enter number to be pushed: ");
        scanf("%d", &num);
        stack1.stack[++stack1.top] = num;
    }
}

void peek()
{
    if (stack1.top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d\n", stack1.stack[stack1.top]);
    }
}

void pop()
{
    if (stack1.top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        stack1.top--;
    }
}

void output()
{
    printf("Stack elements: ");
    for (int i = 0; i <= stack1.top; i++)
    {
        printf("%d ", stack1.stack[i]);
    }
    printf("\n");
}
