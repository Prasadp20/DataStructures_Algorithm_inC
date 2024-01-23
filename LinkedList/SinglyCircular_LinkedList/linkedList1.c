#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;

node* head = NULL;

node* createNode()
{
    node* newNode = (node*)malloc(sizeof(node*));
    if(newNode == NULL)
    {
        printf("Memory (Heap) Full\n");
        exit(0);
    }

    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    return newNode;
}

int addLastNode()
{
    node* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

int addFirstNode()
{
    node* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;

        node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
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
        node* temp = head;
        while(temp->next != head)
        {
            count++;
            temp = temp->next;
        }
        ++count;
        return count;
    }
}

int addNodeAtPosition(int pos)
{
    int count = countNode();
    if(pos <= 0 || pos >= count + 2)
    {
        printf("Invalis position\n");
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
            node* newNode = createNode();
            node* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }
            newNode->next = temp->next;
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
        if(head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            node* temp = head;
            while(temp->next->next != head)
            {
                temp = temp->next;
            }

            free(temp->next);
            temp->next = head;
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
        if(head->next == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            node* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }

            head = head->next;
            free(temp->next);
            temp->next = head;
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
            addFirstNode();
        }
        else if(pos == count + 1)
        {
            addLastNode();
        }
        else
        {
            node* temp = head;
            while(pos - 2)
            {
                temp = temp->next;
                pos--;
            }

            node* val = temp->next->next;
            free(temp->next);
            temp->next = val;
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
        node* temp = head;
        while(temp->next != head)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("%d  \n", temp->data);
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
        printf("7. Print Linked List :  : \n");

        int ch = 0;
        printf("Enter your choise here : ");
        scanf("%d", &ch);

        int pos = 0;
        switch(ch)
        {
            case 1:
            {
                addLastNode();
            }
            break;

            case 2:
            {
                addFirstNode();
            }
            break;

            case 3:
            {
                printf("Enter position to add the node : ");
                scanf("%d", &pos);
                if(pos > 0)
                {
                    addNodeAtPosition(pos);
                }
                else
                {
                    printf("Enter valid position\n");
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
                    deleteNodeAtPosition(pos);
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
                    printf("Linked List Is Empty\n");
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

    } while (choice == 'y' || choice == 'Y');
}