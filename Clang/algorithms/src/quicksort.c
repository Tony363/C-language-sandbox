#include <stdio.h>
#include <stdlib.h>
/* Function to print an array */
void printArray(int *rand_arr, int size)
{
    for (int i = 0; i < 10; i++)
        printf("%d ", *(rand_arr + i));
    printf("\n");
}

// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // storing pivot value
    int i = (low - 1);     // indicates the right position of pivot found so far
    printf("starting index %d:%d\n", i, arr[i]);
    printf("pivot %d:%d\n", high, pivot);
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // if swapped, supposed index would be next index
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    printArray(arr, 10);
    printf("ending index: %d\n", (i + 1));
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
        printf("before: %d\n", pi - 1);
        printf("after: %d\n", pi + 1);
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}