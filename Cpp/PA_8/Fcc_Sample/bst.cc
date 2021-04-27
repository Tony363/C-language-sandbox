#include <iostream>

using namespace std;

class TNode {
    public:
	TNode(int v=0) : value(v), left(0), right(0) {}
	~TNode();
	int getValue() { return value; }
	void insert(int v);
	void traverse();
    protected:
	TNode *getLeft() { return this->left; }
	TNode *getRight() { return this->right; }
	void setLeft(TNode *n) { this->left = n; }
	void setRight(TNode *n) { this->right = n; }
	void setValue(int v) { this->value = v; }
    private:
	int value;
	TNode *left = 0;
	TNode *right = 0;
};

TNode::~TNode() {
    if (this->getLeft()!=0) {
	delete this->getLeft();
    }
    if (this->getRight()!=0) {
	delete this->getRight();
    }
}

void TNode::insert(int v) {
    if (v<this->getValue()) {
	if (this->getLeft()==0) {
	    this->setLeft(new TNode(v));
	} else {
	    this->getLeft()->insert(v);
	}
    } else if (v>this->getValue()) {
	if (this->getRight()==0) {
	    this->setRight(new TNode(v));
	} else {
	    this->getRight()->insert(v);
	}
    }
}

void TNode::traverse() {
    if (this->getLeft()!=0) {
	this->getLeft()->traverse();
    }
    cout << this->getValue() << endl;
    if (this->getRight()!=0) {
	this->getRight()->traverse();
    }
}

class BST {
    public:
	BST(): root(0) {}
	~BST();
	void insert(int v);
	void traverse();
    protected:
	TNode *getRoot() { return this->root; }
	void setRoot(TNode *r) { this->root = r; }
    private:
	TNode *root;
};

BST::~BST() {
    if (this->getRoot()!=0) {
	delete this->getRoot();
    }
}

void BST::insert(int v) {
    if (this->getRoot()==0) {
	this->setRoot(new TNode(v));
    } else {
	this->getRoot()->insert(v);
    }
}

void BST::traverse() {
    if (this->getRoot()!=0) {
	this->getRoot()->traverse();
    }
}

int main(int argc, char **argv) {
    BST bst;
    bst.insert(20);
    bst.insert(5);
    bst.insert(4);
    bst.insert(6);
    bst.traverse();
    return 0;
}
