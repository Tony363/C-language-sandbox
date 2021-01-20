// #include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
};

void linked_list(struct ListNode **head,int NodesN,int *array){
    struct ListNode *temp=NULL;
    for(int i=0;i<NodesN;i++) {
        struct ListNode * Node_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
        Node_ptr->val = array[i];
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

// function to insert nodes
void insert_node(struct ListNode *head,struct ListNode * Node, int index){
    struct ListNode *temp=head;
    for (int i=0;i<index;i++){
        temp = temp->next;
    }
    Node->next = temp->next;
    temp->next = Node;
}

// function to remove nodes 
void remove_node(struct ListNode *head,int index,int listSize){
    struct ListNode *temp=head;struct ListNode *prev;
    // iterate to index - 1 node
    for (int i=0;i<index-2;i++){
        // printf("%d\n",temp->val);
        prev = temp;
        temp = temp->next;
    }
    printf("%d\n",temp->val);
    // attempt delete node
    if (index == listSize){
        temp->next = NULL;
    }
    else {
        temp->next = prev->next->next;
    }
}

void print_list(struct ListNode *head){
    struct ListNode *temp=NULL;
    temp = head;
    printf("[");
    while(temp != NULL) {
        printf("%d,",temp->val);
        temp = temp->next;
    }
    printf("]\n");
}

void print_array(int *array,int arraySize){
    printf("[");
    for(int i=0;i<arraySize;i++){
        printf("%d,",array[i]);
    }
    printf("]\n");
}

/*
class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        original = len(arr)
        print(original)
        i=0
        while i < original:
            if arr[i] == 0:
                arr.insert(i,0)
                arr.pop()
                i+=1
            i+=1
*/

void duplicateZeros(int* arr, int arrSize){
    // instantiate head node
    struct ListNode *head=NULL;
    linked_list(&head,arrSize,arr);
    
    // temp of head and node value to insert
    struct ListNode *temp=head; struct ListNode Node={.val=0,.next=NULL};
    
    // view list
    print_list(head);
    
    // instantiate iterater and final array
    int i=0;int array[arrSize];
    
    // transverse list alongside iterator
    while (temp!=NULL&&i<arrSize){
        // assign array value fist
        array[i]=temp->val;
        if (i == arrSize-1){
            break;
        }
        // if find 0, insert node with value 0 and remove the last node

        // SEG FAULT <- FIX ME
        if (temp->val==0){
            insert_node(temp,&Node,i);
            remove_node(temp,arrSize,arrSize);
                        
            // addition move to next node
            // temp=temp->next->next;
            // addition iteration
            i+=2;
        } else {
             // transversing list and iteration
            i+=1;
            temp=temp->next;
        }
    }
    print_array(array,arrSize);
}

int main(void){
    int array[] = {1,0,2,3,0,4,5,0};
    int arraySize = sizeof(array)/sizeof(array[0]);
    duplicateZeros(array,arraySize);
    return 0;
}