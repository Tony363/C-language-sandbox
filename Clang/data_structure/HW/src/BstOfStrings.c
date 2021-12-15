#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../includes/BstOfStrings.h"

StrBST *createStrBST()
{
    StrBST *bst = (StrBST *)malloc(sizeof(StrBST));
    bst->root = NULL;
    return bst;
}

StrBSTNode *createStrBSTNode(const char *s)
{
    StrBSTNode *n = (StrBSTNode *)malloc(sizeof(StrBSTNode));
    n->s = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(n->s, s);
    n->left = NULL;
    n->right = NULL;
    return n;
}

StrBSTNode *_addValueSB(StrBSTNode *root, StrBSTNode *new)
{
    if (!root)
    {
        root = new;
        return root;
    }
    if (strcmp(new->s, root->s) > 0)
        root->right = _addValueSB(root->right, new);
    else if (strcmp(new->s, root->s) < 0)
        root->left = _addValueSB(root->left, new);
    return root;
}

void addValueSB(StrBST *bst, const char *value)
{
    if (!bst || !value)
        return;
    StrBSTNode *new = createStrBSTNode(value);
    bst->root = _addValueSB(bst->root, new);
}

void value_depth(const char *value, int depth)
{
    printf("%s[%d]\n", value, depth);
}

void _toSortedList(StrBSTNode *node, value_handler handler, int depth)
{
    if (!node)
        return;
    _toSortedList(node->left, handler, depth + 1);
    handler(node->s, depth);
    _toSortedList(node->right, handler, depth + 1);
}

void toSortedList(StrBST *bst, value_handler handler)
{
    if (!bst || !handler)
        return;
    _toSortedList(bst->root, handler, 0);
}

int main(int argc, char **argv)
{
    StrBST *bst = createStrBST();
    addValueSB(bst, "John");
    addValueSB(bst, "Bob");
    addValueSB(bst, "Tom");
    addValueSB(bst, "Alan");
    addValueSB(bst, "Ellen");
    addValueSB(bst, "Karen");
    addValueSB(bst, "Wendy");
    toSortedList(bst, value_depth);
    return 0;
}