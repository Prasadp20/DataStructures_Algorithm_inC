#include<stdio.h>
#include<stdlib.h>

typedef struct AnimeInfo
{
    int animeRank;
    char animeName[20];
    int rating;
    struct AnimeInfo* next;

} anime;

anime* head = NULL;

anime* createNode()
{
    anime* newNode = (anime*)malloc(sizeof(anime));
    if(newNode == NULL)
    {
        printf("Memory (Heap) Full\n");
        exit(0);
    }

    printf("Enter Rank Of Animation : ");
    scanf("%d", &newNode->animeRank);

    getchar();
    printf("Enter Animation Name : ");
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n')
    {
        (*newNode).animeName[i++] = ch;
    }

    printf("Enter Animation Rating : ");
    scanf("%d", &newNode->rating);

    newNode->next = NULL;

    return newNode;
}

void addLastNode()
{
    anime* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        anime* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void addFirstNode()
{
    anime* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
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
        anime* temp = head;
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
    if(pos <= 0 || pos > count + 1)
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
            anime* newNode = createNode();
            anime* temp = head;
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
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        anime* temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

int deleteFirstNode()
{
    anime* temp = head;
    head = head->next;
    free(temp);
}

int deleteNodeAtPos(int pos)
{
    int count = countNode();

    if(pos <= 0 || pos > count + 1)
    {
        printf("Invalid Position\n");
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
            anime* temp = head;
            while(pos - 2)
            {
                temp = temp->next;

            }
            anime* val = temp->next->next;
            free(temp->next);
            temp->next = val;
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
        anime* temp = head;
        printf("\nAnimeRank   AnimeName   Rating\n");
        while(temp != NULL)
        {
            printf("  %d    ->  %s    ->  %d\n", temp->animeRank, temp->animeName, temp->rating);
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
                printf("Enter the position to add the node : ");
                scanf("%d", &pos);
                if(pos > 0)
                {
                    int ret = addNodeAtPos(pos);
                }
                else
                {
                    printf("Please enter position more than 0\n");
                }
            }
            break;

            case 4:
                deleteLastNode();
            break;

            case 5:
                deleteFirstNode();
            break;

            case 6:
            {
                printf("Enter position to delete the node : ");
                scanf("%d", &pos);
                if(pos > 0)
                {
                    int ret = deleteNodeAtPos(pos);
                }
                else
                {
                    printf("Please enter the valid position to delete the node\n");
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
                printf("Please enter the valid option\n");
            break;
        }

        getchar();
        printf("Do You Want To Continue Please Enter [y/n] Or [Y/N]: ");
        scanf("%c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
}