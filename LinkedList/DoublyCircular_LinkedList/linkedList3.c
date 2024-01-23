#include<stdio.h>
#include<stdlib.h>

typedef struct Student{

	struct Student *pre;
	int rollNumber;
	char studName[50];
	struct Student *next;
}stud;

stud* head = NULL;

stud* createNode()
{
	stud* newNode = (stud *)malloc(sizeof(stud));

	newNode -> pre = NULL;

	printf("Enter Roll Number : ");
	scanf("%d", &newNode -> rollNumber);

	getchar();
	printf("Enter Student Name :  ");
	char ch;
	int i = 0;
	while((ch = getchar()) != '\n')
	{
		(*newNode).studName[i++] = ch;
	}

	newNode -> next = NULL;

	return newNode;
}

int countNode()
{
	if(head == NULL){
	
		printf("List is Empty\n");
		return -1;
	}
	else{
		int count = 0;
		stud* temp = head;
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
	stud* newNode = createNode();

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
	}
}

void addNodeAtFirst()
{
	stud* newNode = createNode();

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
			stud* newNode = createNode();
			stud* temp = head;
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
		else if( pos == count + 1){
		
			deleteLastNode();
		}
		else{
		
			stud* temp = head;
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
	if(head == NULL){
	
		printf("List is Empty\n");
	}
	else{
	
		stud* temp = head;
		while(temp -> next != head)
		{
			printf("| %d -> %s|", temp -> rollNumber, temp -> studName);
			//printf("Roll Number of Student : %d\n", temp -> rollNumber);
			//printf("Name of Student : %s\n", temp -> studName);
			temp = temp -> next;
		}

		printf("| %d -> %s|", temp -> rollNumber, temp -> studName);
		//printf("Roll Number of Student : %d\n", temp -> rollNumber);
		//printf("Name of Student : %s\n", temp -> studName);
		//printf("\n");
	}
}

void main()
{
	char choise;

	do{
		
		printf("1. Add Data at Last.\n");
		printf("2. Add Data at First.\n");
		printf("3. Add Data at Required Position.\n");
		printf("4. Delete Last Data.\n");
		printf("5. Delete First Data.\n");
		printf("6. Delete Data at Required Position.\n");
		printf("7. Print Student Data.\n");
		printf("8. Total Count of Student Data.\n");

		int ch = 0;
		printf("Enter your choise here : ");
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
					printf("Enter the position to delete data : ");
					scanf("%d", &pos);
					deleteNodeAtPosition(pos);
				}
				break;
			case 7: 
				printLinkedList();
				break;
			case 8: 
				{
					int count = 0;
					count = countNode();
					if(count != -1){
					
						printf("Total Count of Student Data is : %d\n", count);
					}
				}
				break;
		}

		getchar();
		printf("Do you want to countinue : ");
		scanf("%c", &choise);

	}while(choise == 'Y' || choise == 'y');
}
