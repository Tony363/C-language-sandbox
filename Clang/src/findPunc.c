#include <stdio.h>
#include <ctype.h>
char *findPunct(char *s)
{
    char *p = s;
    while (*p != '\0')
    {
        if (ispunct(*p))
        {
            return p;
        }
        p++;
    }
    return NULL;
}
int main(int argc, char **argv)
{
    char *s = "Hello, World!";
    char *p = findPunct(s);
    if (p == s + 5)
        printf("true");
    else
        printf("false");
    return 0;
}