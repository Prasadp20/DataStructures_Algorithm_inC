#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int number;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int flag = 0;

Node* CreateNode()
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
    if(newNode == NULL)
    {
        printf("Memory (Heap) Full\n");
        exit(0);
    }

    printf("Enter Number : ");
    scanf("%d", &newNode->number);
    newNode->next = NULL;

    return newNode;
}

void Enqueue()
{
    Node* newNode = CreateNode();
    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int Dequeue()
{
    if(front == NULL)
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        int val = front->number;
        if(front->next == NULL)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            Node* temp = front;
            front = front->next;
            free(temp);
        }

        return val;
    }
}

int Frontt()
{
    if(front == NULL)
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        return front->number;
    }
}

int PrintQueue()
{
    if(front == NULL)
    {
        return -1;
    }
    else
    {
        Node* temp = front;
        while(temp != NULL)
        {
            printf("%d  ", temp->number);
            temp = temp->next;
        }

        printf("\n");
        return 0;
    }
}

void main()
{
    char choise;

    do
    {
        printf("1. Enqueue : \n");
        printf("2. Dequeue : \n");
        printf("3. Front : \n");
        printf("4. Print Queue : \n");

        int ch = 0;
        printf("Enter your choise here : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                Enqueue();
            }
            break;

            case 2:
            {
                int ret = Dequeue();
                if(flag == 0)
                {
                    printf("Queue is Underflow\n");
                }
                else
                {
                    printf("%d is dequeue\n", ret);
                }
            }
            break;

            case 3:
            {
                int ret = Frontt();
                if(flag == 0)
                {
                    printf("Queue is Underflow\n");
                }
                else
                {
                    printf("%d \n", ret);
                }
            }
            break;

            case 4:
            {
                int ret = PrintQueue();
                if(ret == -1)
                {
                    printf("Queue is Empty\n");
                }
            }
            break;

            default:
            {
                printf("Enter valid option : ");
            }
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choise);

    } while(choise == 'Y' || choise == 'y');
}