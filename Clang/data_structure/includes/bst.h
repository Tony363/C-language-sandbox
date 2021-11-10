#ifndef BST_H
#define BST_H
#include <stdio.h>

typedef struct _NodeData
{
    int data;
    struct _NodeData *left, *right;
} NodeData;

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
void printTree(TreeNodePtr root);
#endif