#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

	int data;
	struct Node* next;
}node;

node* front = NULL;
node* rear = NULL;
int flag = 0;

node* createNode()
{
	node* newNode = (node *)malloc(sizeof(node));

	if(newNode == NULL){
	
		printf("Memory (Heap) Full\n");
		exit(0);
	}

	printf("Enter Data : \n");
	scanf("%d", &newNode->data);
	newNode -> next = NULL;

	return newNode;
}

void Enqueue()
{
	node* newNode = createNode();

	if(front == NULL){
	
		front = newNode;
		rear = newNode;
	} else{
	
		rear -> next = newNode;
		rear = newNode;
	}
}

int Dequeue()
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
		
			node* temp = front;
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

int PrintQueue()
{
	if(front == NULL){
	
		return -1;
	} else{
	
		node* temp = front;

		while(temp != NULL)
		{
			printf("%d  ",temp -> data);
			temp = temp -> next;
		}
		printf("\n");
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
		printf("Enter Your Choise Here : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: 
				Enqueue();
				break;
			case 2: 
				{
					int ret = Dequeue();
					if(flag == 1){
					
						printf("%d is dequeue\n",ret);
					} else{
					
						printf("Queue is Underflow\n");
					}

				}
				break;
			case 3: 
				{
					int ret = frontt();
					if(flag == 1){
					
						printf("Front = %d\n",ret);
					} else{
					
						printf("Queue is Underflow\n");
					}
				}
				break;
			case 4: 
				{
					int ret = PrintQueue();
					if(ret == -1){
					
						printf("Queue is Empty\n");
					}
				}
				break;
			default:
				printf("You Enmtered Wrong Choise\n");
				break;
		}

		getchar();
		printf("Do You Want to Continue : \n");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
