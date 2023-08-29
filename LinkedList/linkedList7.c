#include<stdio.h>
#include<stdlib.h>

// Linked List Functions Code -

typedef struct Employee{

	int empId;
	char empName[20];
	float Salary;
	struct Employee *next;
}Emp;

Emp *head = NULL;

Emp* createNode()
{
	Emp *newNode = (Emp *)malloc(sizeof(Emp));

	printf("Enter the Id - ");
	scanf("%d", &newNode->empId);

	getchar();

	printf("Enter the name - ");
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')
	{
		(*newNode).empName[i] = ch;
		i++;
	}
	
	printf("Enter the salary - ");
	scanf("%f", &newNode -> Salary);

	newNode -> next = NULL;

	return newNode;

}

void addNode()
{
	Emp *newNode = createNode();
	Emp *temp = head;
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}
void printfLinkedList()
{
	Emp *temp = head;
	while(temp != NULL)
	{
		printf("Employee Id : %d\n", temp -> empId);
		printf("Employee name : %s\n", temp -> empName);
		printf("Salary : %0.4f\n", temp -> Salary);
		printf("\n");	
		temp = temp -> next;
	}
}

void CountOfEmp()
{
	Emp *temp = head;
	int count = 0;
	while(temp != NULL)
	{
		temp = temp -> next;
		count++;
	}

	printf("Count of Employee : %d\n", count);

}

void addFirstNode()
{
	Emp *newNode = createNode();

	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode -> next = head;
		head = newNode;
	}
}

void addNodeAtPosition(int position)
{
	Emp *newNode = createNode();
	Emp *temp = head;

	while(position - 2)
	{
		temp = temp -> next;
		position--;
	}
	newNode -> next = temp -> next;
	temp -> next = newNode;
}
void main()
{
	int userChoise;
	printf("How many number of nodes you want to add : ");
	scanf("%d", &userChoise);
	
	for(int i = 0; i < userChoise; i++)
	{
		addNode();
	}
	
	addFirstNode();

	int pos;
	printf("Enter the position to add node : ");
	scanf("%d", &pos);
	
	addNodeAtPosition(pos);

	printfLinkedList();
	
	CountOfEmp();
}
