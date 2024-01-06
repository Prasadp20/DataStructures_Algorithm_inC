#include<stdio.h>
#include<stdbool.h>

int size = 0;
int flag = 0;
int top = -1;

bool IsFull()
{
    if(top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Push(int arr[])
{
    if(IsFull())
    {
        return -1;
    }
    else
    {
        top++;
        printf("Enter Data : ");
        scanf("%d", &arr[top]);

        return 0;
    }
}

bool IsEmpty()
{
    if(top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Pop(int arr[])
{
    if(IsEmpty())
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        int val = arr[top];
        top--;

        return val;
    }
}

int Peek(int arr[])
{
    if(IsEmpty())
    {
        flag = 0;
        return -1;
    }
    else
    {
        flag = 1;
        return arr[top];
    }
}

void main()
{
    printf("Enter size of array : ");
    scanf("%d", &size);

    int arr[size];
    char choise;
    do
    {
        printf("1. Push : \n");
        printf("2. Pop : \n");
        printf("3. Peek : \n");

        int ch = 0;
        printf("Enter your choise here : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                int ret = Push(arr);
                if(ret == -1) 
                {
                    printf("Stack is overflow\n");
                }
            }
            break;

            case 2:
            {
                int ret = Pop(arr);
                if(flag == 0)
                {
                    printf("Stack is underflow\n")''
                }
                else
                {
                    printf("%d is popped\n", ret);
                }
            }
            break;

            case 3:
            {
                int ret = Peek(arr);
                if(flag == 0)
                {
                    printf("Stack is underflow\n")''
                }
                else
                {
                    printf("%d \n", ret);
                }
            }
            break;

            default:
            {
                printf("Enter the valid option\n");
            }
            break;
        }

        getchar();
        printf("Do you want to continue : ");
        scanf("%c", &choise);

    } while (choise == 'y' || choise == 'Y');
    
}