#include <iostream>
using namespace std;

typedef struct person{
    string name;
    int age;
    float salary;
}Person;


class myfriend{
    public:
        myfriend(){
            Person tony;
            cin >> tony.name >> tony.age >> tony.salary;
            cout << tony.name << tony.age << tony.salary << endl;
        }
        ~myfriend(){}
};
int main (void){
    myfriend tony;
    return 0;
}