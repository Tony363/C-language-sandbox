#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/hashmap.h"

typedef struct _Frac
{
    double frac_val;
    char *frac;
} Frac;

int iterate_unsafe(Frac *array)
{
    int i = 0;
    while ((array + i)->frac != NULL)
        i++;
    return i;
}

double readFraction(const char *str)
{
    double a = 0, b = 0;
    sscanf(str, "%d/%d", &a, &b);
    return a / b;
}

Frac *readFractionFile(FILE *in)
{
    if (in == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    char str[30];
    double val = 0;
    int count = 0;
    Frac *fractions = (Frac *)malloc(30 * sizeof(Frac));
    while (fgets(str, 30, in) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        Frac new_frac;
        new_frac.frac = (char *)malloc(sizeof(char) * 30);
        strcpy(new_frac.frac, str);
        new_frac.frac_val = readFraction(str);

        *(fractions + count) = new_frac;
        count++;
    }
    Frac new_frac = {.frac_val = 0, .frac = NULL}; // set fraction array null equivalent terminator
    *(fractions + count) = new_frac;
    return fractions;
}

void writeFile(FILE *out, Frac *arr)
{
    for (int i = 0; (arr + i)->frac != NULL; i++)
    {
        printf("fraction: %s\nvalue: %lf\n", (arr + i)->frac, (arr + i)->frac_val);
        fprintf(out, "%s\n", (arr + i)->frac);
    }
}

// the compare function for double values
static int compare(const void *a, const void *b)
{
    if (((Frac *)a)->frac_val > ((Frac *)b)->frac_val)
        return 1;
    else if (((Frac *)a)->frac_val < ((Frac *)b)->frac_val)
        return -1;
    else
        return 0;
}

int main(void)
{
    FILE *in = fopen("../Texts/fraction.txt", "r");
    FILE *out = fopen("../Texts/fractionConverted.txt", "w");
    Frac *arr = readFractionFile(in);
    int arr_len = iterate_unsafe(arr);

    qsort(arr, arr_len, sizeof(Frac), compare);
    writeFile(out, arr);
    fclose(in);
    return 0;
}