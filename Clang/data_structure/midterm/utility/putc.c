/* putc example: alphabet writer */
#include <stdio.h>

int main()
{
    FILE *pFile;
    char c;

    pFile = fopen("alphabet.txt", "wt");
    for (c = 'A'; c <= 'Z'; c++)
    {
        putc(c, pFile);
    }
    fclose(pFile);
    return 0;
}