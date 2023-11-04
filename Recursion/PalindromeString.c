#include<stdio.h>
#include<string.h>

void main()
{
	char carr[100];
	printf("Enter the string : ");
	fgets(carr, sizeof(carr), stdin);
	printf("You Entered : %s\n", carr);

	int len = strlen(carr);

	printf("%d", len);
}
