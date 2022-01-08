#include "../includes/graphsFCC.h"
#include <stdlib.h>
#include <string.h>

void printGraph(Graph *g)
{
    int i;

    for (i = 0; i < g->num_vertices; i++)
    {
        ChildNode *c;
        printf("[%d]%s -> ( ", i, g->vertices[i].name);
        c = g->vertices[i].children;
        while (c != NULL)
        {
            printf("%s ", g->vertices[c->child_idx].name);
            c = c->next;
        }
        printf(")\n");
    }
}

int findVertexIdx(Graph *g, const char *name)
{
    int i;
    for (i = g->num_vertices; --i >= 0;)
    {
        if (!strcmp(name, g->vertices[i].name))
        {
            return i;
        }
    }
    return i;
}

Graph *buildGraph(FILE *input)
{
    int numV, i;
    char nameV[100];

    Graph *g = (Graph *)malloc(sizeof(Graph));

    fscanf(input, "%d", &numV); /* the number of vertices */
    g->num_vertices = numV;
    g->vertices = (ParentNode *)malloc(sizeof(ParentNode) * numV);

    /* initialize each vertex information */
    for (i = 0; i < numV; i++)
    {
        fscanf(input, "%s", nameV);
        initParentNode((g->vertices) + i, nameV);
    }

    /* build the children lists */
    while (1)
    {
        int parentIdx, r;
        ChildNode *tail = NULL;

        r = fscanf(input, "%s %d", nameV, &numV);
        if (r < 2)
        {
            break;
        }
        parentIdx = findVertexIdx(g, nameV);
        for (i = 0; i < numV; i++)
        {
            char nameC[100];
            double cost;
            int childIdx;
            ChildNode *n;

            fscanf(input, "%s %lf", nameC, &cost);
            childIdx = findVertexIdx(g, nameC);
            n = createChildNode(childIdx, cost);
            if (tail == NULL)
            { /* the 1st child */
                g->vertices[parentIdx].children = n;
            }
            else
            {
                tail->next = n;
            }
            tail = n;
            /*
            n->next = g->vertices[parentIdx].children;
            g->vertices[parentIdx].children = n;
            */
        }
    }

    return g;
}

ChildNode *createChildNode(int idx, double cost)
{
    ChildNode *n = (ChildNode *)malloc(sizeof(ChildNode));
    n->child_idx = idx;
    n->cost = cost;
    n->next = NULL;
    return n;
}

ParentNode *createParentNode(const char *name)
{
    ParentNode *n = (ParentNode *)malloc(sizeof(ParentNode));
    initParentNode(n, name);
    return n;
}

void initParentNode(ParentNode *n, const char *name)
{
    n->name = (char *)malloc(strlen(name) + 1);
    strcpy(n->name, name);
    n->children = NULL;
}

void freeChildNode(ChildNode *n)
{
    free(n);
}

void freeParentNode(ParentNode *n)
{
    free(n->name);
    free(n);
}

void freeGraph(Graph *g)
{
    int i;

    for (i = 0; i < g->num_vertices; i++)
    {
        ChildNode *c, *t;

        c = g->vertices[i].children;
        while (c != NULL)
        {
            t = c->next;
            free(c);
            c = t;
        }
    }
    free(g->vertices);
    free(g);
}
