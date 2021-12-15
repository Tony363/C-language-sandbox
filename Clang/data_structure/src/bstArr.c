#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _TreeNode
{
    char word[101];
    struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

TreeNodePtr buildTree(FILE *in)
{
    char word[101];

    fscanf(in, "%s", word);
    if (strcmp(word, "@") == 0)
    {
        return NULL;
    }
    else
    {
        TreeNodePtr root = (TreeNodePtr)malloc(sizeof(TreeNode));
        strcpy(root->word, word);
        root->left = buildTree(in);
        root->right = buildTree(in);
        return root;
    }
}

typedef void (*visit_func)(TreeNodePtr node);
typedef void (*visit_func1)(TreeNodePtr node, int node_idx, char **array);

void preOrder(TreeNodePtr root, visit_func v)
{
    if (root == NULL)
    {
        return;
    }
    /* visit node */
    v(root);
    /* traversing */
    preOrder(root->left, v);
    preOrder(root->right, v);
}

void preOrder1(TreeNodePtr root, int node_idx, char **array, visit_func1 v)
{
    if (root == NULL)
    {
        return;
    }
    /* visit node */
    v(root, node_idx, array);
    /* traversing */
    preOrder1(root->left, node_idx * 2 + 1, array, v);
    preOrder1(root->right, node_idx * 2 + 2, array, v);
}

void toArray(TreeNodePtr node, int node_idx, char **array)
{
    array[node_idx] = node->word; /* a quick hack, should duplicate the string */
}

int treeHeight(TreeNodePtr root)
{
    int left_h, right_h;
    if (root == NULL)
    {
        return 0;
    }
    left_h = treeHeight(root->left);
    right_h = treeHeight(root->right);
    return (left_h > right_h ? left_h : right_h) + 1;
}

void print_node(TreeNodePtr node)
{
    printf("%s ", node->word);
}
void print_node_v2(TreeNodePtr node)
{
    printf("%s::", node->word);
}

int main(int argc, char **argv)
{
    FILE *in;
    TreeNodePtr root;
    int h, n_elem, i;
    char **words;

    in = fopen("../Texts/tree.in", "r");
    root = buildTree(in);
    fclose(in);

    h = treeHeight(root);
    for (i = 0, n_elem = 1; i < h; i++)
    {
        n_elem *= 2;
    }
    n_elem--;
    printf("The height of the tree: %d\n", h);
    printf("Requires %d array elements\n", n_elem);
    words = (char **)malloc(sizeof(char *) * n_elem);
    memset(words, 0, sizeof(char *) * n_elem);
    preOrder1(root, 0, words, toArray);

    preOrder(root, print_node);
    printf("\n");
    preOrder(root, print_node_v2);
    printf("\n");

    printf("array representation:\n");
    for (i = 0; i < n_elem; i++)
    {
        if (words[i] == NULL)
        {
            printf("_ ");
        }
        else
        {
            printf("%s ", words[i]);
        }
    }
    printf("\n");

    return 0;
}
