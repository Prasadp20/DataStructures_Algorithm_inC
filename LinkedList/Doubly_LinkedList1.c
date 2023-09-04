#include<stdio.h>
#include<stdlib.h>

typedef struct student {
	struct student* previous;
	int rollNumber;
	float percentage;
	struct student* next;
}stud;

stud* head = NULL;

stud* createNode() {
	stud* newNode = (stud*)malloc(sizeof(stud));

	newNode->previous = NULL;
	printf("Enter Roll Number : ");
	scanf("%d", &newNode->rollNumber);
	printf("Enter Percentage : ");
	scanf("%f", &newNode->percentage);
	newNode->next = NULL;

	return newNode;
}

void addNodeAtLast() {
	stud* newNode = createNode();

	if (head == NULL) {
		head = newNode;
	}
	else {
		stud* temp = head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->previous = temp;
	}
}

void addNodeAtFirst() {
	stud* newNode = createNode();

	if (head == NULL) 
	{
		head = newNode;
	}
	else 
	{
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
}

int nodeCount() {
	int count;
	stud* temp = head;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

int addNodeAtPosition(int pos) {
	int count = nodeCount();
	stud* newNode = createNode();

	if (pos <= 0 || pos >= count + 2) 
	{
		printf("Invalid Position\n");	
		return -1;
	}
	else 
	{
		if (pos == 1) {
			addNodeAtFirst();
		}
		else if (pos == count + 1) {
			addNodeAtLast();
		}
		else {
			stud* temp = head;

			while (pos - 2) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			newNode->previous = temp;
			temp->next = newNode;
			temp->next->previous = newNode;
		}
		return 0;
	}
}

int deleteFirstNode() {
	if (head == NULL) {
		printf("Linked List is Empty, Nothing to Delete\n");

		return -1;
	}
	else {
		int count = nodeCount();

		if (count == 1) {
			free(head);
			head = NULL;
		}
		else {
			head = head->next;
			free(head->previous);
			head->previous = NULL;
		}

		return 0;
	}
}

int deleteLastNode() {

	if (head == NULL) 
	{
		printf("Linked List is Empty, Nothing to Delete\n");
		return -1;
	}
	else
	{
		int count = nodeCount();

		if (count == 1) {
			free(head);
			head = NULL;
		}
		else {
			stud* temp = head;

			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
		}
	}
	return 0;
}

int deleteNodeAtPosition(int pos)
{
	int count = nodeCount();

	if (pos <= 0 || pos > count) {
		printf("Invalid Position.\n");
		return -1;
	}
	else {
		if (pos == 1) {
			deleteFirstNode();
		}
		else if (pos == count) {
			deleteLastNode();
		}
		else {
			stud* temp = head;

			while (pos - 2) {
				temp = temp->next;
			}
			temp->next = temp->next->next;
			free(temp->next->previous);
			temp->next->next = temp;
		}
	}
	return 0;
}
void printDoublyLinkedList()
{
	if (head == NULL) {
		printf("Linked List is Empty\n");
	}
	else {
		stud* temp = head;

		while (temp != NULL) {
			printf("| %d -> %f |", temp->rollNumber, temp->percentage);
			temp = temp->next;
		}
		printf("\n");
	}
}

void main()
{
	addNodeAtLast();
	addNodeAtLast();

	printDoublyLinkedList();
}
