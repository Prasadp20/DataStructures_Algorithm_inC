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
	
	newNode->pre = NULL;
	printf("Enter data : ");
	scanf("%d", &newNode->data);
	newNode->next = NULL;

	return newNode;
}
void addNode()
{
	node* newNode = createNode();

	if(head == NULL){
	
		head = newNode;
	}
	else{
	
		node* temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->pre = temp;
	}
}

int nodeCount()
{
	int count = 0;
	node* temp = head;
	while(temp != NULL)
	{
		count++;
		temp = temp -> next;
	}
	return count;
}

int reverLinkedList()
{
	if(head == NULL){

		printf("Linked List is Empty\n");

		return -1;
	}
	else{
		int count = nodeCount();
		if(count == 1){
		
			printf("Only One Node Present in Linked List\n");
			
			return -1;
		}
		else
		{
		
			node* temp1 = head;
			node* temp2 = head;
			int cnt = count/2;

			while(temp2->next != NULL)
			{
				temp2 = temp2 -> next;
			}

			while(cnt)
			{
				int temp = temp2 -> data;
				temp2 -> data = temp1 -> data;
				temp1 -> data = temp;
				
				cnt--;
				temp2 = temp2->pre;
				temp1 = temp1->next;
			}

			return 0;

		}
	}
}

void printLinkedList()
{
	node* temp = head;

	while(temp != NULL)
	{
		printf("| %d |", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}
void main()
{
	int userChoise;
	printf("How many number of data you want to print : ");
	scanf("%d", &userChoise);

	for(int i = 0; i < userChoise; i++)
		addNode();
	
	printLinkedList();
	
	reverLinkedList();
	
	printLinkedList();
	
}
