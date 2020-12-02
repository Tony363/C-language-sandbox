#include<stdio.h>
#include<stdlib.h>
#include<linked_list.h>
struct ListNode* reverseList(struct ListNode **head){
    // prev is null
    if (*head == NULL){
        return NULL;
    }
    struct ListNode *prev = NULL;
    struct ListNode *temp;
    // n is first node
    struct ListNode *n = *head;
    // while n not Null
    while (n != NULL){
        // temp is next node address
        temp = n->next;
        // current nodes next address becomes the previous 
        n->next = prev;
        // prev is current nodes address
        prev = n;
        // assign current node as temp
        n = temp; 
    }
    // assign head as prev  
    *head = prev;
}
void linked_list(struct ListNode **head,int NodesN){
    struct ListNode *temp=NULL;
    for(int i=0;i<NodesN;i++) {
        struct ListNode * Node_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
        Node_ptr->val = i;
        Node_ptr->next = NULL;
        if(i==0) {
            temp = Node_ptr;
            *head = Node_ptr;
            continue;
        }
        temp->next = Node_ptr;
        temp = Node_ptr;   
    }
    temp->next = NULL;
}
void print_list(struct ListNode *head){
    struct ListNode *temp=NULL;
    temp = head;
    while(temp != NULL) {
        printf("%d\n",temp->val);
        temp = temp->next;
    }
}
void insert_node(struct ListNode *head,struct ListNode * Node, int index){
    struct ListNode *temp=head;
    for (int i=0;i<index;i++){
        temp = temp->next;
    }
    Node->next = temp->next;
    temp->next = Node;
}

void remove_node(struct ListNode *head,int index){
    struct ListNode *temp=head;
    for (int i=0;i<index-1;i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}
struct ListNode * get_node(struct ListNode *head,int index){
    struct ListNode *temp=head;
    for (int i=0;i<index;i++){
        temp = temp->next;
    }
    return temp;
}

// int main (void){
//     struct ListNode *head=NULL;
//     int NodesN=7;
//     linked_list(&head,NodesN);
//     print_list(head);
//     head = reverseList(head);
//     print_list(head);
//     int index=3;
//     insert_node(head,index);
//     return 0;
// }