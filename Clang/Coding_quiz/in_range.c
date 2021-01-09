#include <stdio.h>

int main(int argc, char **argv) {
    double v;
    
    scanf("%lf", &v);
    if (v>=30 && v<=50) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    return 0;
}