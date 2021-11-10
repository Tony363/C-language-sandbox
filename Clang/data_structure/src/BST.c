#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/bst.h"

TreeNodePtr createNode(int input)
{
    NodeData *new = (NodeData *)malloc(sizeof(NodeData));
    new->data = input;
    new->left = NULL;
    new->right = NULL;
    return new;
};

TreeNodePtr buildTree(FILE *in)
{
    char str[10];
    int inD;
    while (fgets(str, 10, in) != NULL)
    {
        inD = atoi(str);
    }
    return NULL;
};
void preOrder(TreeNodePtr root, visit_func visit);
void inOrder(TreeNodePtr root, visit_func visit);
void postOrder(TreeNodePtr root, visit_func visit);

int main(int argc, char **argv)
{
    FILE *in = fopen("../Texts/bst.txt", "r");

    TreeNodePtr root;
    if (in)
        root = buildTree(in);
    return 0;
}