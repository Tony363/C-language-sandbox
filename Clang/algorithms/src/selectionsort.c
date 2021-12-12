#include <stdio.h>
#include <stdlib.h>
#include "../includes/quicksort.h"

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Find the minimum element in unsorted array
int findMin(int arr[], int r)
{
    int min_idx = 0;
    for (int i = 1; i <= r; i++)
        if (arr[i] < arr[min_idx])
            min_idx = i;
    return min_idx;
}

void selectionSortRec(int arr[], int n)
{
    if (n <= 1)
        return;

    int i;
    int min_idx = findMin(arr, n - 1);

    // Swap the found minimum element with the first element
    swap(&arr[min_idx], &arr[0]);

    // Recursively sort the remaining array
    selectionSortRec(arr + 1, n - 1);
}