#include <stdio.h>
#include <string.h>

typedef void (*token_handler)(const char *token);

void parseString(const char *s, token_handler handler)
{
    char word[100];
    int ret, n_chars, offset = 0;
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

int main(int argc, char **argv)
{
    char line[1024];
    int n_chars, ret;
    char word[100];

    printf("Input a line of string:\n");
    fflush(stdout);
    fgets(line, 1024, stdin);

    // ret = sscanf(s, "%s%n", word, &n_chars);
    // printf("Read '%s' of length %d with return status %d\n", word, n_chars, ret);
    // ret = sscanf(s + n_chars, "%s%n", word, &n_chars); // %n means number characters processed
    // printf("Read '%s' of length %d with return status %d\n", word, n_chars, ret);
    parseString(line, handler1);
    printf("\n\n");
    parseString(line, handler2);

    return 0;
}