#ifndef BINARY_TREE_H
#define BINARY_TREE_H


typedef struct _TreeNode
{
	double key;
	struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

int getLevel();
int isInBST(TreeNodePtr root, double key);
void printRoot(TreeNodePtr T);
TreeNodePtr tranverseTree(TreeNodePtr T,TreeNodePtr prev,double key);
TreeNodePtr deleteRoot(TreeNodePtr root,double key);
TreeNodePtr addToBST(TreeNodePtr root, double key);
#endif