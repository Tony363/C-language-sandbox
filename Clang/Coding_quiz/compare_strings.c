#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {
    char word1[11], word2[11];
    int i=0;
    scanf("%s %s", word1, word2);
    for (i=0; word1[i]&&word2[i]; i++) {
        if (toupper(word1[i])!=toupper(word2[i])) {
            printf("FALSE");
            return 0;
        }
    }
    printf("TRUE\n");
    return 0;
}