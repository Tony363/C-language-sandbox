#include <stdio.h>
#include "includes/graphsFCC.h"

int main(int argc, char **argv)
{
    Graph *g;
    FILE *in_file;

    in_file = fopen("../Texts/graph.txt", "r");
    g = buildGraph(in_file);
    fclose(in_file);

    printGraph(g);
    freeGraph(g);

    return 0;
}