#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef void (*fp)(void *, void *);

void swapIntData(void *p1, void *p2)
{
    int *n1 = (int *)p1;
    int *n2 = (int *)p2;
    int tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void swapDoubleData(void *p1, void *p2)
{
    double *n1 = (double *)p1;
    double *n2 = (double *)p2;
    double tmp;
    tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void swapDataBlocks(void *a1, void *a2, int elemSize, int elemCount, fp swapFunc)
{
    int i;
    for (i = 0; i < elemCount; i++)
    {
        swapFunc(a1, a2);
        a1 += elemSize; // increment by N bytes because a1,a2 arrays taken as void * for pointer arithmetic
        a2 += elemSize;
        // a1 = (char *)a1 + elemSize;
        // a2 = (char *)a2 + elemSize;
    }
}

// utilizes memcpy to copy data from one array to another
void swapDataBlocksCOPILOT(void *a, void *b, size_t size)
{
    char *temp = (char *)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_arrays(int *y, int *z, int arrlen, int brrlen)
{
    int x, temp;

    for (x = 0; x < arrlen; x++)
    {
        temp = y[x];
        y[x] = z[x];
        z[x] = temp;
    }
}

void printArray(int *a, int arrlen)
{
    int i = 0;
    for (i = 0; i < arrlen; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void printDouble(double *a, int arrlen)
{
    int i = 0;
    for (i = 0; i < arrlen; i++)
    {
        printf("%lf ", a[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a = 0, b = 1;
    int arr[] = {
        0,
        1,
        2,
    };
    int brr[] = {
        3,
        4,
        5,
    };
    int arrlen = sizeof(arr) / sizeof(arr[0]), brrlen = sizeof(brr) / sizeof(brr[0]);
    swap(&a, &b);
    printf("%d,%d\n", a, b);
    swap_arrays(arr, brr, arrlen, brrlen);
    printArray(arr, arrlen);
    printArray(brr, brrlen);

    int ia1[] = {
        1,
        2,
        3,
    };
    int ia2[] = {
        4,
        5,
        6,
    };
    double fa1[] = {
        1.1,
        2.2,
        3.3,
    };
    double fa2[] = {
        4.4,
        5.5,
        6.6,
    };
    swapDataBlocks(ia1, ia2, sizeof(int), 3, swapIntData);
    swapDataBlocks(fa1, fa2, sizeof(double), 3, swapDoubleData);
    printArray(ia1, 3);
    printArray(ia2, 3);
    // printDouble(fa1, 3);
    // printDouble(fa2, 3);
    swapDataBlocksCOPILOT(fa1, fa2, sizeof(double));
    printDouble(fa1, 3);
    printDouble(fa2, 3);
    return 0;
}
