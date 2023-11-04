#include<stdio.h>

int nonTailRecursion(int x)
{
	if(x == 1){
	
		return 1;
	}

	return 3 + nonTailRecursion(--x);
}

void main()
{
	int num = 0;

	printf("Enter the number : ");
	scanf("%d", &num);

	int ret = nonTailRecursion(num);
	printf("%d\n", ret);
}
