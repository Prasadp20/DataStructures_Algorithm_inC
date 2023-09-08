#include<stdio.h>
#include<stdlib.h>

typedef struct Employee{

	int empId;
	char empName[20];
	char Designation[20];
	float Salary;
	struct Employee *next;
}emp;

emp *head = NULL;

emp* createNode()
{
	emp *newNode = (emp *)malloc(sizeof(emp));

	printf("\nEnter Employee Id : ");
	scanf("%d", &newNode -> empId);

	getchar();
	printf("Enter Employee Name : ");
	char ch1;
	int i = 0;
	while((ch1 = getchar()) != '\n')
	{
		(*newNode).empName[i++] = ch1;
	}

	printf("Enter Employee Designation : ");
	char ch2;
	int j = 0;
	while((ch2 = getchar()) != '\n')
	{
		(*newNode).Designation[j++] = ch2;
	}

	printf("Enter employee Salary : ");
	scanf("%f", &newNode -> Salary);

	newNode -> next = NULL;
	return newNode;
}

void addNode()
{
	emp *newNode = createNode();

	if(head == NULL){
	
		head = newNode;
	}else{
	
		emp *temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp ->  next = newNode;
	}
}

void printLinkedList()
{
	emp *temp = head;
	while(temp != NULL)
	{
		printf("\nEmployee Id : %d\n", temp -> empId);
		printf("Employee Name : %s\n", temp -> empName);
		printf("Employee Designation : %s\n", temp -> Designation);
		printf("Employee Salary : %0.3f\n", temp -> Salary);
		printf("\n");	
		temp = temp -> next;
	}
}

void addNodeAtFirst()
{
	emp *newNode = createNode();

	if(head == NULL){
	
		head = newNode;
	}else{
	
		newNode -> next = head;
		head = newNode;
	}
}

void addNodeAtLast()
{
	addNode();
}

int nodeCount()
{
	int count = 0;
	emp *temp = head;
	while(temp != NULL)
	{
		temp = temp -> next;
		count++;
	}

	return count;
}
void addNodeAtPos(int pos)
{
	int Count = nodeCount();

	if(pos <= 0 || pos >= Count + 2){
	
		printf("\nPlease enter valid position to add node.\n");
	}
	else if(pos == Count + 1){
	
		addNodeAtLast();
	}
	else if(pos == 1){
	
		addNodeAtFirst();
	}
	else{
		emp *newNode = createNode();
		emp *temp = head;

		while(pos - 2)
		{
			temp = temp -> next;
		}
		newNode -> next = temp -> next;
		temp -> next = newNode;
	}
}

void deleteFirstNode()
{
	emp *temp = head;
	head = head -> next;
	free(temp);
}

void deleteLastNode()
{
	
}

void main()
{
	char choise;
	do{
		printf("\n1. Add New Node at First - \n");
		printf("2. Add New Node at Last - \n");
		printf("3. Add New Node at Specifice Position - \n");
		printf("4. Delete First Node - \n");
		printf("5. Delete Last Node - \n");
		printf("6. Print All Nodes - \n");
		printf("7. Show Count of All Nodes - \n");
		printf("\n");
		
		int ch;
		printf("\nEnter your option here - ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				addNodeAtFirst();
				break;
			case 2:
				addNodeAtLast();
				break;
			case 3:
				{
					int pos;
					printf("\nEnter the Node Position - ");
					scanf("%d", &pos);
					addNodeAtPos(pos);
				}
				break;
			case 4:
				deleteFirstNode();
				break;
			case 5:
				deleteLastNode();
				break;
			case 6:
				printLinkedList();
				break;
			case 7:
				int Count = nodeCount();
				printf("\nCount of all node are - %d\n",Count);
				break;
		}

	getchar();	
	printf("\nDo you want to choise another option : ");
	scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
