//Stack Using Array - 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int size = 0;
int top = -1;
int flag = 0;

bool isFull()
{
	if(top == size - 1){

		return true;
	}
	else{
	
		return false;
	}
}

int push(int stack[])
{
	if(isFull()){
		
		return -1;	
	}
	else{
	
		top++;
		printf("Enter data : \n");
		scanf("%d", &stack[top]);
		return 0;
	}
}


bool isEmpty()
{
	if(top == -1){

		return true;
	}
	else{
		
		return false;
	}
}

int pop(int stack[])
{
	if(isEmpty()){
	
		return -1;
		flag = 0;
	}
	else{
	
		int val = stack[top];
		top--;
		flag = 1;
		return val;
	}
}

int peek(int stack[])
{
	if(isEmpty()){
	
		return -1;
		flag = 0;
	}
	else{
	
		int val = stack[top];
		flag = 1;
		return val;
	}
}

void main()
{
	char choise;

	printf("Enter the size of stack ");
	scanf("%d", &size);

	int stack[size];

	do{
	
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. isEmpty\n");
		printf("5. isFull\n");

		int ch;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch(ch){
		
			case 1: 
				{
					int ret = 0;
					ret = push(stack);
					if(ret == -1)
					{
						printf("Stack Overflow\n");
					}
				}
				break;
			case 2: 
				{
					int ret = 0;
					ret = pop(stack);

					if(flag == 0){
						
						printf("Stack Underflow\n");
					}
					else{
					
						printf("%d is popped\n", ret);
					}
				}
				break;
			case 3: 
				{
					int ret = 0;
					ret = peek(stack);
					if(flag == 0){
					
						printf("Stack is empty\n");
					}
					else{
					
						printf("%d\n", ret);
					}
				}
				break;
			case 4: 
				{
					bool ret = isEmpty();
					if(ret){
					
						printf("Stack is empty\n");
					}
					else{
					
						printf("Stack is not empty\n");
					}
				}
				break;
			case 5:
				{
				
					bool ret = isFull();
					if(ret){
					
						printf("Stack is full\n");
					}
					else{
					
						printf("Stack is not full\n");
					}
				}
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
