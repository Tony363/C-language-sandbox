#include <stdio.h>

char score2letter(int score) {
    switch(score/10) {
        case 10: case 9: case 8:
            return 'A';
        case 7:
            return 'B';
        case 6:
            return 'C';
        default:
            return 'F';
    }
}

int main(void){
    printf("%c\n", score2letter(95));
    return 0;
}