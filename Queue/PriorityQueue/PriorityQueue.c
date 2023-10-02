#include<stdio.h>
#include<stdlib.h>

struct Node{

	int data;
	int priority;
	struct Node* next;
};

struct Node* head = NULL;
int flag = 0;

struct Node* createNode()
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
	
		printf("Memory (Heap) is Full\n");
		exit(0);
	}

	printf("Enter Data : ");
	scanf("%d", &newNode->data);
	printf("Enter Priority of Data : ");
	scanf("%d", &newNode->priority);
	newNode->next = NULL;

	return newNode;
}

void Enqueue()
{
	struct Node* newNode = createNode();
	
	if(head == NULL || newNode->priority  < head->priority){
	
		newNode-> next = head;
		head = newNode;
	} else{
	
		struct Node* temp = head;

		if(temp->next != NULL && temp->next->priority <= newNode->priority){
		
			temp = temp->next;
		}
		
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

int Dequeue()
{
	if(head == NULL){
	
		flag = 0;
		return -1;
	}

	flag = 1;
	struct Node* temp = head;
	int data = temp->data;
	head = head->next;
	free(temp);

	return data;
}

int PrintQueue()
{
	if(head == NULL){
	
		return -1;
	}

	struct Node* temp = head;

	while(temp != NULL)
	{
		printf("%d -> %d\n",temp->data, temp->priority);
		temp = temp->next;
	}
}

void main()
{
	char choise;

	do{
	
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Print Queue\n");

		int ch = 0;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				{
					Enqueue();
				}
				break;
			case 2:
				{
					int ret = Dequeue();
					if(flag == 1 && ret != -1){
					
						printf("%d is dequeue\n",ret);
					} else{
					
						printf("Queue is Underflow\n");
					}
				}
				break;
			case 3:
				{
					int ret = PrintQueue();
					if(ret == -1){
					
						printf("Queue is empty\n");
					}
				}
				break;
			default:
				printf("You entered wrong choise\n");
				break;
		}

		getchar();
		printf("Do you want to continue : \n");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
