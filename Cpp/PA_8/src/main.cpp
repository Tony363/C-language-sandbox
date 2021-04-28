#include <iostream>
#include <assert.h>
#include <BST.h>
#include <DataAnalysis.h>
using namespace std;

void test_suite(){
    TestBST test;
    assert(test.TestNode()==true);
    assert(test.TestRunAnalysis() == true);
    assert(test.TestTrend()==true);
}
int main (void){
    test_suite();
    return 0;
}