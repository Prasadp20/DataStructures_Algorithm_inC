#include<stdio.h>
#include<stdlib.h>

typedef struct AadharValidation
{
    struct AadharValidation* pre;
    int aadharNo;
    struct AadharValidation* next;
} aadhar;

aadhar* head = NULL;

aadhar* createNode()
{
    aadhar* newNode = (aadhar*)malloc(sizeof(aadhar*));

    newNode->pre = NULL;
    printf("Enter Your Aadhar Number : ");
    scanf("%d", &newNode->aadharNo);
    newNode->next = NULL;

    return newNode;
}

int addLastNode()
{
    aadhar* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        aadhar* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->pre = temp;
    }
}

int addFirstNode()
{
    aadhar* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
    }
}

int countNode()
{
    int count = 0;
    if(head == NULL)
    {
        return count;
    }
    else
    {
        aadhar* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
}

int addNodeAtPos(int pos)
{
    int count = countNode();
    if(pos <= 0 || pos >= count + 2)
    {
        printf("Invalid Position\n");
        return -1;
    }
    else
    {
        if(pos == 1)
        {
            addFirstNode();
        }
        else if(pos == count + 1)
        {
            addLastNode();
        }
        else
        {
            aadhar* newNode = createNode();
            aadhar* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next->pre;
            newNode->pre = temp;
            temp->next = newNode;
            temp->next->pre = newNode;
        }
        return 0;
    }
}

int printLinkedList()
{
    
}

void main()
{
    char choice;

    do
    {
        printf("1. Add First Node : \n");
        printf("2. Add Last Node : \n");
        printf("3. Add Node At Position : \n");
        printf("4. Delete First Node : \n");
        printf("5. Delete Last Node : \n");
        printf("6. Delete Node At Position : \n");
        printf("7. Print Linked List : \n");

        int ch = 0;
        printf("Enter your choice here : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            addFirstNode();
        }
        break;

        case 2:
        {
            addLastNode();
        }
        break;

        default:
            break;
        }
    } while (choice == 'y' || choice == 'Y');
    
}