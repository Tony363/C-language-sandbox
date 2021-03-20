#ifndef GSSTESTING_H
#define GSSTESTING_H

#include <iostream>
#include <vector>

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x) {if (!x) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

#endif