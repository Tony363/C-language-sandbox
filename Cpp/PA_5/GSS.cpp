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
        return  (1 <= randInt && 5 >= randInt);
    return  (3 <= randInt && 8 >= randInt); 
}

bool GSStesting::testEnqueue(){

    return false;
}

bool GSStesting::testDequeue(){
    
    return false;
}

void GSStesting::testPrintQueue(){

}

GSStesting::~GSStesting(){

}
// ===================

// Data methods
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
    cout << customerNumber << "\n"
         << laneType << "\n"
         << arrivalTime << "\n"
         << endl;
}
Data::~Data(){

}
// ==============

// QueueNode methods
QueueNode::QueueNode(string laneType){
    Data ofCustomer = Data(laneType,ID);
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
Queue::Queue(string type){
    totalTime = 0;
    laneType = type;
}

string Queue::getLaneType(){
    return laneType;
}

void Queue::enqueue(){
    QueueNode customer(getLaneType());
    customerNumberinQueue += 1;
    customer.getID(customerNumberinQueue);
    pTail = pHead;
    QueueNode* nextQueueNode = pHead->getNext();
    nextQueueNode = &customer;
}

void Queue::dequeue(){
    pTail = pTail->getNext();
    
}
void Queue::printQueue(){

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
