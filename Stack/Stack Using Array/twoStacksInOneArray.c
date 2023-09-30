#include<stdio.h>
#include<stdbool.h>

int size = 0;
int top1 = 0;
int top2 = 0;
int flag1 = 0;
int flag2 = 0;

int Push1(int stack[])
{
	if(top1 == top2 - 1){
	
		return -1;
	}
	else{
		top1++;
		int data = 0;
		printf("Enter the data : ");
		scanf("%d", &data);
		stack[top1] = data;
		//return data;
		return 0;
	}
}

int Push2(int stack[])
{
	if(top1 == top2 - 1){
	
		return -1;
	}
	else{
		top2--;
		int data = 0;
		printf("Enter the data : ");
		scanf("%d", &data);
		stack[top2] = data;
		//return data;
		return 0;
	}
}

int Pop1(int stack[])
{
	if(top1 == -1){
	
		flag1 = 0;
		return -1;
	}
	else{
	
		int val = stack[top1];
		top1--;
		flag1 = 1;
		return val;
	}
}

int Pop2(int stack[])
{
	if(top2 == size){
	
		flag2 = 0;
		return -1;
	}
	else{
	
		int val = stack[top2];
		top2++;
		flag2 = 1;
		return val;
	}
}

int Peek1(int stack[])
{
	if(top1 == -1){
	
		flag1 = 0;
		return -1;
	}
	else{
	
		int val = stack[top1];
		flag1 = 1;
		return val;
	}
}

int Peek2(int stack[])
{
	if(top2 == size){
	
		flag2 = 0;
		return -1;
	}
	else{
	
		int val = stack[top2];
		flag2 = 1;
		return val;
	}
}

void main()
{
	printf("Enter the size of array : ");
	scanf("%d", &size);

	int stack[size];
	top1 = -1;
	top2 = size;

	char choise;
	do{
	
		printf("1. Push1\n");
		printf("2. Push2\n");
		printf("3. Pop1\n");
		printf("4. Pop2\n");
		printf("5. Peek1\n");
		printf("6. Peek2\n");

		int ch;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch(ch){
		
			case 1: 
				{
					int ret = 0;
					ret = Push1(stack);

					if(ret == -1){
					
						printf("Stack is Full\n");
					}
				}
				break;

			case 2:
				{
					int ret = 0;
					ret = Push2(stack);

					if(ret == -1){
					
						printf("Stack is Full\n");
					}
				}
				break;

			case 3:
				{
					int ret = 0;
					ret = Pop1(stack);

					if(flag1 == 0){
					
						printf("Stack is underflow.\n");
					}
					else{
					
						printf("%d is popped\n",ret);
					}
				}
				break;

			case 4:
				{
					int ret = 0;
					ret = Pop2(stack);

					if(flag2 == 0){
					
						printf("Stack is underflow.\n");
					}
					else{
					
						printf("%d is popped\n",ret);
					}
				}
				break;

			case 5:
				{
					int ret = 0;
					ret = Peek1(stack);

					if(flag1 == 0){
					
						printf("Stack is underflow\n");
					}
					else{
					
						printf("%d\n",ret);
					}
				}
				break;

			case 6:
				{
					int ret = 0;
					ret = Peek2(stack);

					if(flag2 == 0){
					
						printf("Stack is underflow\n");
					}
					else{
					
						printf("%d\n",ret);
					}
				}
				break;

			default:
				printf("Invalid Choise\n");
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
