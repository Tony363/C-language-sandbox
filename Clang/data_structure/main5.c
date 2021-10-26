#include "ds_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	NodePtr head_ptr = NULL;
	NodePtr np1, np2, np3, np4;
	int i=0;
	
	np1 = new_node(10); 
	head_ptr = add_tail_node(head_ptr, np1);
	printf("size=%d\n", count_list(head_ptr));
	print_list(head_ptr);
	
	np2 = new_node(30); 
	head_ptr = add_tail_node(head_ptr, np2);
	printf("size=%d\n", count_list(head_ptr));
	print_list(head_ptr);	
	
	np3 = new_node(20); 
	head_ptr = add_tail_node(head_ptr, np3);
	printf("size=%d\n", count_list(head_ptr));
	print_list(head_ptr);
	
	np4 = new_node(40); 
	head_ptr = add_tail_node(head_ptr, np4);
	printf("size=%d\n", count_list(head_ptr));
	print_list(head_ptr);
	
	for (i=-1; i<6; i++) {
		NodePtr n = get_node(head_ptr, i);
		if (n!=NULL) {
			printf("value at [%d] = %lf\n", i, n->value);
		} else {
			printf("value at [%d] does not exist\n");
		}
	}
	
	NodePtr n = find_first(head_ptr, 20);
	if (n!=NULL) {
		printf("%lf Found at address 0x%p\n", 20.0, n);
	} else {
		printf("%lf Not Found\n", 20.0);
	}
	n = find_first(head_ptr, 60);
	if (n!=NULL) {
		printf("%lf Found at address 0x%p\n", 60.0, n);
	} else {
		printf("%lf Not Found\n", 60.0);
	}
	
	free(np4);
	free(np3);
	free(np2);
	free(np1);
	
	return 0;
}