#ifndef TESTBST_H
#define TESTBST_H
#include <iostream>

using namespace std;

class testBST{
    private:

    public:
        testBST();
        bool testReadFile();
        bool accessTest();
        bool testPrintTree();
        bool testSearch();
        bool testPrintMword();
        ~testBST();
};

class testHash{
    private:
    public:
        testHash();
        bool testReadtoHashMap();
        bool testSearchHashMap();
        bool testRemoveFromHashMap();
        ~testHash();
};

#endif