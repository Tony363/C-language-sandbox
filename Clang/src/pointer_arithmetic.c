#include <stdio.h>

/*
Copy last three addresses of 
intarray into parray which is
an array of pointers to an int.
*/
int main() {
    int intarray[5] = {10,20,30,40,50};
    //-----------------------^
    int *pointer = &intarray[2];

    // Array of 3 pointers
    int *parray[3];

    // Copy last three addresses of intarray into parray
    // Use parray and pointer
    int i;
    for (i = 0; i < 3; i++) {
        // Insert code here
        parray[i] = &pointer[i];
        printf("%p\n",parray[i]);
    }

    // Test code
    for (i = 0; i < 3; i++) {
        if (parray[i] == &pointer[i]) {
            printf("Matched!\n");
        } else {
            printf("Fail\n");
        }
    }

    return 0;
}
