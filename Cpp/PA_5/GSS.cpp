#include <iostream>
#include <cstdlib>
#include <time.h>
#include <assert.h>
#include <Gss.h>

using namespace std;

// Function to test
bool function1(int a) {
    return a > 5;   
}

int genRand(bool laneType) {
    srand(time(NULL));
    if (laneType == true)
        return 1 + (rand() % (5 - 1 + 1) );
    return 3 + (rand() % (8 - 3 + 1) );
}

bool inRange(int randInt,bool laneType){
    if (laneType == true)
        return  (1 <= randInt && 5 >= randInt);
    return  (3 <= randInt && 8 >= randInt); 
}

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x) { if (!x) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }


// Test for function1()
// You would need to write these even when using a framework
void test_function1(){
    // IS_TRUE(!function1(0));
    // IS_TRUE(!function1(5));
    // IS_TRUE(function1(10));
    // IS_TRUE(function1(0));
    assert(inRange(getRand(true)));
}

int main(void) {
    // Call all tests. Using a test framework would simplify this.
    test_function1();
}
