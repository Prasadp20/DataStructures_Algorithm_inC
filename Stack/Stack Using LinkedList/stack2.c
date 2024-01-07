#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Demo{

    int data;
    struct Demo* next;
}demo;

demo* head = NULL;
int countNode = 0;
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
        demo* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}

bool isFull()
{
    if(countNode == eleCount())
    {
        return true;
    }
    else
    {
        return false;
    }
}

demo* createNode()
{
    demo* newNode = (demo*)malloc(sizeof(demo*));

    printf("Enter Data : ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    return newNode;
}

void addNode()
{
    demo* newNode = createNode();

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        demo* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int push()
{
    if(isFull())
    {
        return -1;
    }
    else
    {
        addNode();
        return 0;
    }
}

bool isEmpty()
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

int deleteNode()
{
    int data = 0;
    if(head->next == NULL)
    {
        data = head->data;
        free(head);
        head = NULL;
    }
    else
    {
        demo* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        data = temp->next->data;
        free(temp->next);
        temp->next = NULL;
    }

    return data;
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
        int val = deleteNode();
        flag = 1;
        return val;
    }
}

int printEle()
{
	demo* temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	int data = temp->data;
	return data;
}

int Peek()
{
    if(isEmpty())
    {
        flag = 0;
        return -1;
    }
    else
    {
        int val = printEle();
        flag = 1;
        return val;
    }
}

void main()
{
        printf("Enter stack size : ");
        scanf("%d", &countNode);

        getchar();
        char choise;

        do{

            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Peek\n");

            int ch = 0;
            printf("Enter you choise here : ");
            scanf("%d", &ch);

            switch(ch)
            {
                case 1:
                {
                    int ret = push();
                    if(ret == 0){

                            printf("Data push into stack\n");
                    } else{

                            printf("Stack Overflow\n");
                    }
                }
                break;

                case 2:
                {
                    int ret = Pop();
                    if(flag == 1 && ret != -1){

                        printf("%d is popped\n",ret);
                    }
                    else{

                        printf("Stack is Underflow\n");
                    }
                }
                break;

                case 3:
                {
                    int ret = Peek();
                    if(flag == 1 && ret != -1)
                    {
                        printf("%d\n",ret);
                    }
                    else
                    {
                        printf("Stack is Underflow\n");
                    }
                }
                break;

                default:
                    printf("Ypu entered wrong input\n");
                break;
            }

            getchar();
            printf("Do You Want To Countinue : ");
            scanf("%c", &choise);

        }while(choise == 'y' || choise == 'Y');
}
