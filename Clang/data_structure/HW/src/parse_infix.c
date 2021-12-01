#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../../includes/intstack.h"

typedef void (*token_handler)(const char *token, IntStack *s);
typedef void (*finalize_parsing)(IntStack *s);

void parse_infix(const char *s, token_handler handler, finalize_parsing flush_op_stack)
{
    char word[100];
    int n_chars, offset = 0;
    IntStack *opst;

    opst = createIntStack();
    while (1 == sscanf(s + offset, "%s%n", word, &n_chars))
    {
        handler(word, opst);
        offset += n_chars;
    }
    flush_op_stack(opst);
}

void postfix_handler(const char *token, IntStack *s)
{
}

void postfix_end(IntStack *s)
{
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
    else if (token[0] == '*' || token[0] == '/')
    {
        while (!isEmptyIS(s) && (peekIS(s, NULL) == '*' || peekIS(s, NULL) == '/'))
        {
            printf("%c ", (char)popIS(s, NULL));
        }
        pushIS(s, token[0]);
    }
    else if (token[0] == '+' || token[0] == '-')
    {
        while (!isEmptyIS(s) && peekIS(s, NULL) != '(')
        {
            printf("%c ", (char)popIS(s, NULL));
        }
        pushIS(s, token[0]);
    }
    else
    {
        while (!isEmptyIS(s) && peekIS(s, NULL) != '(')
        {
            printf("%c ", (char)popIS(s, NULL));
        }
        popIS(s, NULL);
    }
}

int main(int argc, char **argv)
{
    char line[1024];
    int n_chars, ret;
    char word[100];

    printf("Input a line of infix expression: ");
    fflush(stdout);
    fgets(line, 1024, stdin);

    IntStack *s = createIntStack();
    parse_string(line, infix_handler);
    while (!isEmptyIS(s))
    {
        printf("%c ", (char)popIS(s, NULL));
    }
    printf("\n");

    return 0;
}
