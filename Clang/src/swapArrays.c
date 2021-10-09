#include <stdio.h>

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

void printArray(int *a)
{
    int i = 0;
    while (*(a + i) != -1)
    {
        printf("%d ", *(a + i));
        i++;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int a = 0, b = 1;
    int arr[] = {0, 1, 2, -1};
    int brr[] = {3, 4, 5, -1};
    int arrlen = sizeof(arr) / sizeof(arr[0]), brrlen = sizeof(brr) / sizeof(brr[0]);
    swap(&a, &b);
    printf("%d,%d\n", a, b);
    swap_arrays(arr, brr, arrlen, brrlen);
    printArray(arr);
    printArray(brr);
    return 0;
}
