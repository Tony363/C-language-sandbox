#ifndef BSTNODE_H
#define BSTNODE_H
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

class BSTNode{
    private:
        BSTNode* left;
        BSTNode* right;
        char ascii;
        string code;
    public:
        BSTNode();
        BSTNode(char character,string Mcode);
        void setChar(char character);
        void setMcode(string Mcode);
        BSTNode* getLeft();
        BSTNode* getRight();
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
        BSTNode* makeEmpty(BSTNode* t);
        BSTNode* insert(char character,string Mcode,BSTNode* t);
        BSTNode* findMin(BSTNode* t);
        BSTNode* findMax(BSTNode* t);
        BSTNode* remove(char character, BSTNode* t);
        BSTNode* find(BSTNode* t, char character);
        BSTNode* getRoot();
        void parseFile(ifstream &file);
        void inorder(BSTNode* t);
        void insert(char character, string Mcode);
        void remove(char character);
        void search(char character);
        void display();
        void setTest();
        ~BST();
};

#endif