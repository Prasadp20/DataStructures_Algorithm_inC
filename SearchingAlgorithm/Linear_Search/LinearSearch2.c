#include<stdio.h>
#include<stdbool.h>
#define ARRAY_SIZE 5

int createArray(int arr[]);
int printArray(int arr[]);
bool searchElement(int arr[], int key);

int main(void)
{
    int key = 0;
    char choise;
    int arr[ARRAY_SIZE];

    createArray(arr);
    printArray(arr);

    printf("Enter the element you want to search : ");
    scanf("%d", &key);

    if(searchElement(arr, key))
    {
        printf("%d is present in array\n");
    }
    else
    {
        printf("%d is not present in your array\n");
    }
    return 0;
}

int createArray(int arr[])
{
    printf("Enter the array elements : ");
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    return 0;
}

int printArray(int arr[])
{
    printf("You array is : ");
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

bool searchElement(int arr[], int key)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        if(key == arr[i])
        {
            return true;
        }
    }
    return false;
}