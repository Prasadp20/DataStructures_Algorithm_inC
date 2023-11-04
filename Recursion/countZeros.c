#include<stdio.h>

int countZeros(int num, int count)
{
	if(num == 0){
	
		return count;
	} 
	
	if(num % 10 == 0){
	
		count++;
	}
	return countZeros(num / 10, count);
}
void main()
{
	int number;
	int count = 0;

	printf("Enter the number : ");
	scanf("%d", &number);

	if(number != 0){
	
		count = countZeros(number, count);
	} else{
	
		count = 1;
	}

	printf("Number of zero's : %d\n", count);
}
