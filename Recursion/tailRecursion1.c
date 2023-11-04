#include<stdio.h>

int tailRecursion(int x)
{
	if(x == 1){
	
		return 1;
	}

	return tailRecursion(--x);
}

void main()
{
	int num = 0;
	printf("Enter the number : ");
	scanf("%d", &num);

	int ret = tailRecursion(num);
	printf("%d\n", ret);
}
