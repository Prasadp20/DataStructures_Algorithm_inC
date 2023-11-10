#include<stdio.h>

int isPresent(int arr[], int len, int key)
{
	for(int i = 0; i < len; i++)
	{
		if(arr[i] == key){
		
			return 1;
		}
	}

	return -1;
}

void main()
{
	int len = 0;
	printf("Enter the length of array : ");
	scanf("%d", &len);

	int arr[len];

	printf("Enter the array elements : ");
	for(int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	int key = 0;
	printf("Enter the number to search in array : ");
	scanf("%d", &key);

	int ret = isPresent(arr, len, key);

	if(ret == 1){
	
		printf("Element is present\n");
	} else{
	
		printf("Element is not present\n");
	}
}
