#include<stdio.h>
#include<minunit.h>
#include<linked_list.h>

MU_TEST(test_reverse_node){
    struct ListNode *head=NULL;
    linked_list(&head,7);
    print_list(head);
    struct ListNode *temp=head;
    reverseList(&head);
    print_list(head);
    struct ListNode *tail=head;
    for (int i=0;i<7;i++){
        if (temp == NULL || tail == NULL){
            break;
        }
        mu_check(temp->val != tail->val);
        temp = temp->next;
        tail = tail->next;
    }
}
MU_TEST(test_insert_list) {
    struct ListNode *head=NULL;
    linked_list(&head,7);
    struct ListNode Node = {.val=100,.next=NULL};
    insert_node(head,&Node,3);
    print_list(head);
    struct ListNode *Node_ptr1 = get_node(head,3);
    mu_check(Node_ptr1->val == 3);
    struct ListNode *Node_ptr2 = get_node(head,4);
    mu_check(Node_ptr2->val == 100);
    struct ListNode *Node_ptr3 = get_node(head,5);
    mu_check(Node_ptr3->val == 4);
	
}   

MU_TEST(test_remove_node){
    struct ListNode *head=NULL;
    linked_list(&head,7);
    remove_node(head,3);
    print_list(head);
    struct ListNode *temp=head;
    for (int i=0;i<6;i++){
        if (temp->val == 3){
            mu_check(temp->val != 3);
        }
        temp = temp->next;
    }  
}

MU_TEST(test_get_node){
    struct ListNode *head=NULL;
    linked_list(&head,7);
    struct ListNode *Node_ptr = get_node(head,3);
    mu_check(Node_ptr->val == 3);
}
MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_insert_list);
    MU_RUN_TEST(test_get_node);
    MU_RUN_TEST(test_remove_node);
    printf("\n");
    MU_RUN_TEST(test_reverse_node);
}    

int main(int argc,char *argv[]){
    MU_RUN_SUITE(test_suite);    
	MU_REPORT();
	return MU_EXIT_CODE;
}