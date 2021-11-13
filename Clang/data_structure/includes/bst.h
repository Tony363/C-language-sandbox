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

TreeNodePtr buildTree(FILE *in);
TreeNodePtr createNode(int input);
void preOrder(TreeNodePtr root, visit_func visit);
void inOrder(TreeNodePtr root, visit_func visit);
void postOrder(TreeNodePtr root, visit_func visit);
#endif