#include<stdio.h>

int size = 0;
#define size 1;
int arr[size];

int front = -1;
int rear = -1;
int flag = 0;

int Enqueue()
{
    if(rear == size - 1)
    {
        return -1;
    }
    else
    {
        if(front == -1)
        {
            front++;
        }
        rear++;

        printf("Enter the Data : ");
        scanf("%d", &arr[rear]);
        
        return 0;
    }
}

void main()
{
    char choise;

    printf("Enter the size of array : ");
    scanf("%d", &size);

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
                int ret = Enqueue();
                if(ret == -1)
                {
                    printf("Queue is overflow\n");
                }
            }
            break;
        }

        getchar();
        printf("Do you want to countinue : ");
        scanf("%c", &choise);

    } while(choise == 'Y' || choise == 'y');
}