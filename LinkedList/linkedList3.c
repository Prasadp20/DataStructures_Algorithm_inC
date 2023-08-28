#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{

	int empId;
	float salary;
	struct Employee *next;
}Emp;

Emp* addNode(Emp *head)
{
	Emp *newNode = (struct Employee *)malloc(sizeof(Emp));
	newNode -> empId = 101;
	newNode -> salary = 50.50;
	newNode -> next = NULL;

	head = newNode;
	return head;
}

void printLinkedList(Emp *head)
{
	Emp *temp = head;
	while(temp != NULL)
	{
		printf("Employee Id = %d\n", temp -> empId);
		printf("Employee Salary = %f\n", temp -> salary);
		temp = temp -> next;
	}
}
void main()
{
	Emp *head = NULL;
	head = addNode(head);
	printLinkedList(head);
}
