#include<stdio.h>

int sumNumber(int num)
{
	if(num == 1){
	
		return 1;
	}

	return sumNumber(num - 1) + num;
}
void main()
{
	int num = 0;
	printf("Enter the number : ");
	scanf("%d", &num);

	int ret = sumNumber(num);
	printf("sum of %d number : %d\n", num, ret);
}
