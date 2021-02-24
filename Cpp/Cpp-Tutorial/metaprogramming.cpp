#include <iostream> 
using namespace std; 

// write code here
template<unsigned int n>
struct power2{
    enum{val = 2 * power2<n-1>::val};
};

template <>
struct power2<0>{
    enum{val=1};
};

int main() 
{ 
    cout << power2<8>::val << endl; 
    return 0; 
} 