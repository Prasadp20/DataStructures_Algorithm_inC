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
        while(temp->next != NULL)
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

int printEle()
{
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    int val = temp->number;
    return val;
}

bool IsEmpty()
{
    if(eleCount() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Pop()
{
    if(IsEmpty())
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

int Peek()
{
    if(IsEmpty())
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        int val = printEle();
        return val;
    }
}

void main()
{
    char choise;
    printf("Enter the size of stack : ");
    scanf("%d", &nodeCount);

    do
    {
        printf("1. Push : \n");
        printf("2. Pop : \n");
        printf("3. Peek : \n");

        int ch = 0;
        printf("Enter your choise here : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                int ret = Push();
                if(ret == -1)
                {
                    printf("Stack is Overflow\n");
                }
            }
            break;

            case 2:
            {
                int ret = Pop();
                if(flag == 0)
                {
                    printf("Stack is Underflow\n");
                }
                else
                {
                    printf("%d is popped\n", ret);
                }
            }
            break;

            case 3:
            {
                int ret = Peek();
                if(flag == 0)
                {
                    printf("Stack is Underfow\n");
                }
                else
                {
                    printf("%d  \n", ret);
                }
            }
            break;
            
            default:
            {
                printf("Enter valid option\n");
            }
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choise);

    } while (choise == 'Y' || choise == 'y');
    
}