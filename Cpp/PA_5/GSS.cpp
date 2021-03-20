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
Data::Data(string lanetype){
    totalTime = 0;
    laneType = lanetype;
}

void Data::getID(int id){
    customerNumber = id;
}

void Data::printData(){
    cout << customerNumber << "\n"
         << laneType << "\n"
         << getRand(laneType) << "\n"
         << endl;
}
// ==============

// QueueNode methods
QueueNode::QueueNode(string laneType){
    Data ofCustomer = Data(laneType);
    ofCustomer.getID(ID);
    ofCustomer.printData();
    pData -> &ofCustomer;
    pNext -> NULL;
}

void QueueNode::getID(int id){
    ID = id;
}

// ==============

// Queue methods
Queue::Queue(string type){
    laneType = type;
}

string Queue::getLaneType(){
    return laneType;
}

QueueNode Queue::addCustomer(){
    QueueNode customer(getLaneType());
    customerNumberinQueue += 1;
    customer.getID(customerNumberinQueue);
    return customer;
}
// ==============

void test_function1(){
    // test random in range generator
    assert(inRange(getRand(true),true) == true);
    assert(inRange(getRand(false),false) == true);
}
