#include <iostream>
#include <sstream>
#include <assert.h>
#include <linkList.h>
// #include </home/pysolver33/Desktop/my_repos/googletest/googletest/include/gtest/gtest.h>
using namespace std;


Node::Node(int value){
    this->val = value;
}
int Node::getVal(){
    return this->val;
}
Node* Node::getNext(){
    return this->pnext;
}
Node::~Node(){

}


LinkedList::LinkedList(){
    this->head = NULL;
    this->latestp = NULL;
    numNodes = 0;
}
Node* LinkedList::getHead(){
    return this->head;
}
Node* LinkedList::search(int value){
    Node* temp = this->head;
    while(temp!=NULL){
        if (temp->val == value){
            return temp;
        }
        temp = temp->pnext;
    }
    return NULL;
}
void LinkedList::insert(int value){
    Node* newNode = new Node(value);
    if (this->head == NULL){
        this->head = newNode;
        this->latestp = newNode;
    }
    this->latestp->pnext = newNode;
    this->latestp = this->latestp->pnext;
    this->numNodes++;
}
void LinkedList::Delete(int value){
    Node* temp = this->head;
    Node* prev = NULL;
    while(temp!=NULL){
        if (temp->val == value){
            prev -> pnext = temp-> pnext;
            delete temp;
            break;
        }else if (temp->val == value && prev == NULL){
            prev = temp;
            temp = temp-> pnext;
            delete prev;
            break;
        }
        prev = temp;
        temp = temp->pnext;
    }
}
void LinkedList::reverse(){
    Node* temp;
    Node* prev = NULL;
    while (head != NULL){
        temp = head->pnext;
        head->pnext = prev;
        prev = head;
        head = temp;
    }
    this->head = prev;
}
void LinkedList::print(){
    Node* temp = this->head;
    while(temp!=NULL){
        cout << temp->val;
    }
    cout << endl;
}
int LinkedList::getNumNodes(){
    return numNodes;
}
LinkedList::~LinkedList(){

}



testLinkedList::testLinkedList(){
    for (int i=0;i<10;i++){
        this->test.insert(i);
    }
}
bool testLinkedList::testInsert(){
    if (this->test.getNumNodes() == 10){
        cout << "Testing Insert: PASSED" << endl;
        return true;
    }
    cout << "Testing Insert: FAILED" << endl;
    return false; 
}
bool testLinkedList::testDelete(){
    this->test.Delete(10);
    if (this->test.search(10) == NULL){
        cout << "Testing Delete: PASSED" << endl;
        return true;
    }
    cout << "Testing Delete: FAILED" << endl;
    return false;
}
bool testLinkedList::testSearch(){
    if ((this->test.search(3))->val == 3){
        cout << "Testing Search: PASSED" << endl;
        return true;
    }
    cout << "Testing Search: FAILED" << endl;
    return false;
}
bool testLinkedList::testReverse(){
    this->test.reverse();
    string out = "";
    Node* temp = test.getHead();
    while (temp!=NULL){
        stringstream s;
        s << temp->val;
        out += s.str();
        temp = temp->pnext;
    }
    if (out == "9876543210"){
        cout << "Testing reverse LinkedList: PASSED" << endl;
        return true;
    }
    cout << "Testing reverse LinkedList: FAILED" << endl;
    return false;
}
testLinkedList::~testLinkedList(){
    
}

int main(void){
    testLinkedList test;
    assert(test.testInsert()==true);
    assert(test.testSearch()==true);
    assert(test.testReverse()==true);
    assert(test.testDelete()==true);
}   