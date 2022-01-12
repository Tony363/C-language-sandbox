#ifndef MAXHEAP_H
#define MAXHEAP_H

typedef struct _ComplexNum
{
    double real;
    double imag;
} ComplexNum;

typedef struct _CBinTreeNode
{
    ComplexNum value;
    struct _CBinTreeNode *left, *right;
} CBinTreeNode;

typedef struct _CBinTree
{
    CBinTreeNode *root;
} CBinTree;

CBinTree *buildCBinTree(const char *str);
CBinTreeNode *createNode(const char *word);
CBinTreeNode *_buildCBinTree(CBinTreeNode *root, const char *s, int *offset);

int isMaxHeapCBT(CBinTree *tree);
int _isMaxHeapCBT(CBinTreeNode *root, double Rval);

#endif