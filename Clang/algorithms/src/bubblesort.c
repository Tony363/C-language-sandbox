#include <stdio.h>
#include <stdlib.h>
#include "../includes/quicksort.h"
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                // printf("swapped: %d::%d\n", arr[j], arr[j + 1]);
            }
            // printArray(arr, 0, n);
        }
}