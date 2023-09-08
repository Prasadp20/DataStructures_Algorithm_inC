#include<stdio.h>
#include<stdlib.h>

typedef struct studentDetails{

	int rollNumber;
	char studName[50];
	float lastExamMarks;
	struct studentDetails *next;
}stud;

stud *head = NULL;

void addNewStudent()
{
	stud *newNode = (stud *)malloc(sizeof(stud));

	printf("Enter student name : ");
	fgets(newNode -> studName, 15, stdin);	

	getchar();
	
	printf("Enter student roll number : ");
	scanf("%d", &newNode -> rollNumber);

	printf("Enter student's last exam marks : ");
	scanf("%f", &newNode -> lastExamMarks);

	newNode -> next = NULL;

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

void printStudentDetails()
{
	stud *temp = head;

	while(temp != NULL)
	{
		printf("%d\n", temp -> rollNumber);
		printf("%s\n", temp -> studName);
		printf("%f\n", temp -> lastExamMarks);

		temp = temp -> next;
	}
	printf("\n");
}
void main()
{
	int choise;
	while(choise != 3)
	{
		printf("Enter 1 for Add new Student Details - \nEnter 2 for Show Students Details - \nEnter 3 for Exit - \n");
		scanf("%d", &choise);

		switch(choise)
		{
			case 1:
				addNewStudent();
				break;
			case 2:
				printStudentDetails();
				break;
			case 3:
				choise = 3;
				break;
		}
	}
}
