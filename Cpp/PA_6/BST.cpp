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
BSTNode::BSTNode(char text, string code){
    char character = text;
    string Mcode = code;
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
    string line;
    while(getline(file,line)){
        // cout << line << endl;
        istringstream iss(line);
        vector<string> results(istream_iterator<string>{iss},istream_iterator<string>());
        insert(results);
        // cout << "wtf" << endl;
    }
    cout << "FUCK" << endl;
}
void BST::insert(vector<string>results){
    BSTNode* temp = root;
    BSTNode* prev = root;
    vector<string>::const_iterator itv;
    itv = results.begin()++;
    char character = results.front()[0];
    while (itv != results.end()){
        if (*itv == "-"){
            temp = temp->getRight();
        }else if (*itv == "."){
            temp = temp->getLeft();
        }
        if (temp == NULL || (*itv != "." && *itv!= "-")){
            string code = accumulate(results.begin()++,results.end(),string(""));
            BSTNode newNode(character,code);
            temp = &newNode;
            // cout << character << endl;
        }
        itv ++;
    }
    // cout << character << endl;
    // cout << "FUCK!!!"<< endl;
}
void BST::printBST(){
    BSTNode* leftNode = root->getLeft();
    BSTNode* rightNode = root->getRight();
    cout << "wtf"<< endl;
    // cout << leftNode << endl;
    // cout << rightNode << endl;
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
    }
    if (root->getLeft()){
        traverse(root->getLeft());
    }
    if (root->getRight()){
        traverse(root->getRight());
    }
}
BSTNode* BST::getRoot(){
    return root;
}
BST::~BST(){

}