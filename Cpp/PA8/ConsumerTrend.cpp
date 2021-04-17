#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class Node{
    protected:
        string mData;
        Node* mpLeft; 
        Node* mpRight;
    public:
        // Node(){}
        Node(string data){
            this->mpLeft = nullptr;
            this->mpRight = nullptr;
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
        string getData(){
            return this->mData;
        }
        Node**& getLeft(){
            Node** left = &(this->mpLeft);
            return left;
        }
        Node**& getRight(){
            Node** right = &(this->mpRight);
            return right;
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
        void destroyTree(){
            //visit each node in post order to destroy tree
        }
        TransactionNode*& insert(string units,string type, TransactionNode* root){
            // dynamically allocates a TransactionNode and inserts recusively
            // in the correct subtree based on mUnits
            // should pass in a reference to a pointer
            if (root == NULL){
                root = new TransactionNode(type,stoi(units));
                return root;
            }else if(stoi(units) < root->getUnits()){
                *(root->getLeft()) = insert(units,type,(TransactionNode*)root->getLeft());
            }else if (stoi(units) > root->getUnits()){
                *(root->getRight()) = insert(units,type,(TransactionNode*)root->getLeft());
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
                return;
            }
            if (root->getLeft() != nullptr){
                inOrderTraversal((TransactionNode*)root->getLeft());
            }
            cout << root->getUnits() << root->getData() << endl;
            
            if (root->getRight() != nullptr){
                inOrderTraversal((TransactionNode*)root->getRight());
            }
        }
    public:
        BST(){
            this->mpRoot = nullptr;
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
            inOrderTraversal(this->mpRoot);
        }
        TransactionNode*& findSmallest(){
            return ;
        }
        TransactionNode*& findLargest(){
            return ;
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
            string line,units,type,transaction;;
            while(getline(this->mCsvStream,line)){
                string row[3] = {'\0'};
                lineParser(line,&units,&type,&transaction);
                row[0] = units; row[1] = type; row[2] = transaction;
                compareFields(row[2],row[0],row[1]);
            }
            this->mTreePurchased.inOrderTraversal();
            this->mTreeSold.inOrderTraversal();
        }
        void lineParser(string line,string* units,string* type,string* transaction){
            stringstream ss;
            ss << line;
            getline(ss,*units,',');
            getline(ss,*type,',');
            getline(ss,*transaction,',');
        }
        void compareFields(string transaction,string unit,string type){
            // compares transaction field and inserts the mUnits
            // and type into the appropriate tree (mTreeSold or mTreePurchased)
            // Trees should be fairly balanced  
            if (transaction == "Purchased"){
                this->mTreePurchased.insert(unit,type);
            } else if (transaction == "Sold"){
                this->mTreeSold.insert(unit,type);
            }
        }
        void seeTrend(){

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
int main (void){
    return 0;
}