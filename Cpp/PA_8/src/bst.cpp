#pragma once
#include <iostream>
#include <string>
#include <BST.h>

Node::Node(string data):mData(data),mpLeft(nullptr),mpRight(nullptr){}
void Node::setLeft(Node* node){
    this->mpLeft = node;
}
void Node::setRight(Node* node){
    this->mpRight = node;
}
void Node::setMdata(string data){
    this->mData = data;
}
string Node::getData(){//inline
    return this->mData;
}
Node*& Node::getLeft(){
    return this->mpLeft;
}
Node*& Node::getRight(){
    return this->mpRight;
}
Node::~Node(){
    delete this->mpLeft;
    delete this->mpRight;
    cout << this->mData << endl;
}


TransactionNode::TransactionNode(string data,int units):Node(data){
    this->mUnits = units;
}

TransactionNode::~TransactionNode(){}

int TransactionNode::getUnits(){
    int units = this->mUnits;
    return units;
}
void TransactionNode::setUnits(int unit){
    this->mUnits = unit;
}
void TransactionNode::printData(){
    cout << this->getUnits() << " : "
        << this->getData()
        << endl;
}

TransactionNode* BST::insert(string units,string type, TransactionNode* root){
    // dynamically allocates a TransactionNode and inserts recusively
    // in the correct subtree based on mUnits
    // should pass in a reference to a pointer
    if (root == NULL){
        int Units = stoi(units);
        root = new TransactionNode(type,Units);
        return root;
    }else if(stoi(units) < root->getUnits()){
        root->setLeft((Node*)insert(units,type,(TransactionNode*)root->getLeft()));
    }else if (stoi(units) > root->getUnits()){
        root->setRight((Node*)insert(units,type,(TransactionNode*)root->getRight()));
    }
    return root;
}
void BST::memoize(TransactionNode* node){
    if (node->getUnits() > this->pmost->getUnits()){
        this->pmost = node;
    }
    if (node->getUnits() < this->pleast->getUnits()){
        this->pleast = node;
    }
}
void BST::inOrderTraversal(TransactionNode* root){
    // recursively visits and prints the contents
    // (mData and mUnits) of each node in the tree in order
    // each node's printData should be called
    // contents should be printed on a separate line
    if (root == nullptr){
        return;// may not be necessary
    }
    if (root->getLeft() != nullptr){
        inOrderTraversal((TransactionNode*)root->getLeft());
    }
    memoize(root);
    root->printData();
    if (root->getRight() != nullptr){
        inOrderTraversal((TransactionNode*)root->getRight());
    }
    return;
}

BST::BST(){
    this->mpRoot = nullptr;
    this->pmost = new TransactionNode("most",0);
    this->pleast = new TransactionNode("least",0);
}
BST::~BST(){
    delete this->mpRoot;
}
void BST::setRoot(TransactionNode* root){
    this->mpRoot = root;
}
TransactionNode* BST::getRoot(){
    return this->mpRoot;
}
void BST::insert(string units,string type){
    //public used to hide pointer information
    this->mpRoot = insert(units,type,this->mpRoot);
}
void BST::inOrderTraversal(){
    //public used to hide pointer information
    if (this->mpRoot == nullptr){
        return;
    }
    inOrderTraversal((TransactionNode*)(this->mpRoot->getLeft()));
    this->mpRoot->printData();
    inOrderTraversal((TransactionNode*)(this->mpRoot->getRight()));
}
TransactionNode*& BST::findSmallest(){
    return this->pleast;
}
TransactionNode*& BST::findLargest(){
    return this->pmost;
}
