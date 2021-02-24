#include <iostream>
using namespace std;

struct person{
    string name;
    int age;
    bool do_programming;
};

int main(void){
    person p1,p2;

    p1.name = "alice";
    p1.age = 20;
    p1.do_programming = true;
    p2.name = "bob";
    p2.age = 18;
    p2.do_programming = false;
    cout << p1.name << p1.age ;
    printf("%s (%d)",p1.name,p1.age);
    cout << p1.name << " (" << p1.age << ")" << endl;
    cout << p2.name << " (" << p2.age << ")" << endl;
    return 0;
}