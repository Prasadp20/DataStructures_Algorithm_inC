#include<stdio.h>
#include<stdlib.h>

typedef struct Anime
{
    char animeName[50];
    int animeRank;
    struct Anime* next;
} anime;

anime* front = NULL;
anime* rear = NULL;
int flag = 0;

anime* CreateNode()
{
    anime* newNode = (anime*)malloc(sizeof(anime*));
    if(newNode == NULL)
    {
        printf("Memory (Heap) Full\n");
        exit(0);
    }

    getchar();
    printf("Enter Animation Name : ");
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n')
    {
        (*newNode).animeName[i++] = ch;
    }

    printf("Enter Animation Rank : ");
    scanf("%d", &newNode->animeRank);

    newNode->next = NULL;

    return newNode;
}

void Enqueue()
{
    anime* newNode = CreateNode();
    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

anime* Dequeue()
{
    if(front == NULL)
    {
        flag = 0;
        return front;
    }
    else
    {
        flag = 1;
        anime* val = front;

        if(front->next == NULL)
        {
            free(front);
            front = NULL;
            rear = NULL;
        }
        else
        {
            anime* temp = front;
            front = front->next;
            free(temp);
        }

        return val;
    }
}

anime* Frontt()
{
    if(front == NULL)
    {
        flag = 0;
        return front;
    }
    else
    {
        flag = 1;
        return front;
    }
}

int PrintQueue()
{
    if(front == NULL)
    {
        return -1;
    }
    else
    {
        anime* temp = front;

        while(temp != NULL)
        {
            printf("%s -> %d\n", temp->animeName, temp->animeRank);
            temp = temp->next;
        }
        printf("\n");
        return 0;
    }
}

void main()
{
    char choise;

    do
    {
        printf("1. Enqueue : \n");
        printf("2. Dequeue : \n");
        printf("3. Front : \n");
        printf("4. Print Queue : \n");

        int ch = 0;
        printf("Enter your choise here : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                Enqueue();
            }
            break;

            case 2:
            {
                anime* temp = Dequeue();
                if(flag == 0)
                {
                    printf("Queue is underflow\n");
                }
                else
                {
                    while(temp != NULL)
                    {
                        //puts(temp->animeName);
                        //printf("%s  \n", temp->animeName);

                        printf("%s -> %d\n", temp->animeName, temp->animeRank);
                        temp = temp->next;
                    }
                }
            }
            break;

            case 3:
            {
                anime* temp = Frontt();
                if(flag == 0)
                {
                    printf("Queue is Underflow\n");
                }
                else
                {
                    while(temp != NULL)
                    {
                        printf("%s -> %d\n", temp->animeName, temp->animeRank);
                        temp = temp->next;
                    }
                }
            }
            break;

            case 4:
            {
                int ret = PrintQueue();
                if(ret == -1)
                {
                    printf("Queue is Empty\n");
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

    } while (choise == 'y' || choise == 'Y');
}