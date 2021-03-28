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
BSTNode::BSTNode(){

}
BSTNode::BSTNode(char text, string code){
    char character = text;
    string Mcode = code;
    // cout << character << Mcode << endl;
}
BSTNode* BSTNode::getLeft(){
    return pLeft;
}
BSTNode* BSTNode::getRight(){
    return pRight;
}
char BSTNode::getChar(){
    return character;
}
string BSTNode::getMcode(){
    return Mcode;
}
BSTNode::~BSTNode(){

}

// =================================================================
// Binary search tree methods
BST::BST(){
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
    BSTNode* temp;
    while(getline(file,line)){
        char character = line[0];
        stringstream ss;
        ss << line;
        getline (ss,Mcode,character);
        getline (ss,Mcode,character);
        if (root == NULL){
            BSTNode* newNode = new BSTNode(character,Mcode);
            root = newNode;
            cout << root << endl;
            continue;
        }
        insert(root,character,Mcode);
    }
    cout << endl;
    // cout << root->getLeft() << " | " << root->getRight() << endl;
}
void BST::insert(BSTNode* nextNode,char text,string line){
    // cout << nextNode->pLeft << nextNode->pRight << endl;
    if (nextNode == NULL){
        BSTNode* newNode = new BSTNode(text,line);
        nextNode = newNode;
        if (test == "true"){
            cout << nextNode << " | "  << nextNode->getChar() << " | " << nextNode->getMcode() << endl;
        }
        return ;
    }
    // cout << nextNode << endl;
    // cout << nextNode->character << (int)nextNode->character << endl;
    // cout << (int)text << " | " << (int)nextNode->character << endl;
    if (((int)text) < ((int)(nextNode->getChar()))){
        BSTNode* left = nextNode->getLeft();
        if (test == "true"){
            cout << "left " 
                << (int)text 
                << " | " 
                << (int)(nextNode->getChar()) 
                << "\n" 
                << endl; 
        }else{
            cout << "left::";
        }
        insert(left,text,line);
    }
    if (((int)text) > ((int)(nextNode->getChar()))){
        BSTNode* right = nextNode->getRight();
        if (test == "true"){
            cout << "right " 
                << (int)text 
                << " | " 
                << (int)(nextNode->getChar()) 
                << "\n" 
                << endl; 
        }else{
            cout << "right::";
        }
        insert(right,text,line);
    }
}

void BST::printBST(){
    BSTNode* leftNode = root->getLeft();
    BSTNode* rightNode = root->getRight();
    traverse(leftNode);
    traverse(rightNode);
}
void BST::traverse(BSTNode* root){
    if (root == NULL){
        return ;
    }
    if (root->getLeft()){
        cout << root->getChar() << " | ";
        traverse(root->getLeft());
    }
    if (root->getRight()){
        cout << root->getChar() << " | ";
        traverse(root->getRight());
    }
    cout << endl;
}
void BST::search(BSTNode* root,char character){
    if (root == NULL){
        return ;
    }
    if (root->getChar() == character){
        cout << root->getMcode() << endl;
        return;
    }
    if (root->getLeft()){
        traverse(root->getLeft());
    }
    if (root->getRight()){
        traverse(root->getRight());
    }
}
void BST::setTest(){
    test="true";
    cout << test << endl;
}
BSTNode* BST::getRoot(){
    return root;
}
BST::~BST(){

}