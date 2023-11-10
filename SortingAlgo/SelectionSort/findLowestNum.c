#include<stdio.h>

void main()
{
	int len;
	printf("Enter the length of array : ");
	scanf("%d", &len);

	int arr[len];

	printf("Enter array ele : ");
	for(int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Array : ");
	for(int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}

	printf("\nMinimum element in array : ");

	int min = arr[0];
	for(int j = 0; j < len - 1; j++)
	{
		if(min > arr[j + 1])
		{
			min = arr[j + 1];
		}
	}
	printf("%d\n",min);
}
