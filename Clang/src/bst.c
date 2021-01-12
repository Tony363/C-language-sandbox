
#include <stdio.h>
#include <stdlib.h>

typedef struct _TreeNode
{
	double key;
	struct _TreeNode *left, *right;
} TreeNode, *TreeNodePtr;

int getLevel()
{
	return 0;
}
// Give a value, test whether it is BST.
// Case 1: If the given key is NULL, return false.
// Case 2: If the given key is key in the root node, return true.
// Case 3: Whether it is in the left tree, do the recursive call, and return true.
// Case 4: Whether it is in the right tree, do the recursive call, and return true.
// Case 5: If the given key is different, then return false.
int isInBST(TreeNodePtr root, double key)
{
	if (root == NULL)
	{ // Case 1
		return 0;
	}
	else if (root->key == key)
	{ // Case 2
		return 1;
	}
	else if (isInBST(root->left, key))
	{ // Case 3
		return 1;
	}
	else if (isInBST(root->right, key))
	{ // Case 4
		return 1;
	}
	else
	{ // Case 5
		return 0;
	}

	// Single Line Expression (based on logic boolean calculation)
}

void printRoot(TreeNodePtr T)
{
	// if node itself is empty, end the procedure.
	if(T==NULL) return;
	// then print itself
	else printf("%lf::", T->key);
	// print the left with recursive call
	printRoot(T->left);
	// print the right with recursive call
	printRoot(T->right);
}

TreeNodePtr tranverseTree(TreeNodePtr T,TreeNodePtr prev,double key){
	TreeNodePtr tmp=NULL;
	if (T == NULL){
		return T;
	} else if (key < T->key){
		prev = T;
		tmp = T->left;
		return tranverseTree(tmp,prev,key);
	} else if (key > T->key){
		prev = T;
		tmp = T->right;
		return tranverseTree(tmp,prev,key);
	} else if (key == T->key) {
		if (prev == NULL){
			printf("invalid input\n");
			exit(0);
		}
		if (prev->right != NULL){
			if (T->right == NULL && T-> right == NULL){
				prev->right = NULL;
			}
			if (T->right != NULL){
				prev->right = T->right;
			}   
			if (T->left != NULL){
				prev->left = T->left;
			}
		} else if (prev->left != NULL ){
			if (T->left == NULL && T-> right == NULL){
				prev->left = NULL;
			}
			if (T->left != NULL){
				prev->left = T->left;
			}
			if (T->right != NULL){
				prev->right = T->right;
			}
		} 
	}
}
TreeNodePtr deleteRoot(TreeNodePtr root,double key)
{
	TreeNodePtr prev=NULL;
	tranverseTree(root,prev,key);
}

// Allow a null pointer here.
// Case 1: When root node is null.
// Case 2: When the root node has value, same as key, do nothing, return itself.
// Case 3: When the root node has value, larger than key, add to the left, do the recursive call.
// Case 4: When the root node has value, less than key, add to the right, do the recursive call.
TreeNodePtr addToBST(TreeNodePtr root, double key)
{
	if (root == NULL)
	{ // Case 1
		TreeNodePtr n = (TreeNodePtr)malloc(sizeof(TreeNode));
		n->key = key;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	if (root->key == key)
	{ // Case 2
		return root;
	}
	if (key < root->key)
	{ // Case 3
		root->left = addToBST(root->left, key);
		return root;
	}
	else
	{ // Case 4
		root->right = addToBST(root->right, key);
		return root;
	}
	return root;
}

// int main(int argc, char **argv)
// {
// 	int i;
// 	double k;
// 	TreeNodePtr root = NULL,prev = NULL;
// 	if (argc > 1)
// 	{
// 		printf("%d",argc);
// 		for (i = 2; i < argc; i++)
// 		{
// 			double d;
// 			sscanf(argv[i], "%lf", &d);
// 			root = addToBST(root, d);
// 		}
// 	}

// 	printf("Remove specific value: ");
// 	scanf("%lf", &k);

// 	if (isInBST(root, k))
// 	{
// 		printf("Found \n");

// 	}
// 	else
// 	{
// 		printf("Not Found \n");
// 	}
	
// 	printf("Before:\n");
// 	printRoot(root);
// 	printf("\n");
// 	printf("removing %lf...\n", k);
// 	deleteRoot(root,k);
// 	printRoot(root);
// 	printf("\n");
// 	return 0;
// }