#include<stdio.h>

// Tail Recursion Example
void fun(int num)
{
	printf("%d", num);
	fun(--num);
}

void main()
{
	fun(5);
}
