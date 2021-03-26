#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

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
        ~BSTNode();
};

class BST{
    private:
        BSTNode* root=NULL;
    public:
        BST();
        void parseFile(ifstream &file);
        void insert(vector<string> results);
        void printBST();
        void traverse(BSTNode* root);
        void search(BSTNode* root,char charcter);
        ~BST();
};

#endif