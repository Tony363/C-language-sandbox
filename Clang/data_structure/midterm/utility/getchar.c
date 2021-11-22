/* getchar example : typewriter */
#include <stdio.h>

int main()
{
    int c;
    puts("Enter text. Include a dot ('.') in a sentence to exit:");
    do
    {
        c = getchar();
        printf("printing: %c ", c);
        // putchar(c);
    } while (c != '.');
    return 0;
}