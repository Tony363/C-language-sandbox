/*
Author : Martin Chekurov 
*/

#ifndef GEN_LIST_H_
#define GEN_LIST_H_

#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef enum
{

    GEN_LIST_NO_ERR,
    GEN_LIST_WRONG_PAR,
    GEN_LIST_NO_MEMORY,
    GEN_LIST_MATCH,
    GEN_LIST_NO_MATCH,
    GEN_LIST_FULL,
    GEN_LIST_ERROR

} GenListError;

typedef GenListError (*Compare)(void *, void *);
typedef struct GenList_t GenList;

GenList *genListNew(unsigned int dataSize, Compare cmp);
GenListError genListDestroy(GenList *list);
GenListError genListPushHead(GenList *list, void *data);
GenListError genListPopHead(GenList *list, void *buf, unsigned int size);
GenListError genListSearchNode(GenList *list, void *data, void *buf, unsigned int size);
GenListError genListGetSize(GenList *list, unsigned int *size);
GenListError genListGetIndex(GenList *list, unsigned int index, void *buf, unsigned int size);

#endif