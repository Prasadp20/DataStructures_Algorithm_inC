#include<stdio.h>

void SelectionSort(int arr[], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        int minIdx = i;

        for(int j = i + 1; j < len - 1; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void main()
{
    int size = 0;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements : ");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    SelectionSort(arr, size);

    printf("Array after sorting : ");
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}