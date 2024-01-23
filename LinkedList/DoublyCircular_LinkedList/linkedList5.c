#include<stdio.h>
#include<stdlib.h>

typedef struct Data
{
    struct  Data* pre;
    int number;
    struct Data* next;
} data;

data* head = NULL;

data* createNode()
{
    data* newNode = (data*)malloc(sizeof(data*));

    newNode->pre = NULL;

    printf("Enter the number : ");
    scanf("%d", &newNode->number);

    newNode->next = NULL;

    return newNode;
}

int addLastNode()
{
    data* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        newNode->pre = head;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;
        newNode->pre = head->pre;
        head->pre->next = newNode;
        head->pre = newNode;
    }
}

int addFirstNode()
{
    data* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->pre = head;
    }
    else
    {
        newNode->next = head; 
        newNode->pre = head->pre;
        head->pre->next = newNode;
        head->pre = newNode;
        head = newNode;
    }
}

int countNode()
{
    int count = 0;
    if(head== NULL)
    {
        return count;
    }
    else
    {
        data* temp = head;
        while(temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        count += 1;
        return count;
    }
}

int addNodeAtPosition(int pos)
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
            data* newNode = createNode();
            data* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next;
            newNode->pre = temp;
            temp->next->pre = newNode;
            temp->next = newNode;
        }
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
        if(head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head->pre = head->pre->pre;
            free(head->pre->next);
            head->pre->next = head;
        }
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
        if(head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head = head->next;
            head->pre = head->pre->pre;
            free(head->pre->next);
            head->pre->next = head;
        }
    }
}

int deleteNodeAtPosition(int pos)
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
            deleteFirstNode();
        }
        else if(pos == count + 1)
        {
            deleteLastNode();
        }
        else
        {
            data* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }

            temp->next = temp->next->next;
            free(temp->next->pre);
            temp->next->pre = temp;
        }
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
        data* temp = head;
        while(temp->next != head)
        {
            printf("| %d ", temp->number);
            temp = temp->next;
        }
        printf("| %d |\n", temp->number);
        return 0;
    }
}

void main()
{
    char choice;

    do
    {
        printf("1. Add Node At LAst\n");
        printf("2. Add Node At First\n");
        printf("2. Add Node At Position\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete First Node\n");

        printf("7. Print Linked List\n");


        int ch = 0;
        printf("Enter your choice here : ");
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
                    addNodeAtPosition(pos);
                else
                    printf("Enter valid position\n");
            }
            break;

            case 4:
            {
                int ret = deleteLastNode();
                if(ret == -1)
                {
                    printf("Linked List is empty\n");
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
                printf("Enter the position to add the node : ");
                scanf("%d", &pos);
                if(pos > 0)
                {
                    int ret = deleteNodeAtPosition(pos);
                }
                else
                {
                    printf("Enter valid position to add the node\n");
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
                printf("Enter valid option\n");
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');
    
}