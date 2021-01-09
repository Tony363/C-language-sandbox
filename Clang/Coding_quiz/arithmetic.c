#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int n1, n2;
    char op;
    scanf("%d %c %d", &n1, &op, &n2);
    switch(op) {
        case '+':
            printf("%d", n1+n2);
            break;
        case '-':
            printf("%d", n1-n2);
            break;
        case '*':
            printf("%d", n1*n2);
            break;
        case '/':
            if (n2==0) { 
                printf("Divided by zero!");
            } else {
                printf("%d", n1/n2);
            }
            break;
        case '%':
            if (n2==0) { 
                printf("Divided by zero!");
            } else {
                printf("%d", n1%n2);
            }
            break;
    }
    return 0;
}