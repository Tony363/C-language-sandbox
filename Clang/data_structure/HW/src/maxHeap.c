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

int _isMaxHeapCBT(CBinTreeNode *root)
{
    printf("%lf\n", getMag(root->value));

    if (!root->left && !root->right)
        return 1;
    if (root->left && root->right && getMag(root->left->value) > getMag(root->value) && getMag(root->right->value) > getMag(root->value))
        return 0;
    if (root->left && getMag(root->value) < getMag(root->left->value))
        return 0;
    if (root->right && getMag(root->value) < getMag(root->right->value))
        return 0;
    return _isMaxHeapCBT(root->left) && _isMaxHeapCBT(root->right);
}

int isMaxHeapCBT(CBinTree *tree)
{

    if (!tree || !tree->root)
        return 0;
    if (!tree->root->left && !tree->root->right)
        return 1;
    return _isMaxHeapCBT(tree->root);
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
        // printf("%lf::%lf\n", Cval->real, Cval->imag);
    }
    n->left = NULL;
    n->right = NULL;
    return n;
}

CBinTreeNode *traversal(CBinTreeNode *root, CBinTreeNode *new)
{
    if (!root)
        return new;
    if (new->value.real == 0 && new->value.imag == 0)
        return NULL;
    root->left = traversal(root->left, new);
    root->right = traversal(root->right, new);
}

CBinTree *buildCBinTree(const char *s)
{
    CBinTree *tree = (CBinTree *)malloc(sizeof(CBinTree));
    tree->root = NULL;
    char word[100];
    int n_chars, offset = 0;
    while (1 == sscanf(s + offset, "%s%n", word, &n_chars))
    {
        // printf("%s\n", word);
        CBinTreeNode *n = createNode(word);
        tree->root = traversal(tree->root, n);
        offset += n_chars;
    }
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
    // printf("%s\n", isMaxHeapCBT(tree) ? "TRUE" : "FALSE");

    // tree = buildCBinTree("3+4i 3 @ @ -4i @ @");
    // printf("%s\n", isMaxHeapCBT(tree) ? "TRUE" : "FALSE");

    // tree = buildCBinTree("3+4i 3 2.1i @ @ 1 @ @ -4i @ @");
    // printf("%s\n", isMaxHeapCBT(tree) ? "TRUE" : "FALSE");

    tree = buildCBinTree("3+4i 3 8.1i @ @ 1 @ @ -4i @ @");
    printf("%s\n", isMaxHeapCBT(tree) ? "TRUE" : "FALSE");
    // print2D(tree->root);

    return 0;
}