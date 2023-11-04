#include<stdio.h>

void fun(int x)
{
	printf("Hello\n");

	if(x != 1){
	
		fun(--x);
		printf("Bye\n");
	}
}

void main()
{
	int x = 5;
	fun(x);
}
