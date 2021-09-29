#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Frac
{
    int num;
    int den;
} Frac;

int main(int argc, char **argv)
{
    Frac a[10];
    int i;
    double th;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        {
            a[i].num = rand() % 1000;
            a[i].den = rand() % 1000;
            printf("%d/%d ", a[i].num, a[i].den);
        }
    }
    printf("\n\n");
    printf("threshold=");
    fflush(stdout);
    scanf("%lf", &th);
    printf("V >= th\n");
    for (int i = 0; i < 10; i++)
    {
        double v = (double)a[i].num / a[i].den;
        if (v >= th)
        {
            printf("%d/%d ", a[i].num, a[i].den);
        }
    }
    printf("\n");

    printf("V < th\n");
    for (int i = 0; i < 10; i++)
    {
        double v = (double)a[i].num / a[i].den;
        if (v < th)
        {
            printf("%d/%d ", a[i].num, a[i].den);
        }
    }
}