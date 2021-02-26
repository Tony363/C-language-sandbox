#include <iostream>
using namespace std;

typedef struct person{
    string name;
    int age;
    bool do_programming;
}person ;

ostream& operator<<(ostream& out,const person& Person)
{
   out << Person.name << " (" << to_string(Person.age) << ")" << endl;
   return out;
}

int main(void){
    person p1,p2;

    p1.name = "alice";
    p1.age = 20;
    p1.do_programming = true;
    p2.name = "bob";
    p2.age = 18;
    p2.do_programming = false;

    cout << p1 ;
    cout << p2 ;
    return 0;
}


