#ifndef _intlist_h
#define _intlist_h

typedef struct _IntNode {
    int value;
    struct _IntNode *next;
} IntNode;

IntNode *createNodeIL(int value);
int lengthIL(IntNode *head);
int containsValueIL(IntNode *head, int target);
void printValuesIL(IntNode *head);
IntNode *findTailIL(IntNode *head);
IntNode *appendValueIL(IntNode *head, int value);
IntNode *prependValueIL(IntNode *head, int value);
IntNode *searchValueIL(IntNode *head, int target);
int getValueIL(IntNode *head, int index, int *status_code);

#endif
