#include<stdio.h>

void selectSort(int arr[], int len)
{
	for(int i = 0; i < len - 1; i++)
	{
		int min_idx = i;

		for(int j = i + 1; j < len - 1; j++)
		{
			if(arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

void main()
{
	int len;
	printf("Enter the array length : ");
	scanf("%d", &len);

	int arr[len];

	printf("Enter Array Ele : ");
	for(int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("\nArray before sorting : ");
	for(int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}

	selectSort(arr, len);

	printf("\nArray after sorting : ");
	for(int i = 0; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
