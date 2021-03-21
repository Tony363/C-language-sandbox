#ifndef GSS_H  
#define GSS_H

#include <iostream>
#include <vector>

using namespace std;

class Data{
    public://Member functions
        Data();
        Data(string laneType,int id);
        void printData();
        int getServiceTime();
        int getRand(string laneType);
        ~Data();
    private:
        int customerNumber;// Unique identifier; starts at 1; after 24 hours should be reset to 1
        int serviceTime; // Random time; varies between express and normal lanes; units in minutes
        string laneType;
        int arrivalTime;
}; // This memory needs to be allocated on the heap

class QueueNode{
    public: // Member functions
        QueueNode(string laneType);
        void getID(int id);
        Data* getData();
        QueueNode* getNext();
        ~QueueNode();
    private:
        Data *pData; // The memory for Data will need to be allocated on the heap as well
        QueueNode *pNext;
        int ID;
};

class Queue{
    public: // Member functions
        Queue();
        Queue(string type);
        void enqueue();
        void dequeue();
        void printQueue();
        string getLaneType();
        int getTotalTime();
        QueueNode* getHead();
        QueueNode* getTail();
        ~Queue();
    private:
        QueueNode *pHead=NULL; 
        QueueNode *pTail=NULL;
        string laneType;
        int customerNumberinQueue=0;
        // totalTime = serviceTime + sum of serviceTime of customers in line before this customer ; units in minutes
        int totalTime;
};

#endif
