#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode(int);
void deletion(int);
void insertion(int);
int countNodes();
void display();

int main()
{
  int node_number, element_data, option,num;

  printf("Enter the number of nodes required:");
  scanf("%d", &node_number);

  for (int i = 0; i < node_number; i++)
  {
    printf("Enter element %d data:", i + 1);
    scanf("%d", &element_data);
    addNode(element_data);
  }

    while(!NULL)
    {
        printf("\nEnter 1-insertion,2-deletion,3-display & 0-exit");
        scanf("%d",&option);
        switch(option)
    {
        case 0:
        exit(0);

        case 1:
        printf("Enter node loc:");
        scanf("%d",&num);
        insertion(num);
        break;

        case 2:
        printf("Enter node loc:");
        scanf("%d",&num);
        deletion(num);
        break;

        case 3:
        display();
        break;

    }
}}

void addNode(int data)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = data;
  newnode->next = NULL;

  if (head == NULL)
  {
    head = newnode;
    tail = newnode;
  }
  else
  {
    tail->next = newnode;
    tail = newnode;
  }
}

void deletion(int node_no)
{
  struct node *node1 = head;
  struct node *node2 = head;
  struct node *temp_loc;
  int count = countNodes();

  if (node_no == 1)
  {
    head=head->next;
  }
  else if (node_no == count)
  {
    for(int i=1;i<node_no;i++)
      {
        node1=node1->next;
      }
    free(node1);
    
    for(int i=1;i<node_no-1;i++)
      {
        node2=node2->next;
      }
    node2->next=NULL;
  }
  else
  {
      for (int i = 1; i < node_no; i++)
    {
      node2 = node2->next;
    }
    for (int i = 2; i < node_no; i++)
    {
      node1 = node1->next;
    }
    node1->next=node1->next->next;
    free(node2);
  }
}
void insertion(int node_no)
{
  int data;
  printf("Enter item to be inserted:");
  scanf("%d",&data);
  
  struct node *node1 = head;
  struct node *node2 = head;
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  int count = countNodes();

  if (node_no == 1)
  {
    new_node->next = head;
    head = new_node;
  }
  else if (node_no == count+1)
  {
    for (int i = 1; i < count; i++)
    {
      node1 = node1->next;
    }
    node1->next=new_node;
    new_node->next=NULL;
  }
  else
  {
    for (int i = 1; i < node_no - 1; i++)
    {
      node1 = node1->next;
    }
    for (int i = 1; i < node_no; i++)
    {
      node2 = node2->next;
    }

    node1->next = new_node;
    new_node->next = node2;
  }
}
int countNodes()
{
  int count = 0;
  struct node *current = head;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

void display()
{
  struct node *current = head;

  if (head == NULL)
  {
    return;
  }
  else
  {
    printf("Elements:");
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
    }
  }
}