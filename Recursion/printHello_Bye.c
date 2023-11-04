#include<stdio.h>

//print Hello and Bye in recursion code

int x = 5;
void fun()
{
	printf("Hello\n");

	if(x != 1){
		
		fun(--x);
	}

	printf("Bye\n");
}

void main()
{
	fun();
}
