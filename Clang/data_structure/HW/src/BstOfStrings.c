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

/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
StrBSTNode *minValueNode(StrBSTNode *node)
{
    StrBSTNode *current = node;

    /*
     loop down to find the leftmost leaf
     (we determine the parent to leftmost node)?
    */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

StrBSTNode *deleteNode(StrBSTNode *root, const char *value)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (strcmp(value, root->s) < 0)
        root->left = deleteNode(root->left, value);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (strcmp(value, root->s) > 0)
        root->right = deleteNode(root->right, value);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            StrBSTNode *temp = root->right;
            free(root->s);
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            StrBSTNode *temp = root->left;
            free(root->s);
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor, leftmost node
        // (smallest in the right subtree)
        StrBSTNode *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->s = temp->s;

        // Delete the inorder successor
        // Delete the node that is copied to location of root to be deleted
        // since that specific node now should be with no children or single children case
        root->right = deleteNode(root->right, temp->s);
    }
    return root;
}

void delValueSB(StrBST *bst, const char *value)
{
    if (!bst || !value)
        return;
    bst->root = deleteNode(bst->root, value);
}

int main(int argc, char **argv)
{
    // StrBST *bst = createStrBST();
    // addValueSB(bst, "John");
    // addValueSB(bst, "Bob");
    // addValueSB(bst, "Tom");
    // addValueSB(bst, "Alan");
    // addValueSB(bst, "Ellen");
    // addValueSB(bst, "Karen");
    // addValueSB(bst, "Wendy");
    // toSortedList(bst, value_depth);
    // printf("\n");
    // delValueSB(bst, "Alan");
    // toSortedList(bst, value_depth);

    // StrBST *bst = createStrBST();
    // addValueSB(bst, "egg");
    // addValueSB(bst, "hi");
    // addValueSB(bst, "cat");
    // addValueSB(bst, "apple");
    // addValueSB(bst, "bell");
    // delValueSB(bst, "bell");
    // toSortedList(bst, value_depth);
    // printf("\n");

    StrBST *bst = createStrBST();
    addValueSB(bst, "egg");
    addValueSB(bst, "hi");
    addValueSB(bst, "cat");
    addValueSB(bst, "apple");
    addValueSB(bst, "bell");
    delValueSB(bst, "bell");
    delValueSB(bst, "cat");
    toSortedList(bst, value_depth);
    printf("\n");
    return 0;
}