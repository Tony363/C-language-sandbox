#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *arr)
{
    printf("%d\n", sizeof(arr) / sizeof(arr[0]) - 1);
}

int main(int argc, char **argv)
{
    int array[] = {1, 2, 3};
    print(array);
    return 0;
}