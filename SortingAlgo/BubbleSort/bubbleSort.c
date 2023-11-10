#include<stdio.h>

void bubbleSort(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		for(int j = 0; j < len - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void main()
{
	int len = 0;
	printf("Enter the size of the array : ");
	scanf("%d", &len);

	int arr[len];
	printf("Enter array ele : ");
	for(int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	bubbleSort(arr, len);

	printf("Array after sorting (Using Bubble Sort) : ");
	for(int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
