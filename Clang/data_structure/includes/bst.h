#ifndef BST_H
#define BST_H
#include <stdio.h>
#define NodeData int

typedef struct _IntBinTreeNode
{
    int value;
    struct _IntBinTreeNode *left, *right;
} IntBinTreeNode;

typedef struct _BinTree
{
    IntBinTreeNode *root;
} IntBinTree;

IntBinTree *createIntBinTree();
void buildIntTree(IntBinTree *t, FILE *f);
//  no need to make public only have programer create tree not create ndoe
// IntBinTreeNode *createIntBinTreeNode(int v);

/*********8*****************************************************/
typedef struct _TreeNode
{
    NodeData data;
    struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef void (*visit_func)(TreeNodePtr node, char type);

TreeNode *createNode(int input);
TreeNode *traverseTree(TreeNode *root, TreeNode *new);
TreeNode *insertNode(TreeNode *root, int inD);
TreeNode *buildTree(FILE *in);

int searchNode(TreeNode *root, int val);
void preOrder(TreeNode *root, visit_func visit);
void inOrder(TreeNode *root, visit_func visit);
void postOrder(TreeNode *root, visit_func visit);
TreeNode *deleteNode(TreeNode *root, int inD);

void freeNode(TreeNode *root);
void print2DUtil(TreeNode *root, int space);
void print2D(TreeNode *root);
#endif