#include<stdio.h>
#include<stdlib.h>

typedef struct festiveData{

	char festivalName[30];
	char Date[20];
	char Day[20];
	struct festiveData *next;
}festival;

festival* head = NULL;

festival* createNode()
{
	festival* newNode = (festival *)malloc(sizeof(festival));

	getchar();
	printf("Enter Festival Name : ");
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n')
	{
		(*newNode).festivalName[i++] = ch;
	}

	getchar();
	printf("Enter Festival Date : ");
	i = 0;
	while((ch = getchar()) != '\n')
	{
		(*newNode).Date[i++] = ch;
	}

	getchar();
	printf("Enter Festival Day : ");
	i = 0;
	while((ch = getchar()) != '\n')
	{
		(*newNode).Day[i++] = ch;
	}

	newNode -> next = NULL;

	return newNode;
}

void addNode()
{
	festival* newNode = createNode();
	if(head == NULL){
	
		head = newNode;
	}
	else{
	
		festival* temp = head;
		while(temp -> next != NULL)
			temp = temp -> next;

		temp -> next = newNode;
	}
		
}

void printLinkedList()
{
	festival* temp = head;

	while(temp != NULL)
	{
		printf("Festival : %s\n", temp->festivalName);
		printf("Festival Date : %s\n", temp->Date);
		printf("Festival Day : %s\n", temp->Day);
		temp = temp -> next;
	}
}

void main()
{
	char choise;
	do{
		printf("1. Add Festival Data \n");
		printf("2. Show Festival Data : \n");
		printf("\n");
		
		int ch;
		printf("Enter your choise here : \n");
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
		printf("Do you want continue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
