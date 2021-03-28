#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class BSTNode{
    private:
        BSTNode* pLeft;
        BSTNode* pRight;
        BSTNode* parent;
        char character;
        string Mcode;
    public:
        BSTNode();
        BSTNode(char text,string code);
        void setChar(char text);
        void setMcode(string code);
        BSTNode* getLeft();
        BSTNode* getRight();
        BSTNode* getParent();
        char getChar();
        string getMcode();
        ~BSTNode();
};

class BST{
    private:
        BSTNode* root;
        bool test;
    public:
        BST();
        void parseFile(ifstream &file);
        BSTNode* insert(BSTNode* root,char character,string line);
        void printBST();
        void traverse(BSTNode* root);
        void traverse(char path);
        void search(BSTNode* root,char charcter);
        void setTest();
        BSTNode* getRoot();
        ~BST();
};

#endif