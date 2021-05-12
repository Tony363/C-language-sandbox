#include <iostream>
#include <cstring>
#include <string>
#include <typeinfo>
using namespace std;

class object{};

class student{
    private:
        int studentID;
        char* name;
        double gdp;
    public:
        student(){
            string str_obj("yourself");
            this->studentID=123456; 
            this->name = &str_obj[0];
            this->gdp=60.0;
            }
        ~student(){

        }
        // custom type conversion
        int getID(){return this->studentID;}
        char* getName(){return this->name;}
        double getGDP(){return this->gdp;}

        student (const object& o){}
        student& operator=(const object& o){return *this;}
        operator object(){return object();}
        
        bool operator==(object& s){
            if (typeid(s)==typeid(student)){
                student d = s;
                return (d.getID()==this->getID())
                 && (d.getName()==this->getName())  
                && (d.getGDP()==this->getGDP());
            }
            return false;
        }
        bool operator==(student& s){
            if (typeid(s)==typeid(student)){
                return (s.getID()==this->getID())
                 && (s.getName()==this->getName())  
                && (s.getGDP()==this->getGDP());
            }
            return false;
        }
};

void test_func(){
    student a;student b;
    bool compare = a==b;
    cout << boolalpha << compare << endl;
}
int main(void){
    test_func();
    return 0;
}