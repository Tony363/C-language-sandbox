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
BSTNode::BSTNode(char text,string code){
    character = text;
    Mcode = code;
}
void BSTNode::setChar(char text){
    character = text;
}
void BSTNode::setMcode(string code){
    Mcode = code;
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
    setTest();
    root=NULL;
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
        if (root == NULL){
            BSTNode* newNode = new BSTNode(character,Mcode);
            // newNode->setChar(character);
            // newNode->setMcode(Mcode);
            root = newNode;
            // cout << root << endl;
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
        // newNode->setChar(text);
        // newNode->setMcode(line);
        nextNode = newNode;
        if (!test){
            cout << nextNode << " | "  << nextNode->getChar() << " | " << nextNode->getMcode() << endl;
        }
        return ;
    }
    // cout << nextNode << endl;
    // cout << nextNode->character << (int)nextNode->character << endl;
    // cout << (int)text << " | " << (int)nextNode->character << endl;
    if (((int)text) < ((int)(nextNode->getChar()))){
        BSTNode* left = nextNode->getLeft();
        if (!test){
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
    string boolean;
    cout << "test or not test: ";
    cin >> boolean;
    test = (boolean=="true")?false:true;
}
BSTNode* BST::getRoot(){
    return root;
}
BST::~BST(){

}