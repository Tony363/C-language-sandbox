#include <iostream>
#include <assert.h>
#include <testBST.h>
#include <BSTNode.h>

using namespace std;

void test_functions();

int main (void){
    test_functions();
    return 0;
}

void test_functions(){
    testBST test;
    assert(test.testReadFile()==true);
}
testBST::testBST(){

}
bool testBST::testReadFile(){
    BST test = BST();
    cout << "File read" << endl;
    // test.printBST();
    return true;
} 
testBST::~testBST(){

}