#include <iostream>
#include <assert.h>
#include <../includes/AT.h>
using namespace std;

void test_suit(){
    Tests test;
    assert(test.testReadFile()==true);
    assert(test.testMarkStudentAbsence()==true);
    assert(test.testGenerateReport()==true);
}
int main(void){
    test_suit();
    return 0;
}