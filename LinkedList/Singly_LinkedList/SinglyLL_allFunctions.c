#include<stdio.h>
#include<stdlib.h>
typedef struct student{

	int rollNumber;
	char Name[20];
	float lastExamMarks;
	struct student *next;
}stud;
stud *head = NULL;

stud* createNode()
{
	stud *newNode = (stud *)malloc(sizeof(stud));

	printf("Enter roll number : ");
	scanf("%d", &newNode->rollNumber);
	getchar();
	printf("Enter student name : ");
	//gets(newNode -> Name);
	int i = 0;
	char ch;
	while((ch = getchar()) != '\n')
	{
		(*newNode).Name[i++] = ch;
	}

	printf("Enter last exam marks : ");
	scanf("%f", &newNode -> lastExamMarks);

	newNode -> next = NULL;
	return newNode;
}

void addNode()
{
	stud *newNode = createNode();

	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		stud *temp = head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}

void addFirstNode()
{
	stud *newNode = createNode();

	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		newNode -> next = head;
		head = newNode;
	}
}

int CountOfNode()
{
	stud *temp = head;
	int count = 0;

	while(temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	printf("Count of total nodes are : %d\n", count);
	return count;
}

void addNodeAtPos(int pos)
{
	stud *newNode = createNode();

	if(head = NULL)
	{
		head = newNode;
	}
	else
	{
		stud *temp = head;
		while(pos - 2)
		{
			temp = temp -> next;
			pos--;
		}
		newNode -> next = temp -> next;
		temp -> next = newNode;
	}
}
void deleteNode()
{
	stud *temp = head;
	head = head -> next;
	free(temp);
}

void printLinkedList()
{
	stud *temp = head;
	while(temp != NULL)
	{
		printf("\n");
		printf("Roll number of student : %d\n", temp -> rollNumber);
		printf("Name of student : %s\n", temp -> Name);
		printf("Last exam marks : %f\n", temp -> lastExamMarks);
		temp = temp -> next;
	}
}
void main()
{
	char choise;
	do{
		printf("1. Add Node - \n");	
		printf("2. Add Node at First - \n");	
		printf("3. Add Node at Specifice Position - \n");	
		printf("4. Print All Present Nodes - \n");
		printf("5. Delete First Node - \n");	
		printf("6. Delete Last Node - \n");	
		printf("7. See Count of All Present Node - \n");	
		printf("\n");
		int ch;
		printf("Enter Choise - ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				addNode();
				break;
			case 2:
				addFirstNode();
				break;
			case 3:
				{
					int count = CountOfNode();
					if(count >= 1)
					{
						int pos;
						printf("Enter the position to add your node\n");
						scanf("%d",&pos);
						addNodeAtPos(pos);
					}
					else
					{
						printf("No Node Present\n");
					}
				}
				break;
			case 4:
				printLinkedList();
				break;
			case 5:
				deleteNode();
				break;
			case 6:
				break;
			case 7:
				printLinkedList();
				break;
			default:
				printf("You entered wrong choise\n");
				break;
		}
		getchar();	
		printf("Do you want to choise another option : ");
		scanf("%c", &choise);
	}while(choise == 'Y' || choise == 'y');
}
