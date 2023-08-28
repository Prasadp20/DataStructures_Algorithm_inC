#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Employee{

	int empId;
	char empName[20];
	float salary;
	struct Employee *next;
}emp;

void main()
{
	emp obj1, obj2, obj3;

	obj1.empId = 1;
	strcpy(obj1.empName,"Sanket");
	obj1.salary = 50.00;
	obj1.next = &obj2;

	obj2.empId = 2;
	strcpy(obj2.empName,"Vivek");
	obj2.salary = 60.00;
	obj2.next = &obj3;

	obj3.empId = 3;
	strcpy(obj3.empName,"Prasad");
	obj3.salary = 70.00;
	obj3.next = NULL;

	struct Employee *head = &obj1;

	printf("Employee Id = %d\n", (*head).empId);
	printf("Employee Name = %s\n", (*head).empName);
	printf("Employee Salary = %f\n", (*head).salary);

	printf("\nEmployee Id = %d\n", head -> next -> empId);
	printf("Employee Name = %s\n", head -> next -> empName);
	printf("Employee Salary = %f\n", head -> next -> salary);
	
	printf("\nEmployee Id = %d\n", head -> next -> next -> empId);
	printf("Employee Name = %s\n", head -> next -> next -> empName);
	printf("Employee Salary = %f\n", head -> next -> next -> salary);
	
}




















