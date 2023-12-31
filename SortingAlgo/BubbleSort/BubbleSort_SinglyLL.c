#include<stdio.h>
#include<stdlib.h>

typedef struct Demo
{
    int data;
    struct Demo* next;
} demo;

demo* head = NULL;

demo* createNode()
{
       demo* newNode = (demo*)malloc(sizeof(demo*));

       printf("Enter Data : ");
       scanf("%d", &newNode->data);
       newNode->next = NULL;

       return newNode;
}

void addLastNode()
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

int countNode()
{
    int count = 0;
    demo* temp = head;
    while(temp != NULL)
    {
        ++count;
        temp = temp->next;
    }

    return count;
}

void BubbleSort()
{
    demo* temp = head;
    int count = countNode();

    while(temp != NULL)
    {
        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < count - i - 1; j++)
            {
                if(temp->data > (temp + 1)->data)
                {
                    int nav = temp->data;
                    temp->data = (temp + 1)->data;
                    (temp + 1)->data = nav;
                }
            }
        }
    }
}

void printLinkedList()
{
    if(head == NULL)
    {
        printf("Linked List Is Empty\n");
    }
    else
    {
        printf("Linked list before sorting : ");
        demo* temp = head;
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");

        BubbleSort();
        
        printf("Linked list after sorting : ");
        while(temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(void)
{
    addLastNode();
    addLastNode();
    printLinkedList();
    
    return(0);
}