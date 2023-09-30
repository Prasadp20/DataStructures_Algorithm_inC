#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int size = 0;
int top = -1;
int flag = 0;

bool isFull()
{
	if(top == size - 1)
		return true;
	else
		return false;
}

int Push(int stack[])
{
	if(isFull()){
	
		return -1;
	}
	else{
	
		top++;
		printf("Enter data : ");
		scanf("%d", &stack[top]);
		return 0;
	}
}

bool isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}

int Pop(int stack[])
{
	if(isEmpty()){
	
		flag = 0;
		return -1;
	}
	else{
	
		int val = stack[top];
		top--;
		flag = 1;
		return val;
	}
}

int Peek(int stack[])
{
	if(isEmpty()){
	
		flag = 0;
		return -1;
	} else{
	
		flag = 1;
		int val = stack[top];
		return val;
	}
}

void main()
{
	printf("Enter size of stack\n");
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
		
		if(ch >= 1 && ch <= 3)
		{	
			switch(ch){
			
				case 1:
					{
						int ret = Push(stack);
						if(ret == -1){
						
							printf("Stack is Overflow\n");
						}
					}
					break;
				case 2:
					{
						int ret;
						ret = Pop(stack);
						if(flag == 0){
						
							printf("Stack is Underflow\n");
						}
						else{
						
							printf("%d is popped\n",ret);
						}
					}
					break;
				case 3:
					{
						int ret = Peek(stack);
						if(flag == 0){
						
							printf("Stack is Empty\n");
						} else{
						
							printf("%d \n",ret);
						}
					}
					break;

			}
		}
		else{
		
			printf("You enter Wrong Choise\n");
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
