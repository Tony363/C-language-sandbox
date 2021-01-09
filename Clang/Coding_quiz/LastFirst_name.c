#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
    char word1[22], word2[22];
    scanf("%s %s", word1, word2);
    if (word1[strlen(word1)-1]==',') { /* L, F */
        int i;
        for (i=0; i<strlen(word1); i++) {
            printf("%c", toupper(word1[i]));
        }
        printf(" %s", word2);
    } else { /* F L */
        int i;
        for (i=0; i<strlen(word2); i++) {
            printf("%c", toupper(word2[i]));
        }
        printf(", %s", word1);
    }
    return 0;
}