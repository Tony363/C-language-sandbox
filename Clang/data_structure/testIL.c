#include <stdio.h>
#include <stdlib.h>
#include "intlist.h"



int main(int argc, char **argv) {
    IntNode *n1, *n2, *n3, *n4, *head;
    int r, st;
    n1 = createNodeIL(10);
    n2 = createNodeIL(30);
    n3 = createNodeIL(20);
    n4 = createNodeIL(40);
    n1->next = n2; n2->next = n3; n3->next = n4;
    appendValueIL(n1, 3000);
    head = prependValueIL(n1, 5000);
    printValuesIL(head);
    printf("Length of list = %d\n", lengthIL(head));
    printf("Tail value is %d\n", findTailIL(head)->value);
    printf("Value at index %d is %d\n", 3, getValueIL(head, 3, NULL));
    r = getValueIL(head, 200, &st);
    if (st!=0) {
        printf("Error getting value at index %d\n", 200);
    }
    printf("20 in the list? %d\n", containsValueIL(head, 20));
    printf("50 in the list? %d\n", containsValueIL(head, 50));
    return 0;
}
