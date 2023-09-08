#include<stdio.h>
#include<stdlib.h>

typedef struct stateData{

	char stateName[30];
	int population;
	int Budget;
	float literacy;
	struct stateData *next;

}state;

state *head = NULL;

state* createNode()
{
	state* newNode = (state *)malloc(sizeof(state));

	getchar();
	printf("Enter state name : ");
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n')
	{
		(*newNode).stateName[i++] = ch; 
	}
	
	printf("Enter population of state : ");
	scanf("%d", &newNode -> population);

	getchar();
	printf("Enter budget of state : ");
	scanf(" %d", &newNode -> Budget);
	
	getchar();
	printf("Enter state literacy : ");
	scanf(" %f", &newNode -> literacy);

	newNode -> next = NULL;

	return newNode;
}

void addNode()
{
	state* newNode = createNode();
	if(head == NULL){
	
		head = newNode;
	}
	else{
	
		state* temp = head;

		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}

void printLinkedList()
{
	if(head == NULL){
	
		printf("List is empty");
	}
	else{
	
		state* temp = head; 
		while(temp != NULL)
		{
			printf("Name of State : %s\n", temp -> stateName);
			printf("Population of %s : %d\n", temp -> stateName, temp -> population);
			printf("%s's Budget : %d\n", temp -> stateName, temp -> Budget);
			printf("Literacy Rate of %s : %0.2f\n", temp -> stateName, temp -> literacy);
			temp = temp -> next;
		}
		//printf("\n");
	}
}

void main()
{
	char choise;
	do{
		printf("1. Add State Details\n");
		printf("2. Print State Data\n");

		int ch;
		printf("Enter your choise - ");
		scanf("%d", &ch);

		switch(ch){
		
			case 1:
				addNode();
				break;
			case 2:
				printLinkedList();
				break;
			default:
				printf("Invalid Choise\n");
				break;
		}

		getchar();
		printf("Do you want to continue : ");
		scanf("%c", &choise);		
	
	}while(choise == 'Y' || choise == 'y');	
}
