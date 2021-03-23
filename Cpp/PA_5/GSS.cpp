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
    // cout << customerNumber << endl;
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
    cout << id << endl;
    int tempID = pData->getCustomerID();
    tempID = id;
    cout << tempID << endl;
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
    QueueHeadID = 0;
    customerNumberinQueue = 0;
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
    Data* processed = pHead->getData();
    QueueNode* nextQueueNode = pHead->getNext();
    pHead = nextQueueNode;
    if (!test){
        processed->printData();
    }
    QueueHeadID = pHead->getData()->getCustomerID();
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
