#include<stdio.h>

void main()
{
    int size = 0;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the array elements : ");
    for(int i =0; i < size - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting : ");
    for(int i = 0; i < size - 1; i++)
    {
        
    }
}