#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/adjacentGraphs.h"
int findVertexIdx(GraphFCC *g, const char *name)
{
    int i;
    for (i = g->num_vertices; --i >= 0;)
    {
        if (!strcmp(name, g->vertices[i].name))
            return i;
    }
    return -1;
}
ChildNode *createChildNode(int idx, double cost)
{
    ChildNode *n = (ChildNode *)malloc(sizeof(ChildNode));
    n->child_idx = idx;
    n->cost = cost;
    n->next = NULL;
    return n;
};

void initParentNode(ParentNode *n, const char *name)
{
    n->name = (char *)malloc(sizeof(char) * strlen(name) + 1); // + 1 for NULL character
    strcpy(n->name, name);
    n->children = NULL;
};

ParentNode *createParentNode(const char *name)
{
    ParentNode *n = (ParentNode *)malloc(sizeof(ParentNode));
    initParentNode(n, name);
    return n;
};

void freeChildNode(ChildNode *n)
{
    free(n);
};
void freeParentNode(ParentNode *n)
{
    free(n->name);
    free(n);
};

GraphFCC *buildGraph(FILE *input)
{
    int numV, i;
    char nameV[100];
    GraphFCC *g = (Graph *)malloc(sizeof(Graph));
    fscanf("%d", &numV);
    g->num_vertices = numV;
    g->num_vertices = (ParentNode *)malloc(sizeof(ParentNode) * numV);
    for (i = 0; i < numV; i++)
    {
        fscanf(input, "%s", nameV);
        initParentNode((g->vertices) + i, nameV);
    }
    /*build the children lists*/
    while (1)
    {
        int parentIdx, r;
        r = fscanf(input, "%s %d", nameV, &numV);
        if (r < 2)
            break;
        parentIdx = findVertexIdx(g, nameV);
        for (i = 0; i < numV; i++)
        {
            char nameC[100];
            double cost;
            int childIdx;
            fscanf(input, "%s %lf", nameC, cost);
            childIdx = findVertexIdx(g, nameC);
            ChildNode *n = createChildNode(childIdx, cost);
            n->next = g->vertices[parentIdx].children; // parentIdx tell me the char in the vertices; simple prepending
            g->vertices[parentIdx].children = n;
        }
    }
    return g;
};

int main(int argc, char **argv)
{
    return 0;
}