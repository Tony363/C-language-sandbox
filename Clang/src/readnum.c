#include <stdio.h>
#include "frac.h"

void read_fraction_index(int idx)
{
    FILE *f = fopen("../Texts/fractionOut.bin", "rb");
    Frac frac;
    fseek(f, idx * sizeof(Frac), SEEK_SET); // cursor offset by Frac memory bytes
    fread(&frac, sizeof(Frac), 1, f);
    double val = ((double)frac.num / (double)frac.dem);
    printf("%d/%d = %lf\n", frac.num, frac.dem, val);
    fclose(f);
}

void write_fractions_bin(FILE *file, Frac fracs[], int len)
{
    FILE *fout = fopen("../Texts/fractionOut.bin", "wb");
    int n, d, i;
    for (i = 0; i < 10; i++)
    {
        fscanf(file, "%d/%d", &n, &d);
        fracs[i].num = n;
        fracs[i].dem = d;
        double val = ((double)fracs[i].num / (double)fracs[i].dem);
        printf("%d/%d = %lf\n", fracs[i].num, fracs[i].dem, val);
    }
    printf("sizeof(Frac)=%d\n", sizeof(Frac));
    printf("sizeof(int)=%d\n", sizeof(int));
    fwrite(fracs, sizeof(Frac), 10, fout);
    fclose(fout);
}

int main(int argc, char **argv)
{
    FILE *f = fopen("../Texts/fraction.txt", "rb");
    int idx;
    Frac fracs[10];
    sscanf(argv[1], "%d", &idx);
    if (argc < 2 || (idx < 0 || idx > 9))
    {
        fprintf(stderr, "Please supply the index in [0,9]\n");
        return -1;
    }

    write_fractions_bin(f, fracs, 10);
    fclose(f);
    // fread(fracs, sizeof(Frac), 10, f);
    // printf("%d/%d\n", fracs[0].num, fracs[0].dem);
    read_fraction_index(idx);

    return 0;
}