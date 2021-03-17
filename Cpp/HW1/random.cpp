#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

int main(void){
    srand(time(NULL));
    int randInt;
    for (int i=0;i<10;i++){
        randInt = (rand() % 90) + 10;
        cout << randInt << endl;
    }
    return 0;
}