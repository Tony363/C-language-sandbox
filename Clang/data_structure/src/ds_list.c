#include "ds_list.h"
#include <stdlib.h>
#include <stdio.h>

NodePtr new_node(double value) {
	NodePtr n = (NodePtr)malloc(sizeof(Node));
	n->value = value;
	n->next = NULL;
	return n;
}

void print_list(NodePtr head) {
	NodePtr cur = head;
	while (cur!=NULL) {
		printf("%lf ", cur->value);
		cur = cur->next;
	}
	printf("\n");
}

NodePtr add_head_node(NodePtr head, NodePtr node) {
	NodePtr new_head;
	new_head = head;
	
	if (node != NULL) {
		node->next = head;
		new_head = node;
	}
	
	return new_head;
}

NodePtr find_tail_node(NodePtr head) {
	NodePtr cur = head;
	
	while (cur!=NULL && cur->next!=NULL) {
		cur = cur->next;
	}
	return cur;
}

NodePtr add_tail_node(NodePtr head, NodePtr node) {
	NodePtr tail;
	tail = find_tail_node(head);
	if (tail != NULL) {
		tail -> next = node;
	}
	if (head==NULL) {
		return node;
	} else {	
		return head;
	}
}

int count_list(NodePtr head) {
	NodePtr cur = head;
	
	if (cur==NULL) { /* empty */
		return 0;
	} else if (cur->next==NULL) { /* single */
		return 1;
	} else {
		int counter = 1;
		while (cur->next!=NULL) {
			counter++;
			cur = cur->next;
		}
		return counter;
	}
}

NodePtr get_node(NodePtr head, int idx) {
	NodePtr cur;
	int i;
	
	if (head==NULL || idx<0) {
		return NULL;
	}
	cur = head;
	for (i=0; i<idx; i++) {
		if (cur->next!=NULL) {
			cur = cur->next;
		} else {
			return NULL;
		}
	}
	return cur;
}

NodePtr find_first(NodePtr head, double value) {
	NodePtr cur;
	cur = head;
	while (cur!=NULL && cur->value!=value) {
		cur = cur->next;
	}
	return cur;
}
