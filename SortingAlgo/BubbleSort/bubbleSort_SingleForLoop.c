#include<stdio.h>

void BubbleSort(int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}

		if (i == len - 1)
		{
			i = 0;
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