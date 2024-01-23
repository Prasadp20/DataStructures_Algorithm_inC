#include<stdio.h>

#define ARRAY_SIZE 5
int createArray(int arr[]);
int printArray(int arr[]);
int binarySearch(int arr[], int key);

int main(void)
{
    int key = 0;
    int arr[ARRAY_SIZE];

    createArray(arr);
    printArray(arr);

    printf("Enter the key to find in array : ");
    scanf("%d", &key);
    int ret = binarySearch(arr, key);

    if(ret == -1)
    {
        printf("%d not found in given array\n");
    }
    else
    {
        printf("%d found at %d index\n", key, ret);
    }
    return (0);
}

int createArray(int arr[])
{
    printf("Enter the array elements : ");
    int i = 0;
    while(i < ARRAY_SIZE)
    {
        scanf("%d", &arr[i]);
        ++i;
    }

    return (0);
}

int printArray(int arr[])
{
    printf("Array elements are : ");
    int i = 0;
    while(i < ARRAY_SIZE)
    {
        printf("%d  ", arr[i]);
        ++i;
    }

    printf("\n");
    return (0);
}

int binarySearch(int arr[], int key)
{
    int start = 0;
    int end = ARRAY_SIZE - 1;

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

    return (-1);
}