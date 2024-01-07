#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int number;
    struct Node *next;
} node;

node* head = NULL;
int nodeCount = 0;
int flag = 0;

int eleCount()
{
    int count = 0;
    if(head == NULL)
    {
        return count;
    }
    else
    {
        node* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
}

bool IsFull()
{
    if(nodeCount == eleCount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

node* createNode()
{
    node* newNode = (node*)malloc(sizeof(node*));
    if(newNode == NULL)
    {
        printf("Memory (Heap) Full\n");
        exit(0);
    }

    printf("Enter Data : ");
    scanf("%d", &newNode->number);
    newNode->next = NULL;

    return newNode;
}

void addNode()
{
    node* newNode = createNode();

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        node* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int Push()
{
    if(IsFull())
    {
        return -1;
    }
    else
    {
        addNode();
        return 0;
    }
}

int deleteNode()
{
    int val = 0;
    if(head->next == NULL)
    {
        val = head->number;
        free(head);
        head = NULL;
    }
    else
    {
        node* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        val = temp->next->number;
        free(temp->next);
        temp->next = NULL;
    }

    return val;
}

int Pop()
{
    if(isEmpty())
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        int val = deleteNode();
        return val;
    }
}
void main()
{

}