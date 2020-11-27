#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
};
 
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
void linked_list(struct ListNode **head,int NodesN){
    struct ListNode *temp=NULL;
    // for (int i=0;i<NodesN;i++){
    //     struct ListNode Node;
    //     Node.val=i;
    //     Node.next = NULL;
    //     if (i==0){
    //         temp = &Node;
    //         *head = &Node;
    //         continue;
    //     }
    //     temp->next = &Node;
    //     temp = &Node;
        
    //     // printf("%p\n",Node.next);
    // }
    // temp->next = NULL;
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
    // do{
    //     printf("%d\n",temp->val);
    //     printf("%p\n",temp->next);
    //     temp = temp->next;
    // }
    // while (temp != NULL);
    while(temp != NULL) {
        printf("%d\n",temp->val);
        // printf("%p\n",temp->next);
        temp = temp->next;
    }
}
int main (void){
    struct ListNode Node1,Node2,Node3;
    struct ListNode *head=NULL;
    int NodesN=3;
    linked_list(&head,NodesN);
    print_list(head);
    head = reverseList(head);
    print_list(head);
    return 0;
}