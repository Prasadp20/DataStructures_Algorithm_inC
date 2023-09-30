#include<stdio.h>
#include<stdlib.h>

typedef struct Demo{

	int data;
	struct Demo* next;
}demo;

demo* front = NULL;
demo* rear = NULL;
int flag = 0;

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

void enqueue()
{
	demo* newNode = createNode();

	if(front == NULL){
	
		front = newNode;
		rear = newNode;
	} else{
	
		rear -> next = newNode;
		rear = newNode;
	}	
}

int dequeue()
{
	if(front == NULL){
	
		flag = 0;
		return -1;
	} else{
	
		flag = 1;
		int val = front -> data;

		if(front -> next == NULL){
		
			free(front);
			front = NULL;
			rear = NULL;
		} else{
		
			demo* temp = front;
			front = front -> next;
			free(temp);
		}

		return val;
	}
}

int frontt()
{
	if(front == NULL){
	
		flag = 0;
		return -1;
	} else{
	
		flag = 1;
		return front -> data;
	}
}

int printQueue()
{
	if(front == NULL){
	
		return -1;
	} else{
	
		demo* temp = front;
		while(temp != NULL)
		{
			printf("%d ",temp -> data);
			temp = temp -> next;
		}
		printf("\n");
		return 0;
	}
}

void main()
{
	char choise;

	do{
	
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Front\n");
		printf("4. Print Queue\n");

		int ch = 0;
		printf("Enter Your Choise : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				{
					int ret = dequeue();
					if(flag == 1){
					
						printf("%d is Dequeue\n",ret);
					} else{
					
						printf("Queue is Underflow\n");
					}
				}
				break;
			case 3:
				{
					int ret = frontt();
					if(flag == 1){
					
						printf("Front = %d",ret);
					} else{
					
						printf("Queue is Underflow\n");
					}
				}
				break;
			case 4:
				{
					int ret = printQueue();
					if(ret == -1){
					
						printf("Queue id Empty\n");
					}
				}
				break;
			default:
				printf("You Entered Wrong Choise\n");
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
