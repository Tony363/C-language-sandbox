#ifndef GSS_H  
#define GSS_H

#include <iostream>
#include <vector>

using namespace std;

class Data{
    public://Member functions

    private:
        int customerNumber;// Unique identifier; starts at 1; after 24 hours should be reset to 1
        int serviceTime; // Random time; varies between express and normal lanes; units in minutes
        int totalTime;// totalTime = serviceTime + sum of serviceTime of customers in line before this customer ; units in minutes
}; // This memory needs to be allocated on the heap

class QueueNode{
    public: // Member functions
    private:
        Data *pData; // The memory for Data will need to be allocated on the heap as well
        QueueNode *pNext;
};

class Queue{
    public: // Member functions
    private:
        QueueNode *pHead; 
        QueueNode *pTail;
};

#endif
