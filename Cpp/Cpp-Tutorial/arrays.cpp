#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(void){
    typedef int arraylength;
    arraylength length = 5;
    int array[length];
    for (int i=0;i<length;i++){
        array[i] = rand();
        cout << array[i] << endl;
    }
    cout << "RAND_MAX value is " << RAND_MAX << endl;
    return 0;
}