#ifndef INTBST_H
#define INTBST_H
#include "bst.h"
typedef Tree IntBST;
typedef TreeNode bstNode;
IntBST *createIntBST();
void addValueIB(IntBST *bst, int value);
void removeValueIB();
#endif
