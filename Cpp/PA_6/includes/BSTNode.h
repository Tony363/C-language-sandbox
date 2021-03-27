#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class BSTNode{
    // private:
    //     BSTNode* pLeft=NULL;
    //     BSTNode* pRight=NULL;
    public:
        BSTNode* pLeft=NULL;
        BSTNode* pRight=NULL;
        char character=' ';
        string Mcode=" ";
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
        void insert(BSTNode* root,char character,string line);
        void printBST();
        void traverse(BSTNode* root);
        void traverse(char path);
        void search(BSTNode* root,char charcter);
        BSTNode* getRoot();
        ~BST();
};

#endif