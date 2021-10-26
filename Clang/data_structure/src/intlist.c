#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>

int getValueIL(IntNode *head, int index, int *status_code) {
    int i;
    IntNode *cur = head;

    if (head==NULL || index<0) {
        /* status reporting */
        if (status_code!=NULL) { *status_code = -1; }
        return 0;
    }
    for (i=0; i<index; i++) {
        if (cur==NULL) { break; }
        cur = cur->next;
    }
    if (i < index) {
        if (status_code!=NULL) { *status_code = -1; }
        return 0;
    }
    if (status_code!=NULL) { *status_code = 0; }
    return cur->value;
}

IntNode *createNodeIL(int value) {
    IntNode *n = (IntNode*)malloc(sizeof(IntNode));
    n->value = value;
    n->next = NULL;
}

IntNode *findTailIL(IntNode *head) {
    IntNode *cur = head;
    if (cur==NULL) { return NULL; }
    while (cur->next!=NULL) {
        cur = cur->next;
    }
    return cur;
}

IntNode *appendValueIL(IntNode *head, int value) {
    IntNode *new_node = createNodeIL(value);
    if (head == NULL) {
        return new_node;
    }
    IntNode *tail = findTailIL(head);
    tail->next = new_node;
    return head;
}

IntNode *prependValueIL(IntNode *head, int value) {
    IntNode *new_node = createNodeIL(value);
    new_node->next = head;
    return new_node;
}

void printValuesIL(IntNode *head) {
    IntNode *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

int lengthIL(IntNode *head) {
    /*
    if (head==NULL) {
        return 0;
    } else {
        return lengthIL(head->next)+1;
    }
    */
    int count = 0;
    IntNode *cur_node = head;
    while (cur_node!=NULL) {
        cur_node = cur_node->next;
        count++;
    }
    return count;
}

int containsValueIL(IntNode *head, int target) {
    return searchValueIL(head, target)?1:0;
}

IntNode *searchValueIL(IntNode *head, int target) {
    IntNode *cur_node = head;
    while (cur_node!=NULL) {
        if (cur_node->value == target) {
            return cur_node;
        } else {
            cur_node = cur_node->next;
        }
    }
    return NULL;
}
