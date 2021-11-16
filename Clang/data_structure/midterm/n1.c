#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *sample = "wtf, hello 12345";
    char *str1, *str2;
    int digits;
    fscanf(sample, "%s", &str1);
    fscanf(sample, "%s", &str2);
    fscanf(sample, "%d", &digits);
    return 0;
}