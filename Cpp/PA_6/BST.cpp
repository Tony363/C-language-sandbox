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
BSTNode::BSTNode(char text,string code){
    this->character = text;
    this->Mcode = code;
    this->pLeft = NULL;
    this->pRight = NULL;
    this->parent = NULL;
}
void BSTNode::setChar(char text){
    this->character = text;
}
void BSTNode::setMcode(string code){
    this->Mcode = code;
}
BSTNode* BSTNode::getLeft(){
    return this->pLeft;
}
BSTNode* BSTNode::getRight(){
    return this->pRight;
}
BSTNode* BSTNode::getParent(){
    return this->parent;
}
char BSTNode::getChar(){
    return this->character;
}
string BSTNode::getMcode(){
    return this->Mcode;
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
        if (this->root == NULL){
            BSTNode* newNode = new BSTNode(character,Mcode);
            this->root = newNode;
            continue;
        }
        this->root = insert(this->root,character,Mcode);
    }
    cout << endl;
}
BSTNode* BST::insert(BSTNode* nextNode,char text,string line){
    if (nextNode == NULL){
        BSTNode* newNode = new BSTNode(text,line);
        nextNode = newNode;
        if (!(this->test)){
            cout << nextNode << " | "  << nextNode->getChar() << " | " << nextNode->getMcode() << endl;
        }
    }
    if (((int)text) < ((int)(nextNode->getChar()))){
        BSTNode* left = nextNode->getLeft();
        if (!(this->test)){
            cout << "left " 
                << (int)text 
                << " | " 
                << (int)(nextNode->getChar()) 
                << "\n" 
                << endl; 
        }else{
            cout << "left::";
        }
        left = insert(left,text,line);
        BSTNode* parent = left->getParent();
        parent = nextNode;
    }
    if (((int)text) > ((int)(nextNode->getChar()))){
        BSTNode* right = nextNode->getRight();
        if (!test){
            cout << "right " 
                << (int)text 
                << " | " 
                << (int)(nextNode->getChar()) 
                << "\n" 
                << endl; 
        }else{
            cout << "right::";
        }
        right = insert(right,text,line);
        BSTNode* parent = right->getParent();
        parent = nextNode;
    }
    return nextNode;
}

void BST::printBST(){
    if (this->root==NULL){
        cout << "root was NULL" << endl;
        return;
    }
    cout << this->root->getChar()<< " | " << this->root->getMcode() << endl;
    traverse(this->root->getLeft());
}
void BST::traverse(BSTNode* node){
    if (node == NULL){
        cout << "wtf" << endl;
        return ;
    }
    if (node->getLeft()){
        cout << node->getChar() << " | ";
        traverse(node->getLeft());
        cout << node->getChar() << " | ";
    }
    if (node->getRight()){
        cout << node->getChar() << " | ";
        traverse(node->getRight());
    }
    cout << endl;
}
void BST::search(BSTNode* node,char character){
    if (node == NULL){
        return ;
    }
    if (node->getChar() == character){
        cout << node->getMcode() << endl;
        return;
    }
    if (node->getLeft()){
        traverse(node->getLeft());
    }
    if (node->getRight()){
        traverse(node->getRight());
    }
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
BST::~BST(){

}