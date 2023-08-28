#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Employee{

	int empId;
	char empName[20];
	float salary;
	struct Employee *next;
}Emp;

void accessData(Emp *ptr){

	printf("Employee Id = %d\n", ptr -> empId);
	printf("Employee Name = %s\n", ptr -> empName);
	printf("Employee Salary = %f\n", ptr -> salary);
	printf("Next employee address = %p\n", ptr -> next);
	printf("\n");
}

void main()
{
	Emp *emp1 = (Emp *)malloc(sizeof(Emp));
	Emp *emp2 = (Emp *)malloc(sizeof(Emp));
	Emp *emp3 = (Emp *)malloc(sizeof(Emp));

	(*emp1).empId = 1;
	strcpy((*emp1).empName, "suraj");
	(*emp1).salary = 50.00;
	(*emp1).next = emp2;

	(*emp2).empId = 2;
	strcpy((*emp2).empName, "Abhi");
	(*emp2).salary = 60.00;
	(*emp2).next = emp3;
	
	emp3 -> empId = 3;
	strcpy(emp3 -> empName, "Prasad");
	emp3 -> salary = 70.00;
	emp3 -> next = NULL;
	
	accessData(emp1);
	accessData(emp2);
	accessData(emp3);
}
