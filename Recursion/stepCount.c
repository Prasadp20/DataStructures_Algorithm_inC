#include<stdio.h>

int stepCount(int num, int count)
{
	if(num == 0){
	
		return count;
	}

	if(num % 2 == 0){
	
		num /= 2;
	} else{
	
		num -= 1;
	}
	
	count++;
	return stepCount(num, count);
}

void main()
{
	int count = 0;
	int number;

	printf("Enter the number : ");
	scanf("%d", &number);

	if(number != 0){
	
		count = stepCount(number, count);
	} else{
	
		count = 0;
	}

	printf("Number of setps are : %d\n", count);
}
