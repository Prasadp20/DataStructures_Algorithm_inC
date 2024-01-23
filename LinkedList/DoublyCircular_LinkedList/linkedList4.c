#include<stdio.h>
#include<stdlib.h>

typedef struct Anime
{
    struct Anime* pre;
    int animeRank;
    char animeName[30];
    int animeRating;
    struct Anime* next;
} anime;

anime* head = NULL;

anime* createNode()
{
    anime* newNode = (anime*)malloc(sizeof(anime*));

    newNode->pre = NULL;

    printf("Enter Animation Rank : ");
    scanf("%d", &newNode->animeRank);

    getchar();
    printf("Enter Animation Name : ");
    char ch;
    int i = 0;
    while((ch = getchar()) != '\n')
    {
        (*newNode).animeName[i++] = ch;
    }

    printf("Enter Animation Rating : ");
    scanf("%d", &newNode->animeRating);

    newNode->next = NULL;

    return newNode;
}

int addLastNode()
{
    anime* newNode = createNode();
    if(head == NULL)
    {
        head = newNode;
        newNode->pre = head;
        newNode->next = head;
    }
    else
    {
        anime* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        
    }
}

void main()
{
    char choice;

    do
    {
        printf("1. Add Node At Last\n");
        printf("2. Add Node At First\n");
        printf("3. Add Node At Position\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Node At Position\n");
        printf("7. Print Linked List\n");

        int ch = 0;
        printf("Enter your choice here : ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
            {
                addLastNode();
            } 
            break;
            
            default:
                printf("Enter the valid option\n");
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choice);

    } while (choice == 'Y' || choice == 'y');   
}