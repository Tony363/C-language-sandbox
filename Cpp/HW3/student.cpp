#include<iostream>
using namespace std;

class student{
    private:
        int studentID;
        string name;
        double gpa;
    public:
        student(){
            this->studentID = 123456;
            this->name = "yourself";
            this->gpa = 60.0;
        };
        void display(){
            cout << "Student ID: " 
                << this->studentID << "\n"
                << "Name: " 
                << this->name << "\n"
                << "GPA: " 
                << this->gpa << "\n"
                << endl;
        }
        ~student(){};
};

int main(void){
    student Student;
    Student.display();
    return 0;
}