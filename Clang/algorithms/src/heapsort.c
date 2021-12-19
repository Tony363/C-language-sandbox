#include <stdio.h>
#include "../includes/quicksort.h"

/*
underlying data structure applied on is array
sift down or up is for building tree
    sift up builds "tree" incrementally (if needed to build it iteratively)
    sift down builds tree given array and "heapifies" it
sift down specifically, "heapify" for sorting array representing binary tree
*/

// TODO: implement sift up
void siftUp(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        // swap value of first indexed
        // with last indexed
        swap(&arr[0], &arr[i]);

        // maintaining heap property
        // after each swapping
        int j = 0, index;

        do
        {
            index = (2 * j + 1);

            // if left child is smaller than
            // right child point index variable
            // to right child
            if (arr[index] < arr[index + 1] &&
                index < (i - 1))
                index++;

            // if parent is smaller than child
            // then swapping parent with child
            // having higher value
            if (arr[j] < arr[index] && index < i)
                swap(&arr[j], &arr[index]);

            j = index;

        } while (index < i);
    }
}

// function build Max Heap where value
// of each child is always smaller
// than value of their parent
void buildMaxHeap(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // if child is bigger than parent
        if (arr[i] > arr[(i - 1) / 2])
        {
            int j = i;

            // swap child and parent until
            // parent is smaller
            while (arr[j] > arr[(j - 1) / 2])
            {
                swap(&arr[j], &arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapSortUp(int arr[], int arr_size)
{
    // each time expand processing range of predetermined array, call sift up
    buildMaxHeap(arr, arr_size);
    siftUp(arr, arr_size);
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(&arr[0], &arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
