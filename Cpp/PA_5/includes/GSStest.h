#ifndef GSSTEST_H
#define GSSTEST_H

#include <iostream>
#include <vector>

using namespace std;
   
// If parameter is not true, test fails
// This check function would be provided by the test framework
// #define IS_TRUE(x) {if (!x) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

class GSStesting{
    public:
        GSStesting();
        bool inRange(int randInt,string laneType);
        bool testEnqueue(bool test=true);
        bool testEnqueueWithNodes();
        bool testDequeue(bool test=true);
        void testPrintQueue();
        ~GSStesting();
    private:
};

#endif