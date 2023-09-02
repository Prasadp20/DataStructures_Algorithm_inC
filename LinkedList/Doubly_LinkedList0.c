#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	struct Node* previous;
	int data;
	struct Node* next;
}Node;

Node* head = NULL;

Node* createNode() {
	Node* newNode = (Node *)malloc(sizeof(Node));
	
	newNode->previous = NULL;
	printf("Enter Data : \n");
	scanf("%d", &newNode->data);
	newNode->next = NULL;

	return newNode;
}

int nodeCount()
{
	int count = 0;
	Node* temp = head;

	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

void addNode() {
	Node* newNode = createNode();

	if (head == NULL) {
		head = newNode;
	}
	else {
		Node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->previous = temp;
	}
}

void addNodeAtFirst()
{
	Node* newNode = createNode();

	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
}

int addNodeAtPosition(int pos)
{
	Node* newNode = createNode();
	int count = nodeCount();

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
		else if (pos == count + 1)
		{
			addNode();
		}
		else
		{
			Node* temp = head;

			while (pos - 2) {
				temp = temp->next;
				pos--;
			}
			//newNode->previous = temp->next;
			newNode->next = temp->next;
			//newNode->next = temp;
			newNode->previous = temp;
			temp->next->previous = newNode;
			temp->next = newNode;
		}
		return 0;
	}
}

int deleteFirstNode()
{
	int count = nodeCount();

	if (head == NULL) {
		printf("Nothing to delete\n");
		return -1;
	}
	else {
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

void deleteLastNode()
{
	if (head == NULL) {
		printf("Linked List is Empty.\n");
	}
	else {
		int count = nodeCount();

		if (count == 1) {
			free(head);
			head = NULL;
		}
		else {
			Node* temp = head;

			while (temp->next->next != NULL) {
				temp = temp->next;
			}
			free(temp->next);
			temp->next = NULL;
		}
	}

}

int deleteNodeAtPosition(int pos)
{
	int count = nodeCount();

	if (pos <= 0 || pos > count)
	{
		printf("Invalid Position\n");
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
			Node* temp = head;

			while (pos - 2) {
				temp = temp->next;
			}
			temp->next = temp->next->next;
			free(temp->next->previous);
			temp->next->previous = temp;
		}
	}

}

int printLinkedList()
{
	if (head == NULL)
	{
		printf("Linked list is empty.\n");
		return -1;
	}
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
		{
			printf("| %d | -> ", temp->data);
			temp = temp->next;
		}
		printf("| %d |", temp->data);

		printf("\n");
	}

}

void main()
{
	char choise;
	do {
		printf("Enter the number of your option : \n");

		printf("1. Add Node at First - \n");
		printf("2. Add Node at Last - \n");
		printf("3. Add Node at Specifice Position - \n");
		printf("4. Delete First Node - \n");
		printf("5. Delete Last Node - \n");
		printf("6. Delete Node at Specifice Position - \n");
		printf("7. Print Linked List - \n");
		printf("\n");

		int ch;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch (ch) {
		case 1:
			addNodeAtFirst();
			break;
		case 2:
			addNode();
			break;
		case 3:
		{
			int pos;
			printf("Enter the position : ");
			scanf("%d", &pos);
			if (pos == 0) {
				printf("Please enter the position other than 0 \n");
			}
			else {
				addNodeAtPosition(pos);
			}
		}
			break;
		case 4:
			deleteFirstNode();
			break;
		case 5:
			deleteLastNode();
			break;		
		case 6:
		{
			int pos;
			printf("Enter the position : ");
			scanf("%d", &pos);
			if (pos == 0) {
				printf("Please enter the position other than 0 \n");
			}
			else {
				deleteNodeAtPosition(pos);
			}
		}
			break;
		case 7:
			printLinkedList();
			break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);
	} while (choise == 'Y' || choise == 'y');
}

