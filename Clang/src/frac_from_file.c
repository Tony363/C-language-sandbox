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
    FILE *fout, *fin;

    fout = fopen("../Texts/out.txt", "w");
    fin = fopen("../Texts/th.txt", "r");
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {

        a[i].num = rand() % 1000;
        a[i].den = rand() % 1000;
        fprintf(fout, "%d/%d ", a[i].num, a[i].den);
    }
    fprintf(fout, "\n\n");
    /*printf("threshold=");fflush(stdout);*/

    fscanf(fin, "%lf", &th);
    fscanf(fin, "%lf", &th);
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
    fclose(fin);
    return 0;
}