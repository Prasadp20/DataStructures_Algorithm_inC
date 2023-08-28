#include<stdio.h>
#include<stdlib.h>

typedef struct Student{

	int Id;
	float Height;
	struct Student *next;
}stud;

void main()
{
	// Create head pointer
	stud *head = NULL;

	//Create first node
	stud *newNode = (stud *)malloc(sizeof(stud));
	newNode -> Id = 1;
	newNode -> Height = 5.5;
	newNode -> next = NULL;

	// Create connection of first node with head
	head = newNode;

	// Create seconf node
	newNode = (stud *)malloc(sizeof(stud));
	newNode -> Id = 2;
	newNode -> Height = 6.5;
	newNode -> next = NULL;

	// Create connection of first node with second node
	head -> next = newNode;

	// Create third node
	newNode = (stud *)malloc(sizeof(stud));
	newNode -> Id = 3;
	newNode -> Height = 7;
	newNode -> next = NULL;

	// Create connection second node with third node
	head -> next -> next = newNode;

	// Create temporary pointer for move on linked list
	stud *temp = head;

	// printf Nodes function
	while(temp != NULL)
	{
		printf("Student Id = %d\n", temp -> Id);
		printf("Student height = %f\n", temp -> Height);
		
		printf("\n");
		
		temp = temp -> next;

	}
	printf("\n");

}
