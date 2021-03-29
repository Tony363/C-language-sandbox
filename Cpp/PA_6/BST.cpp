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
        insert(character,Mcode);
    }
    cout << endl;
}
void BST::insert(char character,string Mcode) {
    this->root = insert(character,Mcode, this->root);
}
BSTNode* BST::insert(char character,string Mcode, BSTNode* t){
        if(t == NULL){
            t = new BSTNode(character,Mcode);
            if (!(this->test)){
                cout << t << " | "  << t->getChar() << " | " << t->getMcode() << endl;
            }
        }
        else if((int)character < (int)t->getChar()){
            if (!(this->test)){
                cout << "left " 
                    << (int)character
                    << " | " 
                    << (int)t->getChar()
                    << endl;
            }
            //  BSTNode* left = t->getLeft();
            t->left = insert(character,Mcode, t->left);
        }
        else if((int)character > (int)t->getChar()){
            if (!(this->test)){
                cout << "right " 
                    << (int)character
                    << " | " 
                    << (int)t->getChar()
                    << endl;
            }
            //  BSTNode* right = t->getRight();
            t->right = insert(character,Mcode, t->right);
        }
        return t;
}
BSTNode* BST::findMax(BSTNode* t) {
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return findMax(t->right);
}
BSTNode* BST::findMin(BSTNode* t){
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
}
BSTNode* BST::remove(char character, BSTNode* t) {
    BSTNode* temp;
    // BSTNode* left = t->left;
    // BSTNode* right = t->right;
    char currChar = t->getChar();
    if(t == NULL){
        return NULL;
    }
    else if((int)character < (int)t->getChar()){
        t->left = remove(character, t->left);
    }
    else if((int)character > (int)t->getChar()){
        t->right = remove(character, t->right);
    }
    else if(left && right)
    {
        temp = findMin(t->right);
        currChar = temp->getChar();
        t->getMcode() = temp->getMcode();
        t->right = t->right;
        t->right = remove(currChar, t->right);
    }
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}
void BST::inorder(BSTNode* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->getChar() << " " << t->getMcode() << " | ";
        inorder(t->right);
    }
void BST::display(){
    inorder(root);
    cout << endl;
}
BSTNode* BST::find(BSTNode* t, char character) {
    if(t == NULL)
        return NULL;
    else if((int)character < (int)t->getChar())
        return find(t->left, character);
    else if((int)character > (int)t->getChar())
        return find(t->right, character);
    else
        return t;
}
string BST::search(char character){
    BSTNode* temp = root;
    temp = find(temp, character);
    // cout <<  root->getMcode();;
    return temp->getMcode();
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
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}
BST::~BST(){
    this->root = makeEmpty(this->root);
}