#include<stdio.h>

int factorial(int num)
{
	if(num == 1){
	
		return 1;
	}

	return factorial(num - 1) * num;
}

void main()
{
	int number = 0;
	printf("Enter the number : ");
	scanf("%d", &number);

	int ret = factorial(number);
	printf("Factorial of %d is : %d\n", number, ret);
}
