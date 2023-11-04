#include<stdio.h>

// Factorial code using moderate approch
int factorial(int num)
{
	static int fact = 1;

	if(num == 1){
	
		return fact;
	}

	fact = fact * num;
	factorial(--num);
}

void main()
{
	int num = 0;
	printf("Enter the number : ");
	scanf("%d", &num);

	int ret = factorial(num);
	printf("Factorial of %d is : %d\n", num, ret);
}
