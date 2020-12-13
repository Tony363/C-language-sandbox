#include<stdio.h>
#include<minunit.h>
#include<binary_tree.h>
#include<stdlib.h>

MU_TEST(test_delete){
    int arr[10],count=0;
	double k;
	char str[3] = {0};
	TreeNodePtr root = NULL,prev = NULL;
    FILE * pFile = freopen("Texts/bst.txt","r",stdin);
	while (fgets(str,3,pFile)){
		if (count > 1){
			root = addToBST(root, (double)atoi(str));
		}
		count++;
	}

	printf("Remove specific value: ");
	scanf("%lf", &k);

	if (isInBST(root, k))
	{
		printf("Found \n");

	}
	else
	{
		printf("Not Found \n");
	}
	
	printf("Before:\n");
	printRoot(root);
	printf("\n");
	printf("removing %lf...\n", k);
	deleteRoot(root,k);
	printRoot(root);
	printf("\n");
    mu_check(isInBST(root, k)==0);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_delete);
} 

int main(int argc,char *argv[]){
    MU_RUN_SUITE(test_suite);    
	MU_REPORT();
	return MU_EXIT_CODE;
}