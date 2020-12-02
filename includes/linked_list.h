#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode **head);
struct ListNode * get_node(struct ListNode *head,int index);
void print_list(struct ListNode *head);
void linked_list(struct ListNode **head,int NodesN);

void insert_node(struct ListNode *head,struct ListNode * Node,int index);
void remove_node(struct ListNode *head,int index);
#endif


