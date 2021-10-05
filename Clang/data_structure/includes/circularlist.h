#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include "linklist.h"

Node *insertCircular(Node *head, int index, int data);
Node *circularList(int data[], int len);
void printCircular(Node *head);
#endif