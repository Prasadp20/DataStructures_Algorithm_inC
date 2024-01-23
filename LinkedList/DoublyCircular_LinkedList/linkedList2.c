#include<stdio.h>
#include<stdlib.h>

typedef struct Demo{

	struct Demo *pre;
	int data;
	struct Demo *next;
}demo;

demo* head = NULL;

demo* createNode()
{
	demo *newNode = (demo *)malloc(sizeof(demo));

	newNode -> pre = NULL;
	
	printf("Enter Data : ");
	scanf("%d", &newNode -> data);
	
	newNode -> next = NULL;
	return newNode;
}

int countNode()
{
	if(head == NULL){
	
		printf("List is Empty\n");
	}
	else{
		int count = 0;
		demo* temp = head;
		while(temp -> next != head)
		{
			count++;
			temp = temp -> next;
		}

		return count + 1;
	}
}

void addNodeAtLast()
{
	demo* newNode = createNode();

	if(head == NULL){
	
		head = newNode;
		newNode -> next = head;
		newNode -> pre = head;
	}
	else{
	
		newNode -> pre = head -> pre;
		newNode -> next = head;
		head -> pre -> next = newNode;
		head -> pre = newNode;
	}
}

void addNodeAtFirst()
{
	demo* newNode = createNode();

	if(head == NULL){
	
		head = newNode;
		newNode -> next = head;
		newNode -> pre = head;
	}
	else{
	
		newNode -> next = head;
		newNode -> pre = head -> pre;
		head -> pre -> next = newNode;
		head -> pre = newNode;
		head = newNode;
	}
}

int addNodeAtPosition(int pos)
{
	int count = countNode();

	if(pos <= 0 || pos > count + 1){
	
		printf("Invalid Position\n");
		return -1;
	}
	else{
	
		if(pos == 1){
		
			addNodeAtFirst();
		}
		else if(pos == count + 1){
		
			addNodeAtLast();
		}
		else{
		
			demo* newNode = createNode();
			demo* temp = head;

			while(pos - 2)
			{
				temp = temp -> next;
				pos--;
			}

			newNode -> next = temp -> next;
			newNode -> pre = temp;
			temp -> next -> pre = newNode;
			temp -> next = newNode;
		}

		return 0;
	}
}

int deleteLastNode()
{
	if(head == NULL){
	
		printf("List is Empty\n");
		return -1;
	}
	else{
	
		if(head -> next == head){
		
			free(head);
			head = NULL;
		}
		else{
		
			head -> pre = head -> pre -> pre;
			free(head -> pre -> next);
			head -> pre -> next = head;
		}

		return 0;
	}
}

int deleteFirstNode()
{
	if(head == NULL){
	
		printf("List is Empty\n");
		return -1;
	}
	else{
	
		if(head -> next == head){
		
			free(head);
			head = NULL;
		}
		else{
		
			head = head -> next;
			head -> pre = head -> pre -> pre;
			free(head -> pre -> next);
			head -> pre -> next = head;

		}
		
		return 0;
	}
}

int deleteAtPosition(int pos)
{
	int count = countNode();

	if(pos <= 0 || pos > count + 1){
	
		printf("Invalid Position\n");
		return -1;
	}
	else{
	
		if(pos == 1){
		
			deleteFirstNode();
		}
		else if(pos == count + 1){
		
			deleteLastNode();
		}
		else{
		
			demo* temp = head;

			while(pos - 2)
			{
				temp = temp -> next;
				pos--;
			}

			temp -> next = temp -> next -> next;
			free(temp -> next -> pre);
			temp -> next -> pre = temp;
		}
	}
}

void printLinkedList()
{
	if(head == NULL){
	
		printf("List is Empty\n");
	}
	else{
	
		demo* temp = head;

		while(temp -> next != head)
		{
			printf("| %d |->", temp -> data);
			temp = temp -> next;
		}
		printf("| %d |\n", temp -> data);
	}
}

void main()
{
	char choise;

	do{
	
		printf("1. Add data at last. \n");
		printf("2. Add data at first.\n");
		printf("3. Add data at position.\n");
		printf("4. Delete last data.\n");
		printf("5. Delete first data.\n");
		printf("6. Delete data at position.\n");
		printf("7. Print data.\n");
		printf("8. Take count of all data.\n");

		int ch = 0;
		printf("Enter your choise here - ");
		scanf("%d", &ch);

		switch(ch){
		
			case 1: 
				addNodeAtLast();
				break;
			case 2: 
				addNodeAtFirst();
				break;
			case 3: 
				{
					int pos = 0;
					printf("Enter the position to add data : ");
					scanf("%d", &pos);
					addNodeAtPosition(pos);
				}
				break;
			case 4: 
				deleteLastNode();
				break;
			case 5: 
				deleteFirstNode();
				break;
			case 6: 
				{
					int pos = 0;
					printf("Enter the position to add data : ");
					scanf("%d", &pos);
					deleteAtPosition(pos);
				}
				break;
			case 7: 
				printLinkedList();
				break;
			case 8: 
				int count = countNode();
				printf("Total count of data : %d\n", count);
				break;
			default:
				printf("Invalid choise\n");
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
