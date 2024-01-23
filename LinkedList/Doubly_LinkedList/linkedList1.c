#include<stdio.h>
#include<stdlib.h>

typedef struct movieInfo
{
    struct movieInfo* pre;
    char movieName[20];
    int movieRating;
    struct movieInfo* next;
} movie;

movie* head = NULL;

movie* createNode()
{
    printf("Start createNode()\n");

    movie* newNode = (movie*)malloc(sizeof(movie*));
    if(newNode == NULL)
    {
        printf("Memory (Heap) FULL\n");
        exit(0);
    }

    newNode->pre = NULL;

    getchar();
    printf("Enter Movie Name : ");
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n')
    {
        (*newNode).movieName[i++] = ch;
    }

    printf("Enter Movie Rating : ");
    scanf("%d", &newNode->movieRating);

    newNode->next = NULL;

    printf("End createNode()\n");

    return newNode;
}

void addLastNode()
{
    movie* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        movie* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->pre = temp;
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
        movie* temp = head;
        while(temp != NULL)
        {
            printf("%s -> %d", temp->movieName, temp->movieRating);
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
        printf("Enter your choice here : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                addLastNode();
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

            default : 
                printf("Enter valid option\n");
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');
}