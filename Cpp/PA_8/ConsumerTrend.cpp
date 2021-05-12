#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <assert.h>
#include <string.h>
using namespace std;
class TransactionNode;
class Node{
    protected:
        string mData;
        Node* mpLeft; 
        Node* mpRight;
        // define a void mutator to assign left right nodes
        
    // friend class BST;
    public:
        Node(string data):mData(data),mpLeft(nullptr),mpRight(nullptr){}
        void setLeft(Node* node){
            this->mpLeft = node;
        }
        void setRight(Node* node){
            this->mpRight = node;
        }
        void setMdata(string data){
            this->mData = data;
        }
        string getData(){//inline
            return this->mData;
        }
        Node*& getLeft(){
            return this->mpLeft;
        }
        Node*& getRight(){
            return this->mpRight;
        }
        virtual void printData() = 0;
        ~Node(){
            // if (this->mpLeft != nullptr){
                delete this->mpLeft;
            // }
            // if (this->mpRight != nullptr){
                delete this->mpRight;
            // }
            cout << this->mData << endl;
        }
};

class TransactionNode:public Node{
    protected:
        int mUnits;
    public:
        TransactionNode(string data,int units):Node(data){
            this->mUnits = units;
        }
        ~TransactionNode(){}
        int getUnits(){
            int units = this->mUnits;
            return units;
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
        TransactionNode* insert(string units,string type, TransactionNode* root){
            // dynamically allocates a TransactionNode and inserts recusively
            // in the correct subtree based on mUnits
            // should pass in a reference to a pointer
            if (root == NULL){
                int Units = stoi(units);
                root = new TransactionNode(type,Units);
                return root;
            }else if(stoi(units) < root->getUnits()){
                root->setLeft((Node*)insert(units,type,(TransactionNode*)root->getLeft()));
            }else if (stoi(units) > root->getUnits()){
                root->setRight((Node*)insert(units,type,(TransactionNode*)root->getRight()));
            }
            return root;
        }
        void memoize(TransactionNode* node){
            if (node->getUnits() > this->pmost->getUnits()){
                this->pmost = node;
            }
            if (node->getUnits() < this->pleast->getUnits()){
                this->pleast = node;
            }
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
    public:
        BST(){
            this->mpRoot = nullptr;
            this->pmost = new TransactionNode("most",0);
            this->pleast = new TransactionNode("least",0);
        }
        ~BST(){
            delete this->mpRoot;
            // cout << "wtf" << endl;
            // postOrderTraversal(this->mpRoot);
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
                row = lineParser(line,&units,&type,&transaction);
                compareFields(row[2],row[0],row[1]);
            }
            this->mTreePurchased.inOrderTraversal();
            cout << endl;
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
        public:
            void runAnalysis(){
                openCSV();
            }
            void results(){
                seeTrend();
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
        ~TestBST(){
            delete this->Analysis;
        }
        bool TestRunAnalysis(){
            this->Analysis->runAnalysis(); 
            return true;  
        }
        bool TestNode(){
            TransactionNode* test = new TransactionNode("test",10);
            return true;
        }
        bool TestTrend(){
            this->Analysis->results();
            return true;
        }
};

void test_suite(){
    TestBST test;
    assert(test.TestNode()==true);
    assert(test.TestRunAnalysis() == true);
    assert(test.TestTrend()==true);
}
int main (void){
    test_suite();
    return 0;
}