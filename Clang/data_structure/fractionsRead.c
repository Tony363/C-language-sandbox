#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/hashmap.h"

int iterate_unsafe(double *array);

double readFraction(const char *str)
{
    double a = 0, b = 0;
    sscanf(str, "%d/%d", &a, &b);
    return a / b;
}

char *readFractionFile(FILE *in)
{
    if (in == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char str[30];
    double val = 0;
    char *strings[] = (double *)malloc(100 * sizeof(double));
    int count = 0;
    while (fgets(str, 30, in) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        val = readFraction(str);
        insert(str, val);
        *(strings + count) = str;
        count++;
    }
    return strings;
}

void writeFile(FILE *out, double *arr)
{
    for (int i = 0; *(arr + i) != 0; i++)
    {
        printf("%lf\n", *(arr + i));
        fprintf(out, "%lf\n", *(arr + i));
    }
}

int iterate_unsafe(double *array)
{
    int i;
    for (i = 0; *(array + i) != 0; i++)
        printf("%lf", *(array + i));
    return i;
}

// the compare function for double values
static int compare(const void *a, const void *b)
{
    if (*(double *)a > *(double *)b)
        return 1;
    else if (*(double *)a < *(double *)b)
        return -1;
    else
        return 0;
}

int main(void)
{
    dummyItem = (struct DataItem *)malloc(sizeof(struct DataItem));
    dummyItem->data = 0;
    strcpy(dummyItem->key, "");

    FILE *in = fopen("../Texts/fraction.txt", "r");
    FILE *out = fopen("../Texts/fractionConverted.txt", "w");
    double *arr = readFractionFile(in);
    int arr_len = iterate_unsafe(arr);

    qsort(arr, arr_len, sizeof(double), compare);
    writeFile(out, arr);
    fclose(in);
    return 0;
}