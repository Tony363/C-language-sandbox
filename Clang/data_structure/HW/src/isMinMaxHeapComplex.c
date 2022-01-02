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
    int n_chars = 0, complexFlag = 0;
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
        while (isdigit(s[n_chars]) || (complexFlag = isalpha(s[n_chars])))
            n_chars++;
    }
    else
    {
        n_chars++;
    }
    if (complexFlag)
    {
        strncpy(token, s, n_chars);
        *(token + n_chars) = '\0';
    }
    else
    {
        strncpy(token, s, n_chars);
        *(token + n_chars) = '\0';
    }

    return n_chars;
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

double evalComplex(const char *expr)
{
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}