#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/bst.h"
#define COUNT 5

FILE *preOut, *inOut, *postOut;

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
        printf("Duplicate value found\n");
    else if (new->data > root->data)
        root->right = traverseTree(root->right, new);
    else if (new->data < root->data)
        root->left = traverseTree(root->left, new);
    return root;
}

// case for empty
TreeNode *insertNode(TreeNode *root, int inD)
{
    if (!root)
        return NULL;
    TreeNode *new = createNode(inD);
    root = traverseTree(root, new);
    return root;
}

TreeNode *buildTree(FILE *in)
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
        root = insertNode(root, c - '0');
    return root;
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

void freeNode(TreeNode *root)
{
    if (!root)
        return;
    freeNode(root->left);
    freeNode(root->right);
    free(root);
}

/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
TreeNode *minValueNode(TreeNode *node)
{
    TreeNode *current = node;

    /* loop down to find the leftmost leaf */
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
        // Get the inorder successor
        // (smallest in the right subtree)
        TreeNode *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// void deleteNode(TreeNode *root, int val)
// {
//     if (!root)
//         return;
//     if (root->data == val)
//     {
//         if (root->left && !root->right)
//         {

//         }
//         else if (root->right && !root->left)
//         {

//         }
//         else if (root->left && root->right)
//         {

//         }
//     }
//     if (val > root->data)
//         deleteNode(root->right, val);
//     else
//         deleteNode(root->left, val);
// }

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

void iVisit(TreeNode *root, char type)
{
    printf("Root: %d\n", root->data);
    if (type == '0')
        fprintf(preOut, "%d", root->data);
    else if (type == '1')
        fprintf(inOut, "%d", root->data);
    else
        fprintf(postOut, "%d", root->data);
}

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

int main(int argc, char **argv)
{
    FILE *in = fopen("../Texts/bst.txt", "r");
    TreeNodePtr root = NULL;
    root = buildTree(in);
    root = insertNode(root, 10);
    root = insertNode(root, 9);
    root = insertNode(root, 11);
    printf("%s\n\n", searchNode(root, 10) ? "Found" : "Not Found");
    root = deleteNode(root, 3);
    root = deleteNode(root, 11);
    root = deleteNode(root, 9);
    printf("%s\n\n", searchNode(root, 10) ? "Found" : "Not Found");

    preOut = fopen("../Texts/preOrder.txt", "w");
    inOut = fopen("../Texts/inOrder.txt", "w");
    postOut = fopen("../Texts/postOrder.txt", "w");

    printf("preOrder printing\n");
    preOrder(root, iVisit);
    printf("\n");
    printf("inOrder printing\n");
    inOrder(root, iVisit);
    printf("\n");
    printf("postOrder printing\n");
    postOrder(root, iVisit);
    printf("\n");
    print2D(root);
    fclose(in);
    fclose(preOut);
    fclose(postOut);
    fclose(inOut);
    return 0;
}