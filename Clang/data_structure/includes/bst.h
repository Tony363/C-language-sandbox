#ifndef BST_H
#define BST_H
#include <stdio.h>

#define NodeData int

typedef struct _TreeNode
{
    NodeData data;
    struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef struct _BinTree
{
    TreeNode *root;
} Tree;

typedef void (*trav_func)(int value, int depth);

Tree *createIntBinTree();
void buildIntTree(Tree *t, FILE *f);
int getNumNodesIT(Tree *t);
int getNumLeavesIT(Tree *t);
int getHeightIT(Tree *t);
int isFullBinTreeIT(Tree *t);
void preOrderIT(Tree *t, trav_func cb);
void inOrderIT(Tree *t, trav_func cb);
void postOrderIT(Tree *t, trav_func cb);
// adt as public interface and have internal implementation
//  no need to make public only have programer create tree not create ndoe
// IntBinTreeNode *createIntBinTreeNode(int v);

/***************************************************************/

typedef void (*visit_func)(TreeNodePtr node, char type);

TreeNode *createNode(int input);
TreeNode *traverseTree(TreeNode *root, TreeNode *new);
void insertNode(Tree *root, int inD);
Tree *buildTree(FILE *in);

int searchNode(TreeNode *root, int val);
void preOrder(TreeNode *root, visit_func visit);
void inOrder(TreeNode *root, visit_func visit);
void postOrder(TreeNode *root, visit_func visit);
TreeNode *deleteNode(TreeNode *root, int inD);

TreeNode *freeNode(TreeNode *root);
void print2DUtil(TreeNode *root, int space);
void print2D(TreeNode *root);
#endif