#include <stdio.h>

void swapArr(int *arr1, int *arr2, int len1, int len2)
{
    int n;
    if (len1 == len2)
        n = len1;
    else
        n = (len1 > len2) ? len2 : len1;
    if (!arr1 || !arr2)
        return;
    for (int i = 0; i < n; i++)
    {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

void printArr(int *arr, int len)
{
    if (!arr)
        return;
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    printArr(arr1, len1);
    printArr(arr2, len2);
    swapArr(arr1, arr2, len1, len2);
    printArr(arr1, len1);
    printArr(arr2, len2);
    return 0;
}