#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{

	int data;
	struct Node *next;
};

void main()
{
	struct Node *head = NULL;

	//Create first node
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> data = 10;
	newNode -> next = NULL;

	head = newNode;	//Connecting first node to head pointer
	
	//Create second node
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> data = 20;
	newNode -> next = NULL;

	head -> next = newNode; // Connecting second node to first node
	
	//Create third node
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> data = 30;
	newNode -> next = NULL;

	head -> next -> next = newNode; // Connecting third node to second node
	
	struct Node *temp = head;
	while(temp != NULL)
	{
		printf("Data = %d  ", temp -> data);
		temp = temp -> next;
	}
}
