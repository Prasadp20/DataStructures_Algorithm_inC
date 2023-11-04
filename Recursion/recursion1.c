#include<stdio.h>

int sumOfArray(int arr[], int size)
{
	if(size == 0){
	
		return arr[size];
	}

	return sumOfArray(arr, size - 1) + arr[size];
}

void main()
{
	int size;
	printf("Enter Size of Array : ");
	scanf("%d", &size);

	int arr[size];

	printf("Enter Array Elements : \n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}

	int sum = sumOfArray(arr, size);
	printf("Sum of all array elements : %d\n", sum);
}
