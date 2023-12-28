#include<stdio.h>

void BubbleSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
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
	int size = 0;

	printf("Enter the size of array : ");
	scanf("%d", &size);

	int arr[size];
	printf("Enter the array elements : \n");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Array before sorting : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	BubbleSort(arr, size);

	printf("Array after sorting : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
