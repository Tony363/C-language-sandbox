#ifndef BST_H
#define BST_H
#include <stdio.h>
#define NodeData int
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