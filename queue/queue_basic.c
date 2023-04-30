#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int Q[SIZE];
int front, rear;
front = -1;
rear = -1;

void enqueue();
void dequeue();
void display(int[]);

int main()
{
    int option;
    while (!NULL)
    {
        printf("\nEnter 0 for exit, 1 for enqueue and 2 for dequeue:");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            exit(0);

        case 1:
            enqueue();
            display(Q);
            break;

        case 2:
            dequeue();
            display(Q);
            break;

        default:
            printf("Invalid input");
        }
    }
}

void enqueue()
{

    if (front == (SIZE - 1) && rear == (SIZE - 1))
    {
        printf("Queue used!!");
    }
    else if (rear == (SIZE - 1))
    {
        printf("Queue full!!\n");
    }
    else
    {
        int enq;
        printf("Enter number to be enqueued:");
        scanf("%d", &enq);
        Q[++rear] = enq;
    }
}

void dequeue()
{
    if (front == rear)
    {
        printf("Queue empty!!");
    }
    else
    {
        front++;
    }
}

void display(int q[])
{
    printf("Queue elements:");

    for (int i = (front + 1); i <= rear; i++)
    {
        printf("%d ", q[i]);
    }
}
