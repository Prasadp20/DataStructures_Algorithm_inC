#include<stdio.h>
#include<stdbool.h>

bool isSorted(int arr[], int len)
{
	if(len <= 1){
	
		return true;
	}

	if(arr[len - 1] < arr[len - 2]){
	
		return false;
	}

	return isSorted(arr, len - 1);
}

void main()
{
	int len = 0;
	printf("Enter length of array : ");
	scanf("%d", &len);

	int arr[len];

	printf("Enter the array elements : ");
	for(int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}

	if(isSorted(arr, len)){

		printf("The Array is Sorted\n");
	} else{
	
		printf("The Array is Not Sorted\n");
	}
}
