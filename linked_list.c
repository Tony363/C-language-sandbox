#include<stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    // prev is null
    if (head == NULL){
        return NULL;
    }
    struct ListNode* prev = NULL;
    struct ListNode* temp;
    // n is first node
    struct ListNode* n = head;
    // while n not Null
    while (n != NULL){
        temp = n->next;
        n->next = prev;
        prev = n;
        n = temp; 
    }
    head = prev;
        // temp is next node address
        // current nodes next address is prev
        // assign n as temp
        // prev is current nodes address
    // assign head as prev
    return head;   
}
