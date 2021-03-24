#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int diceRoll(){
    return 1 + (rand() % (6 - 1 + 1) );
}

int calDieSum(){
    return diceRoll() + diceRoll();
}

int* simulate(int N=36000){
    static int tabulate[13] = {0};
    for (int i=0;i<N;i++){
        tabulate[calDieSum()]++;
    }
    return tabulate;
}

void printSimulatation(){
    srand(time(NULL));
    int* simArr = (int*)malloc(sizeof(int)*13);
    simArr = simulate();
    for (int i=2;i<13;i++){
        cout << "(" << i << ") " << (double)simArr[i]/360 << endl;
    }
}

int main (void){
    printSimulatation();
    return 0;
}