#include<stdio.h>

// sum of n natural number without using variable in recursion 

int sumN(int num, int sum)
{
	if(num == 0){
	
		return sum;
	} else{
	
		return sumN(--num, sum + num);
	}
}

void main()
{
	int num = 0;
	printf("Enter a positive integer.\n");
	scanf("%d", &num);

	if(num < 0){
	
		printf("Please enter the positive integer\n");
	} else{
	
		int ret = sumN(num, 0);

		printf("The sum of the first %d natural numbers is %d\n", num, ret);
	}

}
