#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../includes/intstack.h"

typedef void (*token_handler)(const char *token);

void parseString(const char *s, token_handler handler)
{
    char word[100];
    int ret, n_chars, offset = 0;
    // scans string 1 token at a time
    // sscanf skips white space
    // %n to parse new tokens char * index to n_chars
    // sscanf from strings offset pointer index
    while (1 == sscanf(s + offset, "%s%n", word, &n_chars))
    {
        handler(word);
        // printf("Got word '%s'\n", word);
        offset += n_chars;
    }
}

void handler1(const char *token)
{
    printf("Got word '%s'\n", token);
}

void handler2(const char *token)
{
    printf("'%s'(%d)\n", token, strlen(token));
}

IntStack *s;

void infix_handler(const char *token)
{
    if (isdigit(token[0]))
    {
        printf("%s ", token);
    }
    else if (token[0] == '(')
    {
        pushIS(s, '(');
    }
    else if (!isEmptyIS(s) && token[0] == '*' || token[0] == '/')
    {
        while (peekIS(s, NULL) == '*' || peekIS(s, NULL) == '/')
        {
            printf("%c ", (char)(popIS(s, NULL)));
        }
        pushIS(s, token[0]);
    }
    else if (token[0] == '+' || token[0] == '-')
    {
        while (!isEmptyIS(s) && peekIS(s, NULL) != ')')
        {
            printf("%c ", (char)(popIS(s, NULL)));
        }
        pushIS(s, token[0]);
    }
    else
    {
        while (!isEmptyIS(s) && peekIS(s, NULL) != '(')
        {
            printf("%c ", (char)(popIS(s, NULL)));
        }
        popIS(s, NULL);
    }
}

int main(int argc, char **argv)
{
    char line[1024];
    int n_chars, ret;
    char word[100];

    printf("Input a line of  infix expression:\n");
    fflush(stdout);
    fgets(line, 1024, stdin);

    // ret = sscanf(s, "%s%n", word, &n_chars);
    // printf("Read '%s' of length %d with return status %d\n", word, n_chars, ret);
    // ret = sscanf(s + n_chars, "%s%n", word, &n_chars); // %n means number characters processed
    // printf("Read '%s' of length %d with return status %d\n", word, n_chars, ret);
    // parseString(line, handler1);
    // printf("\n\n");
    // parseString(line, handler2);
    s = createIntStackIS();
    parseString(line, infix_handler);
    while (!isEmptyIS(s))
    {
        printf("%c ", (char)popIS(s, NULL));
    }
    printf("\n");
    return 0;
}
// gcc -g ../src/parseToken.c ../src/intstack.c ../src/AdtIntList.c -o parseToken