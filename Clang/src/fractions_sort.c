#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct _Frac
{
    int num;
    int den;
} Frac;

int main(int argc, char **argv)
{
    Frac a[10];
    int i, num, den;
    char str[10];
    double th;
    FILE *fout, *fin, *tin;

    fout = fopen("../Texts/out.txt", "w");
    fin = fopen("../Texts/fractions.txt", "r");
    tin = fopen("../Texts/th.txt", "r");
    srand(time(NULL));

    while (fgets(str, 10, fin) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        sscanf(str, "%d/%d", &num, &den);
        a[i].num = num;
        a[i].den = den;
        fprintf(fout, "%d/%d ", a[i].num, a[i].den);
        i++;
    }
    fprintf(fout, "\n\n");
    /*printf("threshold=");fflush(stdout);*/

    fscanf(tin, "%lf", &th);
    fscanf(tin, "%lf", &th);
    fprintf(fout, "V >= %lf\n", th);
    for (int i = 0; i < 10; i++)
    {
        double v = (double)a[i].num / a[i].den;
        if (v >= th)
        {
            fprintf(fout, "%d/%d ", a[i].num, a[i].den);
        }
    }
    fprintf(fout, "\n");

    fprintf(fout, "V < %lf\n", th);
    for (int i = 0; i < 10; i++)
    {
        double v = (double)a[i].num / a[i].den;
        if (v < th)
        {
            fprintf(fout, "%d/%d ", a[i].num, a[i].den);
        }
    }
    fclose(fout);
    fclose(tin);
    return 0;
}