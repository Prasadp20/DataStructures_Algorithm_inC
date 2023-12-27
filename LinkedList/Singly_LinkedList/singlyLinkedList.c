#include<stdio.h>
#include<stdlib.h>

typedef struct Demo 
{
	int data;
	struct Demo* next;
}demo;

demo* head = NULL;

demo* createNode()
{
	demo* newNode = (demo*)malloc(sizeof(demo*));
	printf("Enter Data : ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;

	return newNode;
}

void addLastNode()
{
	demo* newNode = createNode();
	if (head == NULL) 
	{
		head = newNode;
	}
	else 
	{
		demo* temp = head;
		while (temp -> next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void addFirstNode()
{
	demo* newNode = createNode();

	if (head = NULL)
	{
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

int nodeCount()
{
	int count = 0;
	demo* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void addNodeAtPos(int pos)
{
	int count = nodeCount();
	if (pos <= 0 || pos > count + 1)
	{
		printf("Invalid Position\n");
	}
	else
	{
		if (pos == 1)
		{
			addFirstNode();
		}
		else if (pos == count + 1)
		{
			addLastNode();
		}
		else
		{
			demo* newNode = createNode();
			demo* temp = head;
			while (pos - 2)
			{
				temp = temp->next;
				pos--;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}

void printLinkedList()
{

	demo* temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

void main()
{
	char choise;
	do {

		printf("1. Add Node at Last : \n");
		printf("2. Add Node at First : \n");
		printf("3. Add node at Position : \n");
		printf("4. Delete Last Node\n");
		printf("5. Delete First Node : \n");
		printf("6. Delete Node at Position : \n");
		printf("7. Print Nodes : \n");

		int ch = 0;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch (ch) {

		case 1:
			addLastNode();
			break;
		case 2:
			addFirstNode();
			break;
		case 3:
		{
			int pos;
			printf("Enter Position : ");
			scanf("%d", &pos);

			if (pos == 0) {

				printf("Please Enter the more than 0\n");
			}
			else {

				addNodeAtPos(pos);
			}
		}
		break;
/*		case 4:
			deleteFirstNode();
			break;
		case 5:
			deleteLastNode();
			break;
		case 6:
		{
			int pos;
			printf("Enter Position : ");
			scanf("%d", &pos);

			if (pos == 0) {

				printf("Please Enter the more than 0\n");
			}
			else {

				deleteNodeAtPos(pos);
			}
		}
		break;*/
		case 7:
			printLinkedList();
			break;
		default:
			printf("Please enter valid option\n");
			break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	} while (choise == 'Y' || choise == 'y');
}