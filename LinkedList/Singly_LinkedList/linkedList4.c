#include<stdio.h>
#include<stdlib.h>

typedef struct student{

	int Id;
	float percentage;
	struct student *next;
}stud;

struct student *head;
void addNode()
{
	stud *newNode = (stud *)malloc(sizeof(stud));
	
	printf("Enter your Id = ");
	scanf("%d", &newNode -> Id);
	printf("Enter your percentage = ");
	scanf("%f",&newNode -> percentage);
	newNode -> next = NULL;
	/*
	newNode -> Id = 101;
	newNode -> percentage = 85.12;
	newNode -> next = NULL;
	*/
	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		stud *temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}

void printLinkedList()
{
	stud *temp = head;
	
	while(temp != NULL)
	{
		printf("Student Id = %d\n", temp -> Id);
		printf("Student percentage = % 0.2f\n", temp -> percentage);
		temp = temp -> next;
	}
}
void main()
{
	addNode();
	addNode();
	addNode();
	addNode();
	printLinkedList();
}
