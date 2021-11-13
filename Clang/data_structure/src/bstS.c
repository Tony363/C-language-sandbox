#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/bstS.h"

#define NodeData char *

TreeNodePtr createNode(char *input)
{
    TreeNode *new = (TreeNode *)malloc(sizeof(TreeNode));
    new->data = (char *)malloc(sizeof(char) * strlen(input) + 1);
    strcpy(new->data, input);
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
    if (strcmp(new->data, root->data) > 0)
        root->right = traverseTree(root->right, new);
    else if (strcmp(new->data, root->data) < 0)
        root->left = traverseTree(root->left, new);
    return root;
}

TreeNode *buildTree(FILE *in)
{
    char input[4];
    TreeNode *root = NULL, *new = NULL;
    if (fgets(input, 4, in))
    {
        input[strcspn(input, "\n")] = 0;
        root = createNode(input);
    }

    while (fgets(input, 4, in))
    {
        input[strcspn(input, "\n")] = 0;
        printf("%s\n", input);
        new = createNode(input);
        root = traverseTree(root, new);
    }
    return root;
};

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

void sVisit(TreeNode *root)
{
    printf("Root: %s\n", root->data);
    if (root->left && root->right)
        printf("[%s, %s]\n", root->left->data, root->right->data);
}

int main(int argc, char **argv)
{
    FILE *in = fopen("../Texts/bstS.txt", "r");
    TreeNodePtr root = NULL;
    if (in)
        root = buildTree(in);
    printf("preOrder printing\n");
    preOrder(root, sVisit);
    printf("\n");
    printf("inOrder printing\n");
    inOrder(root, sVisit);
    printf("\n");
    printf("postOrder printing\n");
    postOrder(root, sVisit);
    printf("\n");
    fclose(in);
    return 0;
}