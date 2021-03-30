#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>

using namespace std;
class Node{
    private:
        
    public:
        Node* pnext;
        int val;
        Node(int value);
        int getVal();
        Node* getNext();
        ~Node();
};

class LinkedList {
    private:
        Node* head;
        Node* latestp;
        int numNodes;
    public:
        LinkedList();
        Node* getHead();
        Node* search(int value);
        void insert(int value);
        void Delete(int value);
        void reverse();
        void print();
        int getNumNodes();
        ~LinkedList();
};

class testLinkedList{
    private:
        LinkedList test;
    public:
        testLinkedList();
        bool testInsert();
        bool testDelete();
        bool testSearch();
        bool testReverse();
        ~testLinkedList();
};

#endif