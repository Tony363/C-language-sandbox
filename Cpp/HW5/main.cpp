#pragma Once
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <fstream>
#include <Game.h>
using namespace std;

void testSuite(){
    ifstream infile("testCases.txt");
    if (infile.is_open()){
        string line;
        Game* test = NULL;
        while (getline(infile,line)){
            cout << "RUNNING TESTS" << endl;
            istringstream iss(line);
            test = new Game(true,iss);
            test->run();
        }
        
    }else{
        Game one;
        one.run();
    }
}
int main(void){
    testSuite();
    return 0;
}