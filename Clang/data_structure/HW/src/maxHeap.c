#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../includes/maxHeap.h"
#define COUNT 5

double getMag(ComplexNum val)
{
    return (val.real * val.real) + (val.imag * val.imag);
}

int _isMaxHeapCBT(CBinTreeNode *root, double Rval)
{
    return !root || !(getMag(root->value) > Rval) && _isMaxHeapCBT(root->left, Rval) && _isMaxHeapCBT(root->right, Rval);
}

int isMaxHeapCBT(CBinTree *tree)
{
    return (!tree->root->left && !tree->root->right) || tree && tree->root && _isMaxHeapCBT(tree->root, getMag(tree->root->value));
}

CBinTreeNode *createNode(const char *word)
{
    CBinTreeNode *n = (CBinTreeNode *)malloc(sizeof(CBinTreeNode));
    ComplexNum *Cval = (ComplexNum *)malloc(sizeof(ComplexNum));
    Cval->real = 0;
    Cval->imag = 0;
    int wordOffset = 0, w_chars;
    double val;
    while (1 == sscanf(word + wordOffset, "%lf%n", &val, &w_chars))
    {
        wordOffset += w_chars;
        if (Cval->real)
            Cval->imag = val;
        else
            Cval->real = val;
    }
    n->left = NULL;
    n->right = NULL;
    n->value = *Cval;
    return n;
}

CBinTreeNode *_buildCBinTree(CBinTreeNode *root, const char *s, int *offset)
{
    char word[10];
    int n_chars;
    if (sscanf(s + *offset, "%s%n", word, &n_chars))
        *offset += n_chars;
    else
        return NULL;
    if (word[0] == '@')
        return NULL;

    root = createNode(word);
    root->left = _buildCBinTree(root->left, s, offset);
    root->right = _buildCBinTree(root->right, s, offset);
    return root;
}

CBinTree *buildCBinTree(const char *s)
{
    int n_chars, offset = 0;
    CBinTree *tree = (CBinTree *)malloc(sizeof(CBinTree));
    tree->root = _buildCBinTree(tree->root, s, &offset);
    return tree;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(CBinTreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%lf\n", getMag(root->value));

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(CBinTreeNode *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main(int argc, char **argv)
{
    CBinTree *tree;
    // tree = buildCBinTree("5+3i @ @");

    // tree = buildCBinTree("3+4i 3 @ @ -4i @ @");

    tree = buildCBinTree("3+4i 3 2.1i @ @ 1 @ @ -4i @ @");

    // tree = buildCBinTree("3+4i 3 8.1i @ @ 1 @ @ -4i @ @");
    printf("%s\n", isMaxHeapCBT(tree) ? "TRUE" : "FALSE");
    print2D(tree->root);

    return 0;
}