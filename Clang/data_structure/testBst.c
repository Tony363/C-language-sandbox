#include <stdio.h>
#include "includes/bst.h"

FILE *preOut, *inOut, *postOut;

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

int main(int argc, char **argv)
{
    // open insert node file and build tree
    FILE *in = fopen("../Texts/bst.txt", "r");
    Tree *t = buildTree(in);
    print2D(t->root);

    // test insert nodes
    insertNode(t, 10);
    insertNode(t, 9);
    insertNode(t, 11);
    print2D(t->root);
    printf("%s\n\n", searchNode(t->root, 11) ? "Found" : "Not Found");

    // test delete nodes
    deleteNode(t->root, 4);
    deleteNode(t->root, 10);
    deleteNode(t->root, 9);
    print2D(t->root);
    printf("%s\n\n", searchNode(t->root, 11) ? "Found" : "Not Found");

    // open output ordering files
    preOut = fopen("../Texts/preOrder.txt", "w");
    inOut = fopen("../Texts/inOrder.txt", "w");
    postOut = fopen("../Texts/postOrder.txt", "w");

    // get bst tree dimensions
    printf("Moment of the tree = %d\n", getNumNodesIT(t));
    printf("Leaf(Leaves) of the tree = %d\n", getNumLeavesIT(t));
    printf("Height of the tree = %d\n", getNumLeavesIT(t));
    printf("is Full Binary tree? = %d\n", isFullBinTreeIT(t));
    printf("\n");

    // output the formatted orderings
    printf("preOrder printing\n");
    preOrder(t->root, iVisit);
    printf("\n");
    printf("inOrder printing\n");
    inOrder(t->root, iVisit);
    printf("\n");
    printf("postOrder printing\n");
    postOrder(t->root, iVisit);
    printf("\n");
    print2D(t->root);

    // free bst
    t->root = freeNode(t->root);
    print2D(t->root);

    // close all files
    fclose(in);
    fclose(preOut);
    fclose(postOut);
    fclose(inOut);

    // sorted array to bst with divide and conquer
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len;
    Tree *tarr = createIntBinTree();
    printf("sorted array length: %d\n", len = sizeof(arr) / sizeof(int) - 1); // index starts from 0
    sortedArrToBst(arr, 0, len, tarr);
    print2D(tarr->root);
    tarr->root = freeNode(tarr->root);
    print2D(tarr->root);
    return 0;
}