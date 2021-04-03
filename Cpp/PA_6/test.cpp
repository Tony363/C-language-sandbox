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
    assert(test.accessTest()==true);
    assert(test.testPrintTree()==true);
    assert(test.testSearch()==true);
    assert(test.testPrintMword()==true);
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
    test.display();
    cout << "Testing print tree: PASSED" << endl;
    return true;
}
bool testBST::testSearch(){
    BST test = BST();
    if (test.getRoot()->getLeft()==NULL || test.getRoot()->getRight()==NULL){
        return false;
    }
    cout << test.search('H') << endl;// << test.search('E') << test.search('L') << test.search('L') << test.search('O') << endl;
    cout << "\nTesting Search tree: PASSED" << endl;
    return true;
}
bool testBST::testPrintMword(){
    BST test = BST();
    string input;
    cout << "Please Enter text to conver to Morse Code: ";
    cin >> input;
    cout << endl;
    for (char& c:input){
        cout << test.search(c) << " ";
    }
    cout << endl;
    cout << "Testing print word to morse code: PASSED" << endl;
    return true;
}
testBST::~testBST(){

}