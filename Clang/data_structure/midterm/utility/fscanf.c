#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *pFile = fopen("test.txt", "w+");
    char *sample = "wtf, hello 12345";
    fprintf(pFile, "%s", sample);
    char *sample2 = "mac tee ode era ria lea vim";
    fprintf(pFile, "%s", sample2);

    char *str1 = (char *)malloc(sizeof(char) * 20);
    char *str2 = (char *)malloc(sizeof(char) * 20);
    char *str3 = (char *)malloc(sizeof(char) * 4);
    char *str4 = (char *)malloc(sizeof(char) * 4);
    char *str5 = (char *)malloc(sizeof(char) * 4);
    char *str6 = (char *)malloc(sizeof(char) * 4);
    char *str7 = (char *)malloc(sizeof(char) * 4);
    char *str8 = (char *)malloc(sizeof(char) * 4);
    char *str9 = (char *)malloc(sizeof(char) * 4);
    int digits;

    rewind(pFile);
    fscanf(pFile, "%s", str1);
    fscanf(pFile, "%s", str2);
    fscanf(pFile, "%d", &digits);
    printf("%s %s %d", str1, str2, digits);

    fscanf(pFile, "%s", str3);
    fscanf(pFile, "%s", str4);
    fscanf(pFile, "%s", str5);
    fscanf(pFile, "%s", str6);
    fscanf(pFile, "%s", str7);
    fscanf(pFile, "%s", str8);
    fscanf(pFile, "%s", str9);
    printf("%s %s %s %s %s %s %s %s", str3, str4, str5, str6, str7, str8, str9);
    fclose(pFile);
    free(str1);
    free(str2);
    free(str3);
    free(str4);
    free(str5);
    free(str6);
    free(str7);
    free(str8);
    free(str9);

    return 0;
}

/*
c program demonstrating fscanf and its usage
 Assuming that abc.txt has content in below
       format
       NAME    AGE   CITY
       abc     12    hyderbad
       bef     25    delhi
       cce     65    bangalore

#include<stdio.h>
int main()
{
    FILE* ptr = fopen("abc.txt","r");
    if (ptr==NULL)
    {
        printf("no such file.");
        return 0;
    }

    char buf[100];
    while (fscanf(ptr,"%*s %*s %s ",buf)==1)
        printf("%s\n", buf);

    return 0;
}
*/
