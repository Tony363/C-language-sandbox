#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "../../includes/intstack.h"

typedef void (*token_handler)(const char *token, IntStack *s);
typedef void (*finalize_parsing)(IntStack *s);

void parse_infix(const char *s, token_handler handler, finalize_parsing flush_op_stack)
{
    char word[100];
    int n_chars, offset = 0;
    IntStack *opst;

    opst = createIntStackIS();
    while (1 == sscanf(s + offset, "%s%n", word, &n_chars))
    {
        handler(word, opst);
        offset += n_chars;
    }
    flush_op_stack(opst);
}

int checkPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

void postfix_handler(const char *token, IntStack *s)
{
    char p;
    if (token[0] == ' ')
    {
        return;
    }
    else if (isdigit(token[0]))
    {
        printf("%s ", token);
    }
    else if (token[0] == '(')
    {
        pushIS(s, !(token[0] == '*' && token[1] == '*') ? token[0] : '^');
    }
    else if (token[0] == ')')
    {
        while (!isEmptyIS(s))
        {
            p = (char)popIS(s, NULL);
            if (p == '(')
                break;
            printf("%c ", p);
        }
    }
    else
    {
        while (!isEmptyIS(s) && (char)peekIS(s, NULL) != '(' && (checkPrecedence(token[0]) <= checkPrecedence((char)peekIS(s, NULL)))) // i had check precedence in other implementation
        {
            printf("%c ", (char)popIS(s, NULL));
        }
        pushIS(s, !(token[0] == '*' && token[1] == '*') ? token[0] : '^');
    }
}

void postfix_end(IntStack *s)
{
    char popped;
    while (!isEmptyIS(s))
    {
        if ((char)peekIS(s, NULL) == '(' || (char)peekIS(s, NULL) == ')')
            popIS(s, NULL);
        popped = (char)popIS(s, NULL);
        printf("%c ", popped);
    }
}

int main(int argc, char **argv)
{
    // char line[] = "20 ** ( 3 ^ 4 )";
    // char line[] = "20 ^ ( 3 / 4 )";
    // char line[] = "20 + 3 + 4 ";
    // char line[] = "( 7 - 3 ) * ( 9 - 8 ) / 4";
    char line[100];
    printf("Input a line of infix expression: ");
    fflush(stdout);
    fgets(line, 100, stdin);
    parse_infix(line, postfix_handler, postfix_end);
    return 0;
}
