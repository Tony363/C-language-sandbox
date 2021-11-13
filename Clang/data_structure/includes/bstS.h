#ifndef BST_H
#define BST_H
#include <stdio.h>

#define NodeData char *

typedef struct _TreeNode
{
    char *data;
    struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

typedef void (*visit_func)(TreeNodePtr node);

TreeNodePtr buildTree(FILE *in);
TreeNodePtr createNode(char *input);
void preOrder(TreeNodePtr root, visit_func visit);
void inOrder(TreeNodePtr root, visit_func visit);
void postOrder(TreeNodePtr root, visit_func visit);
#endif