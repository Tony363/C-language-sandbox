#include <iostream>
#include <sstream>
#include <assert.h>
// #include </home/pysolver33/Desktop/my_repos/googletest/googletest/include/gtest/gtest.h>
using namespace std;

class Node{
    private:
        
    public:
        Node* pnext;
        int val;
        Node(int value){
            this->val = value;
        }
        int getVal(){
            return this->val;
        }
        Node* getNext(){
            return this->pnext;
        }
        ~Node(){

        }
};

class LinkedList {
    private:
        Node* head;
        Node* latestp;
        int numNodes;
    public:
        LinkedList(){
            this->head = NULL;
            this->latestp = NULL;
            numNodes = 0;
        }
        Node* getHead(){
            return this->head;
        }
        Node* search(int value){
            Node* temp = this->head;
            while(temp!=NULL){
                if (temp->val == value){
                    return temp;
                }
                temp = temp->pnext;
            }
            return NULL;
        }
        void insert(int value){
            Node* newNode = new Node(value);
            if (this->head == NULL){
                this->head = newNode;
                this->latestp = newNode;
            }
            this->latestp->pnext = newNode;
            this->latestp = this->latestp->pnext;
            this->numNodes++;
        }
        void Delete(int value){
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
        void reverse(){
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
        void print(){
            Node* temp = this->head;
            while(temp!=NULL){
                cout << temp->val;
            }
            cout << endl;
        }
        int getNumNodes(){
            return numNodes;
        }
        ~LinkedList(){

        }
};

class testLinkedList{
    private:
        LinkedList test;
    public:
        testLinkedList(){
            for (int i=0;i<10;i++){
                this->test.insert(i);
            }
        }
        bool testInsert(){
            if (this->test.getNumNodes() == 10){
                cout << "Testing Insert: PASSED" << endl;
                return true;
            }
            cout << "Testing Insert: FAILED" << endl;
            return false; 
        }
        bool testDelete(){
            this->test.Delete(10);
            if (this->test.search(10) == NULL){
                cout << "Testing Delete: PASSED" << endl;
                return true;
            }
            cout << "Testing Delete: FAILED" << endl;
            return false;
        }
        bool testSearch(){
            if ((this->test.search(3))->val == 3){
                cout << "Testing Search: PASSED" << endl;
                return true;
            }
            cout << "Testing Search: FAILED" << endl;
            return false;
        }
        bool testReverse(){
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
};

int main(void){
    testLinkedList test;
    assert(test.testInsert()==true);
    assert(test.testSearch()==true);
    assert(test.testReverse()==true);
    assert(test.testDelete()==true);
}   