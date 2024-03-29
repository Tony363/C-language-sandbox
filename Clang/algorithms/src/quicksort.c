#include <stdio.h>
#include <stdlib.h>
#include "../../data_structure/includes/intqueuea.h"
/* Function to print an array */
void printArray(int *rand_arr, int low, int high)
{
    for (int i = low; i < high; i++)
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

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partitionAlt(int *arr, int low, int high, int *lp)
{
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);

    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g)
    {

        // if elements are less than the left pivot
        if (arr[k] < p)
        {
            swap(&arr[k], &arr[j]);
            j++;
        }

        // if elements are greater than or equal
        // to the right pivot
        else if (arr[k] >= q)
        {
            while (arr[g] > q && k < g)
                g--;
            swap(&arr[k], &arr[g]);
            g--;
            if (arr[k] < p)
            {
                swap(&arr[k], &arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;

    // bring pivots to their appropriate positions.
    swap(&arr[low], &arr[j]);
    swap(&arr[high], &arr[g]);

    // returning the indices of the pivots.
    *lp = j; // because we cannot return two elements
    // from a function.

    return g;
}

void DualPivotQuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partitionAlt(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}

int onePassPartition(int *arr, int low, int high)
{
    if (high - low == 1 && arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
        return low;
    }
    else if (high - low == 1 && arr[low] < arr[high])
    {
        return low;
    }
    int pivot = arr[low], lastSmall = low, p;
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] < pivot)
        {
            swap(&arr[i], &arr[lastSmall + 1]);
            lastSmall = lastSmall + 1;
        }
    }
    swap(&arr[low], &arr[lastSmall]);
    return lastSmall;
}

void callStackQuickSort(int *arr, int low, int high)
{
    if (low > high || low == high)
        return;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = onePassPartition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        callStackQuickSort(arr, low, pi - 1);
        callStackQuickSort(arr, pi + 1, high);
    }
}

// don't know how to use this
/*C++ version, [first, last), last needs --first to fetch the last element*/
/*returns the middle of partitioning result*/
int *partition(int *first, int *last, int pivot)
{
    while (1)
    {
        while (*first < pivot)
            ++first;
        --last; // Don't edit this, it's true.
        while (pivot < *last)
            --last;
        if (!(first < last))
            return first;
        swap(*first, *last);
        ++first;
    }
}

// TODO implement partitioning for kth smallest
int kthSmallest(int *arr, int low, int high, int k)
{
    if (low > high || k > high)
        return -1;
    if (low == high)
        return arr[low];

    int pi = onePassPartition(arr, low, high);
    if (pi == k)
        return arr[pi];
    else if (pi > k)
        return kthSmallest(arr, low, pi - 1, k);
    else
        return kthSmallest(arr, pi + 1, high, k);
}