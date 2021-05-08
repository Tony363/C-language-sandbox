#include <iostream>
#include <cstring>
#include <string>
using namespace std;

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

        int getID(){return this->studentID;}
        char* getName(){return this->name;}
        double getGDP(){return this->gdp;}

        bool operator==(student& s){
            return (s.getID()==this->getID()) 
                && (s.getName()==this->getName())  
                && (s.getGDP()==this->getGDP());
        }
};


int main(void){
    student a;student b;
    bool compare = a==b;
    cout << boolalpha << compare << endl;
    return 0;
}