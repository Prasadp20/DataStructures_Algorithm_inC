#include<stdio.h>

void selectSort(int arr[], int len)
{
    for(int i = 0; i < size - 1; i++)
    {
        int minIdx = i;

        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
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
