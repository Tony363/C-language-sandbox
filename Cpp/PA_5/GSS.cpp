#include <GSStest.h>
#include <gss.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <assert.h>

using namespace std;
int getRand(bool laneType);
bool inRange(int randInt,bool laneType);
void test_function1();

int main(void) {
    // Call all tests. Using a test framework would simplify this.
    test_function1();
}

int getRand(string laneType) {
    srand(time(NULL));
    if (laneType == "express")
        return 1 + (rand() % (5 - 1 + 1) );
    return 3 + (rand() % (8 - 3 + 1) );
}

bool inRange(int randInt,bool laneType){
    if (laneType == true)
        return  (1 <= randInt && 5 >= randInt);
    return  (3 <= randInt && 8 >= randInt); 
}

// Data methods
Data::Data(string lanetype,int id){
    laneType = lanetype;
    customerNumber = id;
    arrivalTime = getRand(laneType);
    serviceTime = getRand(laneType);
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
// ==============

// QueueNode methods
QueueNode::QueueNode(string laneType){
    Data ofCustomer = Data(laneType,ID);
    ofCustomer.printData();
    pData = &ofCustomer;
    pNext = NULL;
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
// ==============

// Queue methods
Queue::Queue(string type){
    totalTime = 0;
    laneType = type;
}

string Queue::getLaneType(){
    return laneType;
}

QueueNode Queue::addCustomer(){
    QueueNode customer(getLaneType());
    customerNumberinQueue += 1;
    customer.getID(customerNumberinQueue);
    pHead = &customer;
    return customer;
}

int Queue::getTotalTime(){
    QueueNode *temp = pHead;
    while (temp != NULL){
        totalTime += temp->getData()->getServiceTime();
        temp = temp->getNext();
    };
    return totalTime;
}
// ==============

void test_function1(){
    // test random in range generator
    assert(inRange(getRand(true),true) == true);
    assert(inRange(getRand(false),false) == true);
}
