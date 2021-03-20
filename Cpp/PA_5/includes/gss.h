#ifndef GSS_H  
#define GSS_H

#include <iostream>
#include <vector>

using namespace std;

class Data{
    public://Member functions
        Data();
        void setCustomerID();
        void Data::printData();
        ~Data();
    private:
        int customerNumber;// Unique identifier; starts at 1; after 24 hours should be reset to 1
        int serviceTime; // Random time; varies between express and normal lanes; units in minutes
        int totalTime;// totalTime = serviceTime + sum of serviceTime of customers in line before this customer ; units in minutes
        string laneType;
}; // This memory needs to be allocated on the heap

class QueueNode{
    public: // Member functions
        QueueNode(string laneType);
        void QueueNode::getID(int id)
        ~QueueNode();
    private:
        Data *pData; // The memory for Data will need to be allocated on the heap as well
        QueueNode *pNext;
        int ID;
};

class Queue{
    public: // Member functions
        Queue(string type);
        QueueNode addCustomer();
        string getLaneType();
        ~Queue();
    private:
        QueueNode *pHead; 
        QueueNode *pTail;
        string laneType;
        int customerNumber=0;
};

#endif
