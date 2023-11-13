#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

	struct Node* pre;
	int data;
	struct Node* next;
}node;

node* head = NULL;

node* createNode()
{
	node* newNode = (node*)malloc(sizeof(node*));

	newNode->pre = NULL;

	printf("Enter Data : ");
	scanf("%d", &newNode->data);

	newNode->next = NULL;

	return newNode;
}

void addFirstNode()
{
	node* newNode = createNode();
	if(head == NULL){
	
		head = newNode;
	} else{
	
		newNode->next = head;
		head->pre = newNode;
		head = newNode;
	}
}

void addLastNode()
{
	node* newNode = createNode();
	if(head == NULL){
	
		head = newNode;
	} else{
	
		node* temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->pre = temp;
	}
}

int countNode()
{
	int count = 0;
	if(head == NULL){
	
		return count;
	} else{

		node* temp = head;
		while(temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
}

void addNodeAtPos(int pos)
{
	int count = countNode();
	if(pos <= 0 || pos >= count + 2){
	
		printf("Invalid Position\n");
	} else{
	
		if(pos == 1){
		
			addFirstNode();
		} else if(pos == count + 1){
		
			addLastNode();
		} else{
		
			node* newNode = createNode();
			node* temp = head;
			
			while(pos - 2)
			{
				temp = temp->next;
				pos--;
			}

			newNode->pre = temp;
			newNode->next = temp->next;
			temp->next->pre = newNode;
			temp->next = newNode;
		}
	}
}

void deleteFirstNode()
{
	if(head == NULL){
	
		printf("Linked list is empty\n");
	} else{
		int count = countNode();
	
		if(count == 1){
		
			free(head);
			head = NULL;
		}
		else{
		
			head = head->next;
			free(head->pre);
			head->pre = NULL;
		}
	}
}

void deleteLastNode()
{
	if(head == NULL){
	
		printf("Linked list is empty\n");
	} else{
	
		int count = countNode();
		if(count == 1){
		
			free(head);
			head = NULL;
		} else{
		
			node* temp = head;
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}

			free(temp->next);
			temp->next = NULL;
		}
	}
}

void deleteNodeAtPos(int pos)
{
	int count = countNode();
	if(pos <= 0 || pos > count)
	{
		printf("Invalid position\n");
	} 
	else
	{	
		if(pos == 1)
		{
			deleteFirstNode();
		} 
		else if(pos == count)
		{
			deleteLastNode();
		} 
		else
		{
			node* temp = head;
			while(pos - 2)
			{
				temp = temp->next;
				pos--;
			}

			temp->next = temp->next->next;
			free(temp->next->pre);
			temp->next->pre = temp;
			
			/*
			node* tempNext = temp->next;
			temp->next = tempNext->next;
			tempNext->next->pre = temp;

			free(tempNext);
			*/
		}
	}
}

void printLinkedList()
{
	if(head == NULL){
	
		printf("Linked list is empty\n");
	} else{
	
		node* temp = head;
		while(temp != NULL)
		{
			printf("%d  ",temp->data);
			temp = temp->next;
		}
	}
	printf("\n");
}

void main()
{
	char choise;

	do{
	
		printf("1. Add First Node : \n");
		printf("2. Add Last Node : \n");
		printf("3. Add Node At Position : \n");
		printf("4. Delete First Node : \n");
		printf("5. Delete Last Node : \n");
		printf("6. Delete Node At Position : \n");
		printf("7. Print Linked List : \n");

		int ch = 0;
		printf("Enter your choise here : ");
		scanf("%d", &ch);

		switch(ch){
		
			case 1:
				addFirstNode();
				break;
			case 2:
				addLastNode();
				break;
			case 3:
				{
					int pos = 0;
					printf("Enter the position you want to add node : ");
					scanf("%d", &pos);

					if(pos == 0){
					
						printf("Please enter the valid position : \n");
					}else{
				
						addNodeAtPos(pos);
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
					int pos = 0;
					printf("Enter the position you want to delete node : ");
					scanf("%d", &pos);

					if(pos == 0){
					
						printf("Please enter the valid position\n");
					}else{
					
						deleteNodeAtPos(pos);
					}
				}
				break;
			case 7:
				printLinkedList();
				break;
			default:
				printf("You entered wrong option\n");
				break;
		}

		getchar();
		printf("Do you want to countine : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
