#include<stdio.h>

int size = 0;
int front = -1;
int rear = -1;
int flag = 0;

int Enqueue(int arr[])
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
        printf("Enter Data : ");
        scanf("%d", &arr[rear]);

        return 0;
    }
}

int Dequeue(int arr[])
{
    if(front == -1 || front > rear)
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        int val = arr[front];
        
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }

        return val;
    }
}

int Frontt(int arr[])
{
    if(front == -1)
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        return arr[front];
    }
}

int PrintQueue(int arr[])
{
    if(front == -1)
    {
        return -1;
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d  ", arr[i]);
        }
        printf("\n");
    }
}

void main()
{
    char choise;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    int arr[size];

    do{
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
                int ret = Enqueue(arr);
                if(ret == -1) 
                {
                    printf("Queue is Overflow.\n");
                }
            }
            break;

            case 2:
            {
                int ret = Dequeue(arr);
                if(flag == 1) 
                {
                    printf("%d is dequeue.\n", ret);
                } 
                else 
                {
                    printf("Queue is Underflow.\n");
                }
            }
            break;

            case 3:
            {
                int ret = Frontt(arr);
                if(flag == 1) 
                {
                    printf("%d ", ret);         
                }
                else 
                {
                    printf("Queue is underflow\n");
                }
            }
            break;

            case 4:
            {
                int ret = PrintQueue(arr);
                if(ret == -1)
                {
                    printf("Queue is Empty\n");
                }
            }
            break;

            default:
                printf("Enter the valid option.\n");
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choise);

    }while(choise == 'y' || choise == 'Y');
}