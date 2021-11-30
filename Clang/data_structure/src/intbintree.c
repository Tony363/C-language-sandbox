#include "../includes/bst.h"
#include <stdlib.h>

IntBinTree *createIntBinTree()
{
    IntBinTree *t = (IntBinTree *)malloc(sizeof(IntBinTree));
    return t;
}

IntBinTreeNode *createIntBinTreeNode(int v)
{
    IntBinTreeNode *n = (IntBinTreeNode *)malloc(sizeof(IntBinTreeNode));
    n->value = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

IntBinTreeNode *_buildIntBinTree(FILE *f)
{
    char word[100];
    int v;
    IntBinTreeNode *n;

    if (fscanf("%s", word) != 1)
    {
        return;
    }
    if (word[0] == '@')
    {
        return;
    }
    sscanf(word, "%d", &v);
    n = createIntBinTreeNode(v);
    n->left = _buildIntBuinTree(f);
    n->right = _buildIntBinTree(f);
    return n;
}

void buildIntTree(IntBinTree *t, FILE *f)
{
    t->root = _buildIntBinTree(f);
}

int main(int argc, char **argv)
{
    FILE *in = fopen(argv[1], "r");
    IntBinTree *t;
    t = createIntBinTree();
    printf("root pointer = %p\n", t->root);
    buildIntTree(t, in);
    return 0;
}