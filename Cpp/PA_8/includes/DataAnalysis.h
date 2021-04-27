#ifndef DATAANALYSIS_H
#define DATAANALYSIS_H
#include <iostream>
#include <fstream>
#include <BST.h>
using namespace std;
class DataAnalysis{
    private:
        BST mTreeSold;
        BST mTreePurchased;
        ifstream mCsvStream;
        void openCSV();
        void readCSV();
        string* lineParser(string line,string* units,string* type,string* transaction);
        void compareFields(string transaction,string unit,string type);
        void seeTrend();
        public:
            void runAnalysis();
            void results();
            DataAnalysis();
            ~DataAnalysis();
};
class TestBST{
    private:
        DataAnalysis* Analysis = NULL;
    public:
        TestBST();
        ~TestBST();
        bool TestRunAnalysis();
        bool TestNode();
        bool TestTrend();
};
#endif