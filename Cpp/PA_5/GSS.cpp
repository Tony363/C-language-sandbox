#include <GSStest.h>
#include <gss.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// unit testing methods
GSStesting::GSStesting(){

}

bool GSStesting::inRange(int randInt,string laneType){
    if (laneType == "express")
        cout << "[inRange] test PASSED" << endl;
        return  (1 <= randInt && 5 >= randInt);
    cout << "[inRange] test FAILED" << endl;
    return  (3 <= randInt && 8 >= randInt); 
}

bool GSStesting::testEnqueue(bool test=true){
    Queue express("express"),normal("normal");
    express.enqueue(test);normal.enqueue(test);
    if (express.getTail() != NULL && normal.getTail() != NULL)
        cout << "[testEnqueue] test PASSED" << endl;
        return true;
    cout << "[testEnqueue] test FAILED" << endl;
    return false;
}
bool GSStesting::testEnqueueWithNodes(){
    bool test = true;
    Queue express("express"),normal("normal");
    express.enqueue(test);normal.enqueue(test);
    express.enqueue(test);normal.enqueue(test);
    if (express.getTail() != NULL && normal.getTail() != NULL)
        cout << "[testEnqueueWithNodes] test PASSED" << endl;
        return true;
    cout << "[testEnqueueWithNodes] test FAILED" << endl;
    return false;  
}

bool GSStesting::testDequeue(){
    bool test = true;
    Queue express("express"),normal("normal");
    express.enqueue(test);normal.enqueue(test);
    express.dequeue();normal.dequeue();
    // cout << "wtf" << endl;
    if (express.getTail()==NULL && normal.getTail()==NULL){
        cout << "[testDequeue] test PASSED" << endl;
        return true;
    }
    cout << "wtf" << endl;
    cout << "[testDequeue] test FAILED" << endl;
    return false;
}

void GSStesting::testPrintQueue(){

}

GSStesting::~GSStesting(){

}
// ===================

// Data methods

Data::Data(){

}

Data::Data(string lanetype,int id){
    laneType = lanetype;
    customerNumber = id;
    arrivalTime = getRand(laneType);
    serviceTime = getRand(laneType);
}

int Data::getRand(string laneType) {
    srand(time(NULL));
    if (laneType == "express")
        return 1 + (rand() % (5 - 1 + 1) );
    return 3 + (rand() % (8 - 3 + 1) );
}

int Data::getServiceTime(){
    return serviceTime;
}
void Data::printData(){
    cout << "Customer ID: " << customerNumber << "\n"
         << "Lane Type: " << laneType << "\n"
         << "Time to arrive: " << arrivalTime << "\n"
         << endl;
}
Data::~Data(){

}
// ==============

// QueueNode methods
QueueNode::QueueNode(string laneType,bool test){
    Data ofCustomer = Data(laneType,ID);
    if (!test)
        ofCustomer.printData();
    pData = &ofCustomer;
}

void QueueNode::getID(int id){
    ID = id;
}

Data* QueueNode::getData(){
    return pData;
}
QueueNode* QueueNode::getNext(){
    return pNext;
}

QueueNode::~QueueNode(){

}
// ==============

// Queue methods
Queue::Queue(){

}
Queue::Queue(string type){
    totalTime = 0;
    laneType = type;
}

string Queue::getLaneType(){
    return laneType;
}

QueueNode* Queue::getHead(){
    return pHead;
}

QueueNode* Queue::getTail(){
    return pTail;
}

void Queue::enqueue(bool test){

    QueueNode customer(getLaneType(),test);
    if (test){
        cout << "[" << getLaneType() << "] testing..." << endl;
        QueueNode customer(getLaneType(),test);
        customerNumberinQueue += 1;
        customer.getID(customerNumberinQueue);
    } else{
        QueueNode customer(getLaneType());
        customerNumberinQueue += 1;
        customer.getID(customerNumberinQueue);
    }
    
    if (customerNumberinQueue == 1)
        pTail = &customer;
        pHead = &customer;
        return ;

    QueueNode* nextQueueNode = pTail->getNext();
    nextQueueNode = &customer;
    pTail = nextQueueNode;
}

void Queue::dequeue(){
    QueueNode* nextQueueNode = pHead->getNext();
    pHead = nextQueueNode;
}

void Queue::printQueue(){
    QueueNode* temp = pTail;
    while(temp != NULL){
        temp->getData()->printData();
        temp = temp->getNext();
    }
}

int Queue::getTotalTime(){
    QueueNode *temp = pHead;
    while (temp != NULL){
        totalTime += temp->getData()->getServiceTime();
        temp = temp->getNext();
    };
    return totalTime;
}

Queue::~Queue(){

}
// ==============
