#include<stdio.h>
#include<stdbool.h>

int size = 0;
int flag = 0;
int top = -1;

bool isFull()
{
	if(size - 1 == top){
	
		return true;
	}
	else{
	
		return false;
	}
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
	if(top == -1){
	
		return true;
	}
	else{
	
		return false;
	}
}

int Pop(int stack[])
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

int Peek(int stack[])
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
	printf("Enter size of stack : ");
	scanf("%d", &size);

	int stack[size];

	char choise;
	do{
	
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. IsEmpty\n");
		printf("5. IsFull\n");

		int ch = 0;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch(ch){
		
			case 1:
				{
					int ret = 0;
					ret = Push(stack);
					if(ret == -1)
					{
						printf("Stack is Overflow\n");
					}
				}
				break;
			case 2:
				{
					int ret = 0;
					ret = Pop(stack);
					if(flag == 1){
					
						printf("%d is popped\n",ret);
					}
					else{
					
						printf("Stack is or underflow empty\n");
					}
				}
				break;
			case 3:
				{
					int ret = 0;
					ret = Peek(stack);
					if(flag == 1){
					
						printf("%d\n",ret);
					}
					else{
					
						printf("Stack is empty\n");
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
			default:
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c",&choise);

	}while(choise == 'y' || choise == 'Y');
}
