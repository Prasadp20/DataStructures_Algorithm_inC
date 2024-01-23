#include<stdio.h>

#define ARRAY_SiZE 5

int createArray(int arr[]);
int printArray(int arr[]);
int binarySearch(int arr[], int key);

int main(void)
{
	int key = 0;
	int arr[ARRAY_SiZE];

	createArray(arr);
	printArray(arr);

	printf("Enter the key you want to find in array : ");
	scanf("%d", &key);
	
	int ret = binarySearch(arr, key);

	if(ret == -1)
	{
		printf("Key element %d not found in array\n", key);
	}
	else
	{
		printf("Key element %d found in array at %d location\n", key, ret);
	}

	return 0;
}

int createArray(int arr[])
{
	printf("Enter the array elements : ");
	for(int i = 0; i < ARRAY_SiZE; i++)
	{
		scanf("%d", &arr[i]);
	}
}

int printArray(int arr[])
{
	printf("Array elements are : ");
	for(int i = 0; i < ARRAY_SiZE; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int binarySearch(int arr[], int key)
{
	int start = 0;
	int end = ARRAY_SiZE - 1;

	while(start <= end)
	{
		int mid = start + (end - start) / 2;

		if(arr[mid] == key)
		{
			return mid;
		}
		if(arr[mid] > key)
		{
			end = mid - 1;
		}
		if(arr[mid] < key)
		{
			start = mid + 1;
		}
	}

	return -1;
}