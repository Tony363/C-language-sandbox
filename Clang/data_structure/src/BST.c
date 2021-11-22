#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/bst.h"
// #define NodeData int

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
    if (new->data > root->data)
        root->right = traverseTree(root->right, new);
    else if (new->data < root->data)
        root->left = traverseTree(root->left, new);
    return root;
}

TreeNode *insertNode(TreeNode *root, int inD)
{
    if (!root)
    {
        return NULL;
    }
    TreeNode *new = createNode(inD);
    root = traverseTree(root, new);
    return root;
}

TreeNode *buildTree(FILE *in)
{
    char str[4];
    int inD;
    TreeNode *root = NULL, *new = NULL;
    if (fgets(str, 4, in))
    {
        inD = atoi(str);
        root = createNode(inD);
    }

    while (fgets(str, 4, in))
    {
        inD = atoi(str);
        root = insertNode(root, inD);
    }
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

void deleteNode(TreeNode *root, int val)
{
    if (!root)
        return;
    if (root->data == val)
    {
        if (root->left && root->right)
        {
            TreeNode *temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
        else if (root->left)
        {
            TreeNode *temp = root->left;
            root->data = temp->data;
            root->left = temp->left;
            root->right = temp->right;
        }
        else if (root->right)
        {
            TreeNode *temp = root->right;
            root->data = temp->data;
            root->left = temp->left;
            root->right = temp->right;
        }
        else
        {
            root = NULL;
        }
    }
    else if (val > root->data)
    {
        deleteNode(root->right, val);
    }
    else
    {
        deleteNode(root->left, val);
    }
}

void preOrder(TreeNodePtr root, visit_func visit)
{
    if (!root)
        return;
    visit(root);
    preOrder(root->left, visit);
    preOrder(root->right, visit);
};

void inOrder(TreeNodePtr root, visit_func visit)
{
    if (!root)
        return;
    inOrder(root->left, visit);
    visit(root);
    inOrder(root->right, visit);
};

void postOrder(TreeNodePtr root, visit_func visit)
{
    if (!root)
        return;
    postOrder(root->left, visit);
    postOrder(root->right, visit);
    visit(root);
};

void iVisit(TreeNode *root)
{
    printf("Root: %d\n", root->data);
    if (root->left && root->right)
        printf("[%d, %d]\n", root->left->data, root->right->data);
}

int main(int argc, char **argv)
{
    FILE *in = fopen("../Texts/bst.txt", "r");
    TreeNodePtr root = NULL;
    if (in)
        root = buildTree(in);
    root = insertNode(root, 10);
    root = insertNode(root, 9);
    root = insertNode(root, 11);
    printf("%s\n\n", searchNode(root, 10) ? "Found" : "Not Found");
    deleteNode(root, 10);
    printf("%s\n\n", searchNode(root, 10) ? "Found" : "Not Found");

    printf("preOrder printing\n");
    preOrder(root, iVisit);
    printf("\n");
    printf("inOrder printing\n");
    inOrder(root, iVisit);
    printf("\n");
    printf("postOrder printing\n");
    postOrder(root, iVisit);
    printf("\n");
    fclose(in);
    return 0;
}
// TODO: print bst like tree
// https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/