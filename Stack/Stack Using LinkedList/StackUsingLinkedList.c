#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Demo{

	int data;
	struct Demo* next;
}demo;

demo* head = NULL;
int userCount = 0;
int flag = 0;

int countNode()
{
	if(head == NULL){
	
		return -1;
	} else{
	
		demo* temp = head;
		int count = 0;

		while(temp -> next != NULL)
		{
			count++;
			temp = temp -> next;
		}

		return count;
	}
}

bool isFull()
{
	if(countNode() == userCount){
	
		return true;
	} else{
	
		return false;
	}
}

demo* createNode()
{
	demo* newNode = (demo *)malloc(sizeof(demo));

	if(newNode == NULL){
	
		printf("Memory (Heap) Full\n");
		exit(0);
	}

	printf("Enter Data : \n");
	scanf("%d", &newNode -> data);
	newNode -> next = NULL;

	return newNode;
}

void addNode()
{
	demo* newNode = createNode();
	if(head == NULL){
	
		head = newNode;
	} else{
	
		demo* temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}

		temp -> next = newNode;
	}
}

int Push()
{
	if(isFull()){
	
		return -1;
	} else{
	
		addNode();
		return 0;
	}
}

bool isEmpty()
{
	if(countNode() == 0){
	
		return true;
	} else{
	
		return false;
	}
}

int deleteNode()
{
	demo* temp = head;
	while(temp -> next -> next != NULL)
	{
		temp = temp -> next;
	}

	int val = temp -> data;
	free(temp -> next);
	temp -> next = NULL;
	return val;

}

int Pop()
{
	if(isEmpty()){
	
		flag = 0;
		return -1;
	} else{
	
		flag = 1;
		int val = deleteNode();
		return val;
	}
}

int Peek()
{
	if(isEmpty()){
	
		flag = 0;
		return -1;
	} else{
	
		flag = 1;
		demo* temp = head;

		while(temp -> next != NULL)
		{
			temp = temp -> next;	
		}

		int val = temp -> data;
		return val;
	}
}

void main()
{
	char choise;
	userCount = 0;
	printf("Enter the number of Stack : ");
	scanf("%d", &userCount);

	do{
	
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		
		int ch = 0;
		printf("Enter Your Choise : ");
		scanf("%d", &ch);

		if(ch >= 1 && ch <= 3)
		{
			switch(ch)
			{
				case 1:
					{
						int ret = Push();
						if(ret == -1){
						
							printf("Stack is Overflow\n");
						}
					}
					break;
				case 2:
					{
						int ret = Pop();
						if(flag == 1){
						
							printf("%d is Popped\n",ret);
						} else{
						
							printf("Stack is Underflow\n");
						}
					}
					break;
				case 3:
					{
						int ret = Peek();
						if(flag == 1){
						
							printf("%d \n",ret);
						} else{
						
							printf("Stack is Underflow\n");
						}
					}
					break;
				default:
					printf("You entered wrong choise\n");
					break;
			}
		} else{
		
			printf("Your entered wrong choise\n");
		}

		getchar();
		printf("Do you want continue : \n");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
