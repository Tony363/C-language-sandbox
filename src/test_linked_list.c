#include<stdio.h>
#include<minunit.h>
#include<linked_list.h>

MU_TEST(test_insert_list) {
    struct ListNode *head=NULL;
    int NodesN=7;
    linked_list(&head,NodesN);
    int index=3;
    struct ListNode Node = {.val=100,.next=NULL};
    insert_node(head,&Node,index);
    struct ListNode *Node_ptr1 = get_node(head,3);
    mu_check(Node_ptr1->val == 3);
    struct ListNode *Node_ptr2 = get_node(head,4);
    mu_check(Node_ptr2->val == 100);
    struct ListNode *Node_ptr3 = get_node(head,5);
    printf("%d\n",Node_ptr3->val);
    mu_check(Node_ptr3->val == 4);
	
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
}    

int main(int argc,char *argv[]){
    MU_RUN_SUITE(test_suite);    
	MU_REPORT();
	return MU_EXIT_CODE;
}