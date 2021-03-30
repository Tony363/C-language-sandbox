#include <iostream>

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
    public:
        LinkedList(){
            this->head = NULL;
            this->latestp = NULL;
        }
        void insert(int value){
            Node* newNode = new Node(value);
            if (this->head == NULL){
                this->head = newNode;
                this->latestp = newNode;
            }
            this->latestp->pnext = newNode;
            this->latestp = this->latestp->pnext;
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
            Node* temp = NULL;
            Node* prev = NULL;
            while (this->head != NULL){
                temp = this->head->pnext;
                temp->pnext = prev;
                prev = this->head;
                this->head = temp;
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
        ~LinkedList(){

        }

};