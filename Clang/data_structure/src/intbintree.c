#include "../includes/bst.h"
#include <stdlib.h>

void print_node(int value, int depth)
{
    printf("%d(depth: %d) ", value, depth);
}

Tree *createIntBinTree()
{
    Tree *t = (Tree *)malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

TreeNode *createIntBinTreeNode(int v)
{
    TreeNode *n = (TreeNode *)malloc(sizeof(TreeNode));
    n->data = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}

TreeNode *_buildIntBinTree(FILE *f)
{
    char word[100];
    int v;
    TreeNode *n;

    if (fscanf(f, "%s", word) != 1)
    {
        return NULL;
    }
    if (word[0] == '@')
    {
        return NULL;
    }
    sscanf(word, "%d", &v);
    n = createIntBinTreeNode(v);
    n->left = _buildIntBinTree(f);
    n->right = _buildIntBinTree(f);
    return n;
}

void buildIntTree(Tree *t, FILE *f)
{
    t->root = _buildIntBinTree(f);
}

int _getNumLeavesIT(TreeNode *n)
{
    if (n == NULL)
        return 0;
    if (n->left || n->right)
        return _getNumLeavesIT(n->left) + _getNumLeavesIT(n->right);
    else
        return 1;
}

int getNumLeavesIT(Tree *t)
{
    return _getNumLeavesIT(t->root);
}

int _getNumNodesIT(TreeNode *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return _getNumNodesIT(n->left) + _getNumNodesIT(n->right) + 1;
}

int getNumNodesIT(Tree *t)
{
    return _getNumNodesIT(t->root);
}

int _getHeightIT(TreeNode *n)
{
    int h_l, h_r;
    if (n == NULL)
    {
        return 0;
    }
    h_l = _getHeightIT(n->left);
    h_r = _getHeightIT(n->right);
    return (h_l > h_r) ? h_l + 1 : h_r + 1;
}

int getHeightIT(Tree *t)
{
    return _getHeightIT(t->root);
}

int _isFullBinTreeIT(TreeNode *n)
{
    if (n == NULL)
    {
        return 1;
    }
    if (n->left == NULL && n->right == NULL)
    {
        return 1;
    }
    if (n->left && n->right)
    {
        return _isFullBinTreeIT(n->left) && _isFullBinTreeIT(n->right);
    }
    return 0;
}

int isFullBinTreeIT(Tree *t)
{
    return _isFullBinTreeIT(t->root);
}

void _preOrderIT(TreeNode *n, trav_func cb, int depth)
{
    if (n == NULL)
    {
        return;
    }
    cb(n->data, depth);
    _preOrderIT(n->left, cb, depth + 1);
    _preOrderIT(n->right, cb, depth + 1);
}

void preOrderIT(Tree *t, trav_func cb)
{
    _preOrderIT(t->root, cb, 0);
}

void _inOrderIT(TreeNode *n, trav_func cb, int depth)
{
    if (n == NULL)
    {
        return;
    }
    _inOrderIT(n->left, cb, depth + 1);
    cb(n->data, depth);
    _inOrderIT(n->right, cb, depth + 1);
}

void inOrderIT(Tree *t, trav_func cb)
{
    _inOrderIT(t->root, cb, 0);
}

void _postOrderIT(TreeNode *n, trav_func cb, int depth)
{
    if (n == NULL)
    {
        return;
    }
    _postOrderIT(n->left, cb, depth + 1);
    _postOrderIT(n->right, cb, depth + 1);
    cb(n->data, depth);
}

void postOrderIT(Tree *t, trav_func cb)
{
    _postOrderIT(t->root, cb, 0);
}

// int main(int argc, char **argv)
// {
//     FILE *f = fopen(argv[1], "r");
//     if (!f)
//     {
//         perror("Data file Error");
//         return -2;
//     }
//     Tree *t = createIntBinTree();
//     printf("root pointer = %p\n", t->root);

//     buildIntTree(t, f);
//     printf("new root pointer = %p\n", t->root);
//     printf("Moment of the tree = %d\n", getNumNodesIT(t));
//     printf("Leaf(Leaves) of the tree = %d\n", getNumLeavesIT(t));
//     printf("Height of the tree = %d\n", getNumLeavesIT(t));
//     printf("is Full Binary tree? = %d\n", isFullBinTreeIT(t));

//     printf("Pre-Order:\n[");
//     preOrderIT(t, print_node);
//     printf("]\n");

//     printf("In-Order:\n[");
//     inOrderIT(t, print_node);
//     printf("]\n");

//     printf("Post-Order:\n[");
//     postOrderIT(t, print_node);
//     printf("]\n");
//     fclose(f);
//     return 0;
// }