#include <iostream>
#include <vector>
using namespace std;
using std::vector;

void print(const std::vector<int>& ivec, std::vector<int>::const_iterator it) {
    if (it == ivec.end())
        return;
    std::cout << *it++ << std::endl;
    print(ivec, it);
}

int main(){
    vector<int> v{
        5, 7, 77, 23, 10, 81
    };

    print(v, v.begin()); // ok

    vector<int>::iterator it = v.begin();
    auto v2{ v };

    if (it == v.begin())
        cout << "it = v.begin()" << endl;
    if (it == v2.begin()) // causes crash
        cout << "it =v2.begin()" << endl;
}