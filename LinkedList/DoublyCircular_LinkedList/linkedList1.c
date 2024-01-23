#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

	struct Node *pre;
	int data;
	struct Node *next;
}node;

node* head = NULL;

node* createNode()
{
	node* newNode = (node *)malloc(sizeof(node));

	newNode -> pre = NULL;
	printf("Enter Data : ");
	scanf("%d", &newNode -> data);
	newNode -> next = NULL;
	
	return newNode;
}

int countNode()
{
	if(head == NULL){
	
		printf("Linked List is Empty\n");
	}
	else{
		int count = 0;
		node* temp = head;
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
	node* newNode = createNode();

	if(head == NULL){
	
		head = newNode;
		newNode -> next = head;
		newNode -> pre = head;
	}
	else{
	
		head -> pre -> next = newNode;
		newNode -> pre = head -> pre;
		newNode -> next = head;		
		//newNode -> pre = head -> pre;		
		head -> pre = newNode;
	}

}

void addNodeAtFirst()
{
	node* newNode = createNode();

	if(head == NULL){
	
		head = newNode;
		newNode -> pre = head;
		newNode -> next = head;
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
		
			node* newNode = createNode();
			node* temp = head;
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

int deleteFirstNode()
{
	if(head == NULL){
	
		printf("Linked List is Empty\n");
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
	}
}

int deleteLastNode()
{
	if(head == NULL){
	
		printf("Linked List is Empty\n");
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

int deleteNodeAtPosition(int pos)
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
		
			node* temp = head;
			while(pos - 2)
			{
				temp = temp -> next;
				pos--;
			}

			temp -> next = temp -> next -> next;
			free(temp -> next -> pre);
			temp -> next -> pre = temp;
		}
		return 0;
	}
}

void printLinkedList()
{
	node* temp = head;
	while(temp -> next != head)
	{
		printf("| %d | -> ", temp -> data);
		temp = temp -> next;
	}
	printf("| %d |\n", temp -> data);

}
void main()
{
	char choise;

	do{
	
		printf("1. Add Data at Last.\n");
		printf("2. Add Data at First.\n");
		printf("3. Add Data at Position.\n");
		printf("4. Delete First Node.\n");
		printf("5. Delete Last Node.\n");
		printf("6. Delete Node at Position.\n");
		printf("7. Print Data\n");

		int ch;
		printf("Enter your choise here - \n");
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
					int pos;
					printf("Enter the position you want to add data in list : \n");
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

					int pos;
					printf("Enter the position you want to delete data in list : \n");
					scanf("%d", &pos);
					deleteNodeAtPosition(pos);
				}
				break;
			case 7:
				printLinkedList();
				break;
			default:
				printf("You Entered Invalid Choise\n");
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
