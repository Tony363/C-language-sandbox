#include <iostream>
#include <BSTNode.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

// =================================================================
// BST node methods
// =================================================================
BSTNode::BSTNode(){

}
BSTNode::BSTNode(char character,string Mcode){
    this->ascii = character;
    this->code = Mcode;
    this->left = NULL;
    this->right = NULL;
}
void BSTNode::setChar(char character){
    this->ascii = character;
}
void BSTNode::setMcode(string Mcode){
    this->code = Mcode;
}
BSTNode* BSTNode::getLeft(){
    return this->left;
}
BSTNode* BSTNode::getRight(){
    return this->right;
}
char BSTNode::getChar(){
    return this->ascii;
}
string BSTNode::getMcode(){
    return this->code;
}
BSTNode::~BSTNode(){

}

// =================================================================
// Binary search tree methods
// =================================================================
BST::BST(){
    setTest();
    this->root=NULL;
    ifstream MorseFile;
    MorseFile.open("morseCode.txt");
    if (MorseFile.is_open()){
        parseFile(MorseFile);
    }else {
        cout << "Unable to open file";
    }
    MorseFile.close();
}
void BST::parseFile(ifstream &file){
    string line,Mcode;
    while(getline(file,line)){
        char character = line[0];
        stringstream ss;
        ss << line;
        getline (ss,Mcode,character);
        getline (ss,Mcode,character);
        // if (this->root == NULL){
        //     insert(character,Mcode);
        //     continue;
        // }
        insert(character,Mcode);
    }
    cout << endl;
}
void BST::insert(char character,string Mcode) {
        this->root = insert(character,Mcode, this->root);
}
BSTNode* BST::insert(char character,string Mcode, BSTNode* t){
        BSTNode* left = t->getLeft();
        BSTNode* right = t->getRight();
        if(t == NULL){
            t = new BSTNode(character,Mcode);
        }
        else if((int)character < (int)t->getChar()){
            left = insert(character,Mcode, left);
        }
        else if((int)character > (int)t->getChar()){
            right = insert(character,Mcode, right);
        }
        return t;
}
BSTNode* BST::findMax(BSTNode* t) {
    if(t == NULL)
        return NULL;
    else if(t->getRight() == NULL)
        return t;
    else
        return findMax(t->getRight());
}
BSTNode* BST::findMin(BSTNode* t){
        if(t == NULL)
            return NULL;
        else if(t->getLeft() == NULL)
            return t;
        else
            return findMin(t->getLeft());
}
BSTNode* BST::remove(char character, BSTNode* t) {
    BSTNode* temp;
    BSTNode* left = t->getLeft();
    BSTNode* right = t->getRight();
    char currChar = t->getChar();
    if(t == NULL){
        return NULL;
    }
    else if((int)character < (int)t->getChar()){
        left = remove(character, left);
    }
    else if((int)character > (int)t->getChar()){
        right = remove(character, right);
    }
    else if(left && right)
    {
        temp = findMin(right);
        currChar = temp->getChar();
        t->getMcode() = temp->getMcode();
        right = t->getRight();
        right = remove(currChar, right);
    }
    else
    {
        temp = t;
        if(left == NULL)
            t = right;
        else if(right == NULL)
            t = left;
        delete temp;
    }

    return t;
}
void BST::inorder(BSTNode* t) {
        if(t == NULL)
            return;
        inorder(t->getLeft());
        cout << t->getChar() << " | " << t->getMcode() << " ";
        inorder(t->getRight());
    }
void BST::display(){
    inorder(root);
    cout << endl;
}
BSTNode* BST::find(BSTNode* t, char character) {
        if(t == NULL)
            return NULL;
        else if((int)character < (int)t->getChar())
            return find(t->getLeft(), character);
        else if((int)character > (int)t->getChar())
            return find(t->getRight(), character);
        else
            return t;
    }
void BST::search(char character){
    root = find(root, character);
}
void BST::setTest(){
    string boolean;
    cout << "test or not test: ";
    cin >> boolean;
    this->test = (boolean=="true")?false:true;
}
BSTNode* BST::getRoot(){
    return this->root;
}
BSTNode* BST::makeEmpty(BSTNode* t) {
    if(t == NULL)
        return NULL;
    {
        makeEmpty(t->getLeft());
        makeEmpty(t->getRight());
        delete t;
    }
    return NULL;
}
BST::~BST(){
    this->root = makeEmpty(this->root);
}