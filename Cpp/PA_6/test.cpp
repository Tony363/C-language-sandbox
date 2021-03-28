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
    // assert(test.testReadFile()==true);
    // assert(test.accessTest()==true);
    assert(test.testPrintTree()==true);
    // assert(test.testSearch()==true);
}
testBST::testBST(){

}
bool testBST::testReadFile(){
    BST test = BST();
    cout << "Test read File: PASSED" << endl;
    return true;
} 
bool testBST::accessTest(){
    BST test = BST();
    cout << test.getRoot()->getChar() << test.getRoot()->getMcode() << endl;
    if (test.getRoot()->getLeft()==NULL || test.getRoot()->getRight()==NULL){
        return false;
    }
    cout << test.getRoot()->getLeft() << test.getRoot()->getRight() << endl;
    cout << "Testing class object access rights: PASSED" << endl;
    return true;
}
bool testBST::testPrintTree(){
    BST test = BST();
    if (test.getRoot()->getLeft()==NULL || test.getRoot()->getRight()==NULL){
        return false;
    }
    test.printBST();
    cout << "Testing print tree: PASSED" << endl;
    return true;
}
bool testBST::testSearch(){
    BST test = BST();
    test.search(test.getRoot(),'A');
    cout << "Testing Search tree: PASSED" << endl;
    return true;
}
testBST::~testBST(){

}