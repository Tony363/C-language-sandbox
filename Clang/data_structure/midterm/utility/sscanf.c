/* sscanf example */
#include <stdio.h>

int main()
{
    char sentence[] = "Rudolph is 12 years old";
    char str[20], str1[5], str2[5], str3[5];

    int i;

    sscanf(sentence, "%d %s %s", &i, str2, str3);
    printf("%d %s %s\n", i, str2, str3);

    return 0;
}