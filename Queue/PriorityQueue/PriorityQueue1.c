#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{

	int empId;
	char empName[20];
	int priority;
	struct Employee* next;
}Emp;

Emp* front = NULL;
int flag = 0;

Emp* createNode()
{
	Emp* newNode = (Emp *)malloc(sizeof(Emp));

	if(newNode == NULL){
	
		printf("Memory(Heap) Full\n");
		exit(0);
	} 
	printf("Enter employee id : ");
	scanf("%d", &newNode->empId);
	
	getchar();
	printf("Enter employee name : ");
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n')
	{
		(*newNode).empName[i++] = ch;
	}

	printf("Enter pririty of employee : ");
	scanf("%d", &newNode->priority);
	newNode->next = NULL;

	return newNode;
}

void enqueue()
{
	Emp* newNode = createNode();

	if(front == NULL || newNode->priority < front->priority)
	{
		newNode->next = front;
		front = newNode;
	} else{
	
		Emp* temp = front;

		if(temp->next != NULL && temp->next->priority <= newNode->priority)
		{
			temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}
}

int PrintQueue()
{
	if(front == NULL){
	
		return -1;
	}

	Emp* temp = front;
	while(temp != NULL)
	{
		printf("Employee Id : %d\t\tEmployee Name : %s\t\tEmployee priority : %d\n", temp->empId, temp->empName, temp->priority);
		temp = temp->next;
	}

}

int dequeue()
{
	if(front == NULL){
	
		flag = 0;
		return -1;
	} 

	flag = 1;
	Emp* temp = front;
	int data = temp->empId;
	front = front->next;
	free(temp);

	return data;
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

		if(ch >= 1 && ch <= 3)
		{
			switch(ch)
			{
				case 1:
					enqueue();
					break;
				case 2:
					{
						int ret = dequeue();
						if(flag = 1 && ret != -1){
						
							printf("%d Id's employee is dequeue\n",ret);
						} else{
						
							printf("Queue is Underflow\n");
						}
					}
					break;
				case 3:
					{
						int ret = PrintQueue();
						if(ret == -1){
						
							printf("Queue is Underflow\n");
						}
					}
					break;
				default:
					printf("You entered wrong option\n");
					break;
			}
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'y' || choise == 'Y');
}
