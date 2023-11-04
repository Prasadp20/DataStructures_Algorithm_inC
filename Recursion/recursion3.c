#include<stdio.h>

// Code to check how many stack frame pushed into stack

void fun()
{
	static int x = 0;	// Used static storage class here
	printf("%d\n", x++);
	fun();
}

void main()
{
	fun();
}
