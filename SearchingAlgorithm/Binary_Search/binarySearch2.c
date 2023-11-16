#include<stdio.h>

int binarySearch(int arr[], int size, int key)
{
	int start = 0;
	int end = size - 1;

	while(start <= end)
	{
		int mid = start + (start + end) / 2;

		if(arr[mid] == key)
		{
			return mid;
		}

		if(arr[mid] < key)
		{
			start = mid = 1;
		}
		if(arr[mid] > key)
		{
			end = mid - 1;
		}
	}

	return -1;
}

void main()
{
	int size = 0;
	int key = 0;

	printf("Enter the size of array : ");
	scanf("%d", &size);

	int arr[size];

	printf("Enter array ele : ");
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("Enter the element to find : ");
	scanf("%d", &key);

	int ret = binarySearch(arr, size, key);

	if(ret == -1) {
		
		printf("%d not found.\n",key);
	
	} else {

		printf("%d found on %d index in array.\n",key,ret);
	}
}
