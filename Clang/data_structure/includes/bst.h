#ifndef BST_H
#define BST_H
#include <stdio.h>
#define NodeData int
typedef struct _TreeNode
{
    NodeData data;
    struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef void (*visit_func)(TreeNodePtr node);

TreeNode *buildTree(FILE *in);
TreeNode *createNode(int input);
TreeNode *insertNode(TreeNode *root, int inD);
void preOrder(TreeNodePtr root, visit_func visit);
void inOrder(TreeNodePtr root, visit_func visit);
void postOrder(TreeNodePtr root, visit_func visit);
#endif