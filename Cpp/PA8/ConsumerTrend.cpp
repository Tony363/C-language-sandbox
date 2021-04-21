#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <assert.h>
#include <string.h>
using namespace std;

class Node{
    protected:
        string mData;
        void* mpLeft; 
        void* mpRight;
    public:
        // Node(){}
        Node(string data){
            this->mpLeft = nullptr;
            this->mpRight = nullptr;
            this->mData = data;
        }
        void setMdata(string data){
            this->mData = data;
        }
        void setLeft(Node* node){
            this->mpLeft = node;
        }
        void setRight(Node* node){
            this->mpRight = node;
        }
        string getData(){//inline
            return this->mData;
        }
        void*& getLeft(){
            return this->mpLeft;
        }
        void*& getRight(){
            return this->mpRight;
        }
        virtual void printData() = 0;
        ~Node(){}
};

class TransactionNode:public Node{
    protected:
        int mUnits;
    public:
        // TransactionNode(){}
        TransactionNode(string data,int units):Node(data){
            this->mUnits = units;
        }
        ~TransactionNode(){}
        int getUnits(){
            return this->mUnits;
        }
        void setUnits(int unit){
            this->mUnits = unit;
        }
        void printData(){
            cout << this->getUnits() << " : "
                << this->getData()
                << endl;
        }
};

class BST{
    private:
        TransactionNode* mpRoot;
        TransactionNode* pmost;
        TransactionNode* pleast;
        void destroyTree(){
            //visit each node in post order to destroy tree
        }
        TransactionNode* insert(string units,string type, TransactionNode* root){
            // dynamically allocates a TransactionNode and inserts recusively
            // in the correct subtree based on mUnits
            // should pass in a reference to a pointer
            if (root == NULL){
                int Units = stoi(units);
                root = new TransactionNode(type,Units);
                return root;
            }else if(stoi(units) < root->getUnits()){
                TransactionNode* left = (TransactionNode*)root->getLeft();
                left = insert(units,type,left);
            }else if (stoi(units) > root->getUnits()){
                TransactionNode* right = (TransactionNode*)root->getRight();
                right = insert(units,type,right);
            }
            return root;
            // inOrderTraversal(units,type,root);
        }
        void inOrderTraversal(TransactionNode* root){
            // recursively visits and prints the contents
            // (mData and mUnits) of each node in the tree in order
            // each node's printData should be called
            // contents should be printed on a separate line
            if (root == nullptr){
                return;// may not be necessary
            }
            if (root->getLeft() != nullptr){
                inOrderTraversal((TransactionNode*)root->getLeft());
            }
            memoize(root);
            root->printData();
            if (root->getRight() != nullptr){
                inOrderTraversal((TransactionNode*)root->getRight());
            }
            return;
        }
        void memoize(TransactionNode* node){
            if (node->getUnits() > this->pmost->getUnits()){
                this->pmost = node;
            }
            if (node->getUnits() < this->pleast->getUnits()){
                this->pleast = node;
            }
        }
    public:
        BST(){
            this->mpRoot = nullptr;
            this->pmost = nullptr;
            this->pleast = nullptr;
        }
        ~BST(){
            destroyTree();
        }
        void setRoot(TransactionNode* root){
            this->mpRoot = root;
        }
        TransactionNode* getRoot(){
            return this->mpRoot;
        }
        void insert(string units,string type){
            //public used to hide pointer information
            this->mpRoot = insert(units,type,this->mpRoot);
        }
        void inOrderTraversal(){
            //public used to hide pointer information
            if (this->mpRoot == nullptr){
                return;
            }
            inOrderTraversal((TransactionNode*)(this->mpRoot->getLeft()));
            this->mpRoot->printData();
            inOrderTraversal((TransactionNode*)(this->mpRoot->getRight()));
        }
        TransactionNode*& findSmallest(){
            return this->pleast;
        }
        TransactionNode*& findLargest(){
            return this->pmost;
        }
};

class DataAnalysis{
    private:
        BST mTreeSold;
        BST mTreePurchased;
        ifstream mCsvStream;
        void openCSV(){
            this->mCsvStream.open("data.csv");
            if (this->mCsvStream.is_open()){
                cout << "FILE OPENED" << endl;
                readCSV();
            }else{
                cout << "FILE NOT FOUND" << endl;
            }
        }
        void readCSV(){
            // user inOrderTraversal to display tree
            string line,units,type,transaction;
            string* row = NULL;
            while(getline(this->mCsvStream,line)){
                row = lineParser(line,&units,&type,&transaction);// <- FIX ME
                compareFields(row[2],row[0],row[1]);
            }
            this->mTreePurchased.inOrderTraversal();
            this->mTreeSold.inOrderTraversal();
        }
        string* lineParser(string line,string* units,string* type,string* transaction){
            stringstream ss;
            ss << line;
            getline(ss,*units,',');
            getline(ss,*type,',');
            getline(ss,*transaction,',');
            string* row = new string[3];
            row[0] = *units; row[1] = *type; row[2] = *transaction;
            return row;
        }
        void compareFields(string transaction,string unit,string type){
            // compares transaction field and inserts the mUnits
            // and type into the appropriate tree (mTreeSold or mTreePurchased)
            // Trees should be fairly balanced 

            if (transaction.compare("Purchased\r")==0){
                this->mTreePurchased.insert(unit,type);
            } else if (transaction.compare("Sold\r")==0){
                this->mTreeSold.insert(unit,type);
            }
        }
        void seeTrend(){
            cout << mTreePurchased.findSmallest()->getUnits() 
                << mTreePurchased.findSmallest()->getData()
                << mTreeSold.findSmallest()->getUnits()
                << mTreeSold.findLargest()->getData()
                << endl; 
        }
        public:
            void runAnalysis(){
                openCSV();
            }
            DataAnalysis(){
                this->mTreeSold = BST();
                this->mTreePurchased = BST();
            }
            ~DataAnalysis(){
                this->mCsvStream.close();
            }
};
class TestBST{
    private:
        DataAnalysis* Analysis = NULL;
    public:
        
        TestBST(){
            this->Analysis = new DataAnalysis();
        }
        ~TestBST(){}
        bool TestRunAnalysis(){
            this->Analysis->runAnalysis(); 
            return true;  
        }
};

void test_suite(){
    TestBST test;
    assert(test.TestRunAnalysis() == true);
}
int main (void){
    test_suite();
    return 0;
}