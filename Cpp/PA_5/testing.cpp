#include <GSStest.h>
#include <gss.h>
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
    GSStesting test; Data dtest;
    assert(test.testEnqueue()==true);
    assert(test.inRange(dtest.getRand("express"),"express") == true);
    assert(test.inRange(dtest.getRand("normal"),"normal") == true);
}