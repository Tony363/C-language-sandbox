#include <iostream>
#include <assert.h>
#include <../includes/AT.h>
using namespace std;

tm* getTimeNow(){
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return localtm;
}

void test_suit(){
    Tests test;
    assert(test.testReadFile()==true);
    assert(test.testMarkStudentAbsence()==true);
    assert(test.testGenerateReport()==true);
}
int main(void){
    test_suit();
    // Node<Data> node;
    return 0;
}