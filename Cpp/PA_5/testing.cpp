#include <GSStest.h>
#include <gss.h>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

void test_function1();

int main(void) {
    // Call all tests. Using a test framework would simplify this.
    test_function1();
}

// unit testing methods
GSStesting::GSStesting(){

}

bool GSStesting::inRange(int randInt,string laneType){
    cout << "[inRange] " << laneType << " test"  << endl;
    if (laneType == "express"){
        return  (1 <= randInt && 5 >= randInt);
    }else {
        return  (3 <= randInt && 8 >= randInt); 
    }
    cout << "[inRange] test FAILED\n" << endl;
}

bool GSStesting::testEnqueue(bool test){
    cout << "[testEnqueue] test" << endl;
    Queue express("express"),normal("normal");
    express.enqueue(test);normal.enqueue(test);
    if (express.getTail() != NULL && normal.getTail() != NULL){
        cout << "[testEnqueue] test PASSED\n" << endl;
        return true;
    }
    cout << "[testEnqueue] test FAILED\n" << endl;
    return false;
}
bool GSStesting::testEnqueueWithNodes(){
    bool test = true;
    cout << "[testEnqueueWithNodes] test" << endl;
    Queue express("express"),normal("normal");
    express.enqueue(test);normal.enqueue(test);
    express.enqueue(test);normal.enqueue(test);
    if (express.getTail() != NULL && normal.getTail() != NULL){
        cout << "[testEnqueueWithNodes] test PASSED\n" << endl;
        return true;
    }
    cout << "[testEnqueueWithNodes] test FAILED\n" << endl;
    return false;  
}

bool GSStesting::testDequeue(bool test){
    Queue express("express"),normal("normal");
    cout << "[testDequeue] test" << endl;
    express.enqueue(test);normal.enqueue(test);
    int ExpressID = express.dequeue(test);
    int NormalID = normal.dequeue(test);
    if (express.getQueueHeadID()==ExpressID&& normal.getQueueHeadID()==NormalID){
        cout << "[testDequeue] test PASSED\n" << endl;
        return true;
    }
    cout << "[testDequeue] test FAILED\n" << endl;
    return false;
}

bool GSStesting::testDequeueWithNodes(bool test){
    Queue express("express"),normal("normal");
    cout << "[testDequeueWithNode] test" << endl;
    express.enqueue(test);normal.enqueue(test);
    express.enqueue(test);normal.enqueue(test);
    int ExpressID = express.dequeue(test);
    int NormalID = normal.dequeue(test);
    if (express.getQueueHeadID()==ExpressID&& normal.getQueueHeadID()==NormalID){
        cout << "[testDequeueWithNode] test PASSED\n" << endl;
        return true;
    }
    cout << "[testDequeueWithNode] test FAILED\n" << endl;
    return false;
}

void GSStesting::testPrintQueue(){

}

GSStesting::~GSStesting(){

}

void test_function1(){
    // test random in range generator
    GSStesting test; Data dtest;
    assert(test.testEnqueue(true)==true);
    assert(test.testEnqueueWithNodes()==true);
    assert(test.testDequeue()==true);
    assert(test.testDequeueWithNodes()==true);
    assert(test.inRange(dtest.getRand("express"),"express") == true);
    assert(test.inRange(dtest.getRand("normal"),"normal") == true);
}