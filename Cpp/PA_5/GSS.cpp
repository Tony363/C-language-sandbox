#include <GSStest.h>
#include <gss.h>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

// ===================

// Data methods

Data::Data(){

}

Data::Data(string lanetype){
    laneType = lanetype;
    customerNumber = 0;
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

int Data::getCustomerID(){
    return customerNumber;
}

void Data::setCustomerID(int id){
    customerNumber = id;
}

Data::~Data(){

}
// ==============

// QueueNode methods
QueueNode::QueueNode(string laneType,bool test){
    Data ofCustomer = Data(laneType);
    if (!test)
        ofCustomer.printData();
    pData = &ofCustomer;
}

void QueueNode::passinID(int id){
    // cout << id << endl;
    pData->setCustomerID(id);
    // cout << pData->getCustomerID() << endl;
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
    totalTime = 0;
    QueueHeadID = 0;
    customerNumberinQueue = 0;
    laneType = "NONE";
}
Queue::Queue(string type){
    totalTime = 0;
    laneType = type;
    customerNumberinQueue = 0;
    QueueHeadID = 0;
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
    }
    customerNumberinQueue += 1;
    customer.passinID(customerNumberinQueue);
    if (customerNumberinQueue == 1){
        pTail = &customer;
        pHead = &customer;
        QueueHeadID = customer.getData()->getCustomerID();
        // cout << QueueHeadID << endl;
        return ;
    }
    QueueNode* nextQueueNode = pTail->getNext();
    nextQueueNode = &customer;
    pTail = nextQueueNode;
}

int Queue::dequeue(bool test){
    // cout might fuck up the pHead address
    Data* processed = pHead->getData();
    QueueNode* nextQueueNode = pHead->getNext();
    pHead = nextQueueNode;
    if (!test){
        processed->printData();
    }
    QueueHeadID = processed->getCustomerID();
    return processed->getCustomerID();
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

int Queue::getQueueHeadID(){
    return QueueHeadID;
}

Queue::~Queue(){

}
// ==============
