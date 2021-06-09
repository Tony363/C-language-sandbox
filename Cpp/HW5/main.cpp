// #pragma Once
#include <iostream>
#include <vector>
#include <tuple>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <test.h>
#include <Board.h>
using namespace std;

void TestRun::testGame(){
    iss.push_back(istringstream("0 0 1 0 0 1 1 1 0 2"));
    this->test.setTestBool(true);
    // this->test->setTestInput(iss);
    this->test.run();
}
void testSuite(){
    Game one;
    one.run();
}
int main(void){
    testSuite();
    return 0;
}