#ifndef BST_H
#define BST_H
#pragma once
#include <iostream>
using namespace std;
class Node{
    protected:
        string mData;
        Node* mpLeft; 
        Node* mpRight;
        // define a void mutator to assign left right nodes
        
    friend class BST;
    public:
        Node(string data);
        void setLeft(Node* node);
        void setRight(Node* node);
        void setMdata(string data);
        string getData();
        Node*& getLeft();
        Node*& getRight();
        virtual void printData() = 0;
        ~Node();
};

class TransactionNode:public Node{
    protected:
        int mUnits;
    public:
        TransactionNode(string data,int units);
        ~TransactionNode();
        int getUnits();
        void setUnits(int unit);
        void printData();
};

class BST{
    private:
        TransactionNode* mpRoot;
        TransactionNode* pmost;
        TransactionNode* pleast;
        TransactionNode* insert(string units,string type, TransactionNode* root);
        void memoize(TransactionNode* node);
        void inOrderTraversal(TransactionNode* root);
    public:
        BST();
        ~BST();
        void setRoot(TransactionNode* root);
        TransactionNode* getRoot();
        void insert(string units,string type);
        void inOrderTraversal();
        TransactionNode*& findSmallest();
        TransactionNode*& findLargest();
};

#endif