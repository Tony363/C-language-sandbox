#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
using namespace std;

class BSTNode{
    private:
        char character;
        string Mcode;
        BSTNode* pLeft=NULL;
        BSTNode* pRight=NULL;
    public:
        BSTNode(char text,string code);
        BSTNode* getLeft();
        BSTNode* getRight();
        char getChar();
        string getMcode();
        ~BSTNode(){

        }
};


#endif