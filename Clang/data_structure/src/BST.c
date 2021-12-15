#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/bst.h"
#define COUNT 5

int getLevel(int n)
{
    int lvl = 0;
    while (n % 2 == 0)
    {
        lvl++;
        n /= 2;
    }
    return lvl;
}

TreeNode *createNode(int input)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = input;
    new->left = NULL;
    new->right = NULL;
    return new;
};

TreeNode *traverseTree(TreeNode *root, TreeNode *new)
{
    if (!root)
    {
        root = new;
        return root;
    }
    if (new->data == root->data)
        printf("Duplicate value found: %d\n", root->data);
    else if (new->data > root->data)
        root->right = traverseTree(root->right, new);
    else if (new->data < root->data)
        root->left = traverseTree(root->left, new);
    return root;
}

// case for empty
void insertNode(Tree *t, int inD)
{
    if (!t)
        return;
    TreeNode *new = createNode(inD);
    t->root = traverseTree(t->root, new);
}

void sortedArrToBst(int *arr, int start, int end, Tree *root)
{
    if (start > end)
        return;
    int mid = (start + end) / 2;
    insertNode(root, arr[mid]);
    sortedArrToBst(arr, start, mid - 1, root);
    sortedArrToBst(arr, mid + 1, end, root);
}

Tree *buildTree(FILE *in)
{
    if (!in)
        return NULL;
    char c;
    TreeNode *root = NULL;
    if (c = fgetc(in))
        root = createNode(c - '0');
    else
        return NULL;
    while ((c = fgetc(in)) != EOF)
    {
        TreeNode *new = createNode(c - '0');
        root = traverseTree(root, new);
    }
    Tree *t = createIntBinTree();
    t->root = root;
    return t;
};

int searchNode(TreeNode *root, int val)
{
    if (!root)
        return 0;
    if (root->data == val)
        return 1;
    if (val > root->data)
        return searchNode(root->right, val);
    else
        return searchNode(root->left, val);
}

TreeNode *freeNode(TreeNode *root)
{
    if (!root)
        return root;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
    return NULL;
}

/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;

    /*
     loop down to find the leftmost leaf
     (we determine the parent to leftmost node)?
    */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor, leftmost node
        // (smallest in the right subtree)
        TreeNode *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        // Delete the node that is copied to location of root to be deleted
        // since that specific node now should be with no children or single children case
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void delete (Tree *t, int inD)
{
    if (!t)
        return;
    t->root = deleteNode(t->root, inD);
}

void preOrder(TreeNodePtr root, visit_func visit)
{
    if (!root)
        return;
    visit(root, '0');
    preOrder(root->left, visit);
    preOrder(root->right, visit);
};

void inOrder(TreeNodePtr root, visit_func visit)
{
    if (!root)
        return;
    inOrder(root->left, visit);
    visit(root, '1');
    inOrder(root->right, visit);
};

void postOrder(TreeNodePtr root, visit_func visit)
{
    if (!root)
        return;
    postOrder(root->left, visit);
    postOrder(root->right, visit);
    visit(root, '2');
};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(TreeNode *root, int space)
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
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(TreeNode *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
