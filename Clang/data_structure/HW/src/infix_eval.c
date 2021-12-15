#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "../../includes/intstack.h"

typedef void (*token_handler)(const char *token, IntStack *oprtr_s, IntStack *oprnd_s);
typedef void (*finalize_parsing)(IntStack *oprtr_s, IntStack *oprnd_s);

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

int eval(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/')
        return a / b;
    return pow(a, b);
}

int readToken(const char *s, char *token)
{
    // copy to token
    int n_chars = 0;
    if (!s)
    {
        return n_chars;
    }
    else if (s[n_chars] == '\0')
    {
        return n_chars;
    }
    else if (s[n_chars] == '*' && s[n_chars + 1] == '*')
    {
        strcpy(token, "^\0");
        return n_chars + 2;
    }
    else if (isdigit(s[n_chars]))
    {
        while (isdigit(s[n_chars]))
            n_chars++;
    }
    else
    {
        n_chars++;
    }
    strncpy(token, s, n_chars);
    *(token + n_chars) = '\0';
    return n_chars;
}

void postfix_handler(const char *token, IntStack *oprtr_s, IntStack *oprnd_s)
{
    char p;
    int value;
    if (token[0] == ' ')
    {
        return;
    }
    else if (isdigit(token[0]))
    {
        pushIS(oprnd_s, atoi(token));
    }
    else if (token[0] == '(')
    {
        pushIS(oprtr_s, !(token[0] == '*' && token[1] == '*') ? token[0] : '^');
    }
    else if (token[0] == ')')
    {
        while (!isEmptyIS(oprtr_s))
        {
            p = (char)popIS(oprtr_s, NULL);
            if (p == '(')
                break;
            value = eval((int)popIS(oprnd_s, NULL), (int)popIS(oprnd_s, NULL), p);
            pushIS(oprnd_s, (int)value);
        }
    }
    else
    {
        while (!isEmptyIS(oprtr_s) && (char)peekIS(oprtr_s, NULL) != '(' && (checkPrecedence(token[0]) <= checkPrecedence((char)peekIS(oprtr_s, NULL)))) // i had check precedence in other implementation
        {
            p = (char)popIS(oprtr_s, NULL);
            value = eval((int)popIS(oprnd_s, NULL), (int)popIS(oprnd_s, NULL), p);
            pushIS(oprnd_s, (int)value);
        }
        pushIS(oprtr_s, !(token[0] == '*' && token[1] == '*') ? token[0] : '^');
    }
}

void postfix_end(IntStack *oprtr_s, IntStack *oprnd_s)
{
    char popped;
    while (!isEmptyIS(oprtr_s))
    {
        if ((char)peekIS(oprtr_s, NULL) == '(' || (char)peekIS(oprtr_s, NULL) == ')')
            popIS(oprtr_s, NULL);
        popped = (char)popIS(oprtr_s, NULL);
        pushIS(oprnd_s, eval((int)popIS(oprnd_s, NULL), (int)popIS(oprnd_s, NULL), popped));
    }
    int p = popIS(oprnd_s, NULL);
    if (p == 0)
        printf("no expression");
    else
        printf("%d", p);
}

void parse_infix(const char *s, token_handler handler, finalize_parsing flush_op_stack)
{
    char word[100];
    int ret, n_chars, offset = 0;
    IntStack *oprtr_s; /* operator stack */
    IntStack *oprnd_s; /* operand stack */

    oprtr_s = createIntStackIS();
    oprnd_s = createIntStackIS();
    while ((n_chars = readToken(s + offset, word)))
    {
        handler(word, oprtr_s, oprnd_s);
        offset += n_chars;
    }
    flush_op_stack(oprtr_s, oprnd_s);
}

int main(int argc, char **argv)
{
    // char line[100];
    // printf("Input a line of infix expression: ");
    // fflush(stdout);
    // fgets(line, 100, stdin);
    // char line[] = "20 ** ( 3 ^ 4 )";
    // char line[] = "( 7 - 3 ) * ( 9 - 8 ) / 4";
    // char line[] = "2^3 / 4";
    // char line[] = "20 + 3 + 4 ";
    char line[] = "( 67 - 3 ) /4**(2 *1 )";
    // char line[] = "";
    // char line[] = "2 ** ( 3 ^ 2 )";
    parse_infix(line, postfix_handler, postfix_end);
    return 0;
}