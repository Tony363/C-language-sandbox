#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <DataAnalysis.h>
using namespace std;

void DataAnalysis::openCSV(){
    this->mCsvStream.open("data.csv");
    if (this->mCsvStream.is_open()){
        cout << "FILE OPENED" << endl;
        readCSV();
    }else{
        cout << "FILE NOT FOUND" << endl;
    }
}
void DataAnalysis::readCSV(){
    // user inOrderTraversal to display tree
    string line,units,type,transaction;
    string* row = NULL;
    while(getline(this->mCsvStream,line)){
        row = lineParser(line,&units,&type,&transaction);
        compareFields(row[2],row[0],row[1]);
    }
    this->mTreePurchased.inOrderTraversal();
    cout << endl;
    this->mTreeSold.inOrderTraversal();
}
string* DataAnalysis::lineParser(string line,string* units,string* type,string* transaction){
    stringstream ss;
    ss << line;
    getline(ss,*units,',');
    getline(ss,*type,',');
    getline(ss,*transaction,',');
    string* row = new string[3];
    row[0] = *units; row[1] = *type; row[2] = *transaction;
    return row;
}
void DataAnalysis::compareFields(string transaction,string unit,string type){
    // compares transaction field and inserts the mUnits
    // and type into the appropriate tree (mTreeSold or mTreePurchased)
    // Trees should be fairly balanced 

    if (transaction.compare("Purchased\r")==0){
        this->mTreePurchased.insert(unit,type);
    } else if (transaction.compare("Sold\r")==0){
        this->mTreeSold.insert(unit,type);
    }
}
void DataAnalysis::seeTrend(){
    cout << "Purchased:\n " 
        << "\tLeast:\n"
        << "\tUnits: "
        << mTreePurchased.findSmallest()->getUnits() << "\n"
        << "\tProduct: "
        << mTreePurchased.findSmallest()->getData() << "\n"
        << "\n\tMost:\n"
        << "\tUnits: "
        << mTreePurchased.findLargest()->getUnits() << "\n"
        << "\tProduct: "
        << mTreePurchased.findLargest()->getData() << "\n"
        << "Sold:\n"
        << "\tLeast:\n"
        << "\tUnits: "
        << mTreeSold.findSmallest()->getUnits() << "\n"
        << "\tProduct: "
        << mTreeSold.findSmallest()->getData() << "\n"
        << "\n\tMost:\n"
        << "\tUnits: "
        << mTreeSold.findLargest()->getUnits() << "\n"
        << "\tProduct: "
        << mTreeSold.findLargest()->getData() << "\n"
        << endl; 
}

void DataAnalysis::runAnalysis(){
    openCSV();
}
void DataAnalysis::results(){
    seeTrend();
}
DataAnalysis::DataAnalysis(){
    this->mTreeSold = BST();
    this->mTreePurchased = BST();
}
DataAnalysis::~DataAnalysis(){
    this->mCsvStream.close();

}


TestBST::TestBST(){
    this->Analysis = new DataAnalysis();
}
TestBST::~TestBST(){
    delete this->Analysis;
}
bool TestBST::TestRunAnalysis(){
    this->Analysis->runAnalysis(); 
    return true;  
}
bool TestBST::TestNode(){
    TransactionNode* test = new TransactionNode("test",10);
    return true;
}
bool TestBST::TestTrend(){
    this->Analysis->results();
    return true;
}
