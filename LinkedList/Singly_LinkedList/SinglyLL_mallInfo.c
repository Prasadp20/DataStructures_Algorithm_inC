#include<stdio.h>
#include<stdlib.h>

typedef struct mallInfo{

	char mallName[20];
	int noOfShops;
	float totalRevenue;
	struct mallInfo *next;
}mall;

mall* head = NULL;

mall* createNode()
{
	mall *newNode = (mall *)malloc(sizeof(mall));

	getchar();
	printf("Enter Mall Name : ");
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n')
	{
		newNode->mallName[i++] = ch;
	}

	printf("Enter Number of Shops in Mall : ");
	scanf("%d", &newNode->noOfShops);

	printf("Enter Total Revenue of Mall : ");
	scanf("%f", &newNode->totalRevenue);

	newNode->next = NULL;

	return newNode;
}
void addNode()
{
	mall* newNode = createNode();

	if(head == NULL){
	
		head = newNode;
	}
	else{
	
		mall* temp = head;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int printLinkedList()
{
	if(head == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	else{
		mall* temp = head;

		while(temp != NULL)
		{
			printf("Name of Mall : %s\n", temp->mallName);
			printf("Number of shops in %s : %d\n", temp->mallName, temp->noOfShops);
			printf("Total Revenue of %s : %0.3f\n", temp->mallName, temp->totalRevenue);
			temp = temp->next;
		}
		printf("\n");
		return 0;
	}
}

void main()
{
	char choise;
	do{
	
		printf("1. Add Mall Info - \n");
		printf("2. Show Mall Data - \n");

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
		}

		getchar();
		printf("Do you want to add more : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
	
	//addNode();
	//printLinkedList();
}
