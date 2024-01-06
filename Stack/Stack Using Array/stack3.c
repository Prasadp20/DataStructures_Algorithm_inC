#include<stdio.h>
#include<stdbool.h>

int top = -1;
int flag = 0;
int size = 0;

bool isFull()
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

int push(int stack[])
{
	if(isFull())
	{
		return -1;
	}
	else
	{
		top++;
		printf("Enter the data : ");
		scanf("%d", &stack[top]);
		return 0;			
	}
}

bool isEmpty()
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

int pop(int stack[])
{
	if(isEmpty())
	{
		flag = 0;
		return -1;
	}
	else
	{
		int val = stack[top];
		top--;
		flag = 1;
		return val;
	}
}

int peek(int stack[])
{
	if(isEmpty())
	{
		flag = 0;
		return -1;
	}
	else
	{
		int val = stack[top];
		flag = 1; 
		return val;
	}
}


void main()
{
	printf("Enter the size of the stack : ");
	scanf("%d", &size);

	int stack[size];

	char choise;

	do{
	
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");

		int ch = 0;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				{
					int ret = push(stack);
					if(ret == -1)
					{
						printf("Stack is overflow\n");
					}
					//else
					//{
					//	printf("Element Pushed\n");
					//}
				}
				break;
			case 2:
				{
					int ret = pop(stack);
					if(flag == 0 && ret == -1)
					{
						printf("Stack is underflow\n");
					}
					else
					{
						printf("%d is popped\n",ret);
					}
				}
				break;
			case 3:
				{
					int ret = peek(stack);
					if(flag == 0)
					{
						printf("Stack is underflow\n");
					}
					else
					{
						printf("%d is peeked\n", ret);
					}
				}
				break;
			default:
				{
				
					printf("Please enter the valid option\n");
				}
				break;
		}

		getchar();
		printf("Do you want to continue : \n");
		scanf("%c", &choise);

	} while(choise == 'Y' || choise == 'y');

}
