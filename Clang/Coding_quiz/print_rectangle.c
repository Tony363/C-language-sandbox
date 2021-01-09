#include <stdio.h>

int main(int argc, char **argv) {
    int size, i, j;
    scanf("%d", &size);
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}