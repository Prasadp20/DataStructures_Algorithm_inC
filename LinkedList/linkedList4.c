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
	newNode -> Id = 101;
	newNode -> percentage = 85.12;
	newNode -> next = NULL;

	head = newNode;

	newNode = (stud *)malloc(sizeof(stud));
	newNode -> Id = 102;
	newNode -> percentage = 87.12;
	newNode -> next = NULL;
	
	head -> next = newNode;
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
	printLinkedList();
}
