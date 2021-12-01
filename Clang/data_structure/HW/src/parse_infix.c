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

int isOperand(char c)
{
    return !(
        c == '+' || c == '-' ||
        c == '*' || c == '/' ||
        c == '(' || c == ')' || c == '^');
}

int tokenize(const char *token)
{
    int p = token[0];
    char *toParse = (char *)malloc(sizeof(char) * 4);
    strncpy(toParse, token, 4);
    if (!strcmp(toParse, "**"))
    {
        p = '^';
    }
    else if (strlen(token) > 0)
    {
        sscanf(token, "%d", &p);
    }
    free(toParse);
    return p;
}

void postfix_handler(const char *token, IntStack *s)
{

    char p = (char)tokenize(token);
    // TODO: exponential ^  & ** as ^
    // TODO: spacing
    // TODO: parentheses

    if (p == ' ')
    {
        return;
    }
    else if (isdigit(p))
    {
        printf("%c ", p);
    }
    else if (isOperand(p))
    {
        printf("%d ", p);
    }
    else if (p == '(')
    {
        pushIS(s, p);
    }
    else if (p == ')')
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
        while (!isEmptyIS(s) && (char)peekIS(s, NULL) != '(' && (checkPrecedence(p) <= checkPrecedence((char)peekIS(s, NULL)))) // i had check precedence in other implementation
        {
            printf("%c ", (char)popIS(s, NULL));
        }
        pushIS(s, p);
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
    char line[] = "20 ^ ( 3 / 4 )";
    // char line[] = "20 + 3 + 4 ";
    // char line[] = "( 7 - 3 ) * ( 9 - 8 ) / 4";
    // char line[100];
    // printf("Input a line of infix expression: ");
    // fflush(stdout);
    // fgets(line, 100, stdin);
    parse_infix(line, postfix_handler, postfix_end);
    return 0;
}
