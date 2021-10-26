#ifndef _ds_list_h
#define _ds_list_h

typedef struct _Node {
	double value;
	struct _Node *next;
} Node, *NodePtr;

NodePtr new_node(double value);
void print_list(NodePtr head);

NodePtr add_head_node(NodePtr head, NodePtr node);
NodePtr add_tail_node(NodePtr head, NodePtr node);
NodePtr find_tail_node(NodePtr head);
int count_list(NodePtr head);
NodePtr get_node(NodePtr head, int idx);
NodePtr find_first(NodePtr head, double value);

#endif
