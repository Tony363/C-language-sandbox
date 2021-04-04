#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>
#include <assert.h>
#include <ctype.h>
#include <testBST.h>
#include <BSTNode.h>
#include <HashTable.h>


using namespace std;

void test_functions();

int main (void){
    test_functions();
    return 0;
}

void test_functions(){
    testBST testBST; testHash testHash;
    assert(testBST.testReadFile()==true);
    assert(testBST.accessTest()==true);
    assert(testBST.testPrintTree()==true);
    assert(testBST.testSearch()==true);
    assert(testBST.testPrintMword()==true);
    assert(testHash.testReadtoHashMap()==true);
    assert(testHash.testSearchHashMap()==true);
    assert(testHash.testRemoveFromHashMap()==true);
    cout << "wtf" << endl; 
}
//================================================================
// BST tests
//================================================================
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
    // input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
    
    cout << input << endl;
    cout << endl;
    for (char& c:input){
        if (c == ' ') {
            cout << "  ";
        }
        cout << test.search(toupper(c)) << " ";
    }
    cout << endl;
    cout << "Testing print word to morse code: PASSED" << endl;
    return true;
}
testBST::~testBST(){

}
// =================================================================
// Hash Map tests
// =================================================================
testHash::testHash(){

}
bool testHash::testReadtoHashMap(){
    ifstream file("morseCode.txt");
    HashMapTable hash;
    if (file.is_open()){
        string line,Mcode;
        while(getline(file,line)){
            char character = line[0];
            stringstream ss;
            ss << line;
            getline (ss,Mcode,character);
            getline (ss,Mcode,character);
            hash.Insert(character,Mcode);
        }
    }else {
        cout << "Unable to Read file" << endl;
        return false;
    }
    cout << "Testing insertion to HashMap: PASSED" << endl;
    return true;
}
bool testHash::testSearchHashMap(){
    ifstream file("morseCode.txt");
    HashMapTable hash;
    if (file.is_open()){
        string line,Mcode;
        while(getline(file,line)){
            char character = line[0];
            stringstream ss;
            ss << line;
            getline (ss,Mcode,character);
            getline (ss,Mcode,character);
            hash.Insert(character,Mcode);
        }
    }else {
        cout << "Unable to Read file" << endl;
        return false;
    }
    char SearchKey;
    cout << "Please enter testing search character from file: ";
    cin >> SearchKey;
    cout << hash.SearchKey(SearchKey) << endl;
    cout << "Testing insertion to HashMap: PASSED" << endl;
    return true;
}
bool testHash::testRemoveFromHashMap(){
    ifstream file("morseCode.txt");
    HashMapTable hash;
    if (file.is_open()){
        string line,Mcode;
        while(getline(file,line)){
            char character = line[0];
            stringstream ss;
            ss << line;
            getline (ss,Mcode,character);
            getline (ss,Mcode,character);
            hash.Insert(character,Mcode);
        }
    }else {
        cout << "Unable to Read file" << endl;
        return false;
    }
    char charR;
    cout << "Please enter Char to remove from HashMap: ";
    cin >> charR;
    hash.Remove(charR);
    if (hash.SearchKey(charR) == "NONE"){
        return true;
    }
    return false;
}
testHash::~testHash(){

}