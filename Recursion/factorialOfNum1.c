#include<stdio.h>

//Factorial code using best approch

int factorial(int num)
{
	if(num == 1){
	
		return 1;
	}

	return factorial(num - 1) * num;
}

void main()
{
	int num = 0;
	printf("Enter the number : ");
	scanf("%d", &num);

	int ret = factorial(num);
	printf("Factorial of %d is : %d\n", num, ret);
}
