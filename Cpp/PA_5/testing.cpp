#include <GSStest.h>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

void test_function1();

int main(void) {
    // Call all tests. Using a test framework would simplify this.
    test_function1();
}


void test_function1(){
    // test random in range generator
    GSStesting test;
    assert(test.inRange(getRand("express"),"express") == true);
    assert(test.inRange(getRand("normal"),"normal") == true);
}