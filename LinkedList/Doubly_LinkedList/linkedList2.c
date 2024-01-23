#include<stdio.h>
#include<stdlib.h>

typedef struct Numbers
{
    struct Numbers* pre;
    int number;
    struct Numbers* next;
} numbers;

numbers* head = NULL;

numbers* createNode()
{
    numbers* newNode = (numbers*)malloc(sizeof(numbers*));

    newNode->pre = NULL;
    printf("Enter the number : ");
    scanf("%d", &newNode->number);
    newNode->next = NULL;

    return newNode;
}

void addLastNode()
{
    numbers* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        numbers* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->pre = temp;
    }
}

void addFirstNode()
{
    numbers* newNode = createNode();
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
        numbers* temp = head;
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
        printf("Invalid position\n");
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
            numbers* newNode = createNode();
            numbers* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }

            newNode->pre = temp;
            newNode->next = temp->next;
            temp->next->pre = newNode;
            temp->next = newNode;
        }
        return 0;
    }
}

int deleteLastNode()
{
    if(head == NULL)
    {
        return -1;
    }
    else
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            numbers* temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }

            free(temp->next);
            temp->next = NULL;
        }
        return 0;
    }
}

int deleteFirstNode()
{
    if(head == NULL)
    {
        return -1;
    }
    else
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = head->next;
            free(head->pre);
            head->pre = NULL;
        }
        return 0;
    }
}

int deleteNodeAtPos(int pos)
{
    int count = countNode();
    if(pos <= 0 || pos >= count + 2)
    {
        printf("Invalid position\n");
        return -1;
    }
    else
    {
        if(pos == 1)
        {
            deleteFirstNode();
        }
        else if(pos == count + 1)
        {
            deleteLastNode();
        }
        else
        {
            numbers* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }

            temp->next = temp->next->next;
            free(temp->next->pre);
            temp->next->pre = temp;
        }

        return 0;
    }
}

int printLinkedList()
{
    if(head == NULL)
    {
        return -1;
    }
    else
    {
        numbers* temp = head;
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
    char choice;

    do
    {
        printf("1. Add Node At Last : \n");
        printf("2. Add Node At First : \n");
        printf("3. Add Node At Position : \n");
        printf("4. Delete Last Node : \n");
        printf("5. Delete First Node : \n");
        printf("6. Delete Node At Position : \n");
        printf("7. Print Linked List : \n");

        int ch = 0;
        printf("Enter your choise here : ");
        scanf("%d", &ch);

        int pos = 0;
        switch(ch)
        {
            case 1:
                addLastNode();
            break;

            case 2:
                addFirstNode();
            break;

            case 3:
            {          
                printf("Enter the position to add the node : ");
                scanf("%d", &pos);

                if(pos > 0)
                {
                    int ret = addNodeAtPos(pos);
                }
                else
                {
                    printf("Enter the valid position\n");
                }
            }
            break;

            case 4:
            {
                int ret = deleteLastNode();
                if(ret == -1)
                {
                    printf("Linked list is empty\n");
                }
            }
            break;

            case 5:
            {
                int ret = deleteFirstNode();
                if(ret == -1)
                {
                    printf("Linked list is empty\n");
                }
            }
            break;

            case 6:
            {
                printf("Enter the position to delete the node : ");
                scanf("%d", &pos);
                if(pos > 0)
                {
                    int ret = deleteNodeAtPos(pos);
                }
                else
                {
                    printf("Enter the valid position\n");
                }
            }
            break;

            case 7:
            {
                int ret = printLinkedList();
                if(ret == -1)
                {
                    printf("Linked list is empty\n");
                }
            }
            break;

            default:
                printf("Enter valid option : \n");
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choice);

    } while (choice == 'Y' || choice == 'y');
}