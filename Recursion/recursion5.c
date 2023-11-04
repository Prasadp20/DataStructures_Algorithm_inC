#include<stdio.h>

//Sum of N natural number using recursion 
int sumN(int num)
{
	static int sum = 0;
	if(num == 0){
	
		return sum;
	}

	sum = sum + num;
	return sumN(--num);
}

void main()
{
	int number = 0;

	printf("Enter the number : ");
	scanf("%d", &number);
	int ret = sumN(number);

	printf("Sum of %d natural numbers : %d\n", number, ret);
}
