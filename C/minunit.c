#include<stdio.h>
#include<minunit.h>
#include<second_greatest.h>

MU_TEST(test_minamum) {
    freopen("minamum_numbers.txt","r",stdin);
    int minamum = second_minamum();
    fclose(stdin);
	mu_check(minamum == 2);
}   

MU_TEST(test1) {
    freopen("test1.txt","r",stdin);
    int minamum = second_minamum();
    fclose(stdin);
	mu_check(minamum == 0);
} 
MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_minamum);
    MU_RUN_TEST(test1);
}    

int main(int argc,char *argv[]){
    MU_RUN_SUITE(test_suite);    
	MU_REPORT();
	return MU_EXIT_CODE;
}
