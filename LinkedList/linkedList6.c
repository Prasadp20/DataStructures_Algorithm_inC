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

	getchar();

	printf("Enter student name : ");
	//fgets(newNode -> studName, 15, stdin);
	//gets(newNode -> studName);	
	
	int i = 0;
	char ch;

	while((ch = getchar()) != '\n')
	{
		(*newNode).studName[i++] = ch;
	}

	printf("Enter student roll number : ");
	scanf("%d", &newNode -> rollNumber);

	printf("Enter student's last exam marks : ");
	scanf("%f", &newNode -> lastExamMarks);

	newNode -> next = NULL;
	printf("\n");

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
		printf("Roll number - %d\n", temp -> rollNumber);
		printf("Student name - %s\n", temp -> studName);
		printf("Last exam marks - %0.2f\n", temp -> lastExamMarks);

		temp = temp -> next;
	}
	printf("\n");
}
void countOfStudents()
{
	int count = 0;
	stud *temp = head;

	while(temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	printf("Total count of students : %d", count);
	printf("\n");
}
void main()
{
	int choise;
	while(choise != 4)
	{
		printf("Enter 1 for Add new Student Details - \nEnter 2 for Show Students Details - \nEnter 3 to See Total Count of Students - \nEnter 4 If You Want Left -\n");
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
				countOfStudents();
				break;
			case 4:
				choise = 4;
				break;
		}
	}
}
