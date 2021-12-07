#include "../includes/intbst.h"

/* copy the implemetaiton function from intbintree.c */
TreeNode *createIntBinTreeNode(int v);
typedef void (*trav_func)(int value, int depth);

IntBST *createIntBST()
{
    return createIntBinTree();
};
TreeNode *_addValueIB(TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createIntBinTreeNode(value); // to not waste memory for memory leakage
    }
    if (root->data == value)
    {
        return root;
    }
    if (root->data > value)
    {
        root->left = _addValueIB(root->left, value);
        return root;
    }
    else
    {
        root->right = _addValueIB(root->right, value);
        return root;
    }
};

void addValueIB(IntBST *bst, int value)
{
    if (bst == NULL)
    {
        return;
    }
    _addValueIB(bst->root, value);
}

void print_node(int value, int depth)
{
    printf("%d ", value);
}

int main(int argc, char **argv)
{
    IntBST *bst = createIntBST();
    addValueIB(bst, 1);
    addValueIB(bst, 2);
    addValueIB(bst, -1);
    addValueIB(bst, 4);
    inOrderIT(bst, print_node);

    return 0;
}