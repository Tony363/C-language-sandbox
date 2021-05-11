#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class circle{
    private:
        double pi,r;

    public:
        circle(){
            this->pi=M_PI;
            this->r=0;
        }
        circle(double r){
            this->r=r;
            this->pi=M_PI;
            };
        ~circle(){};
        double getR(){return this->r;}
        double Area(){return (r*pi)*(r*pi);}
        circle operator+(circle& c){
            circle temp;
            temp.r = this->r + c.getR();
            return temp;
        }
        bool operator>(circle c){return this->Area() > c.Area();}
};

class rect{
    private:
        double height,breadth;
    public:
        rect(){
            this->height=0;
            this->breadth=0;
        }
        rect(double h,double b){
            this->height=h;
            this->breadth=b;
        }
        ~rect(){}

        double getH(){return this->height;}
        double getB(){return this->breadth;}
        double Area(){return (this->breadth)*(this->height);}
        rect operator+(rect& r){
            rect temp;
            temp.height = this->height + r.getH();
            temp.breadth = this-> breadth + r.getB();
            return temp;
        }
        bool operator<(rect r){return (this->Area() < r.Area());}
};

class Time{
    private:
        int hours,minutes,seconds;
    public:
        Time(){
            this->hours=0;
            this->minutes=0;
            this->seconds=0;
        }
        Time(int h,int m,int s){
            this->hours=h;
            this->minutes=m;
            this->seconds=s;
        }
        ~Time(){}
        int getH(){return this->hours;}
        int getM(){return this->minutes;}
        int getS(){return this->seconds;}

        void printTime(){
            cout << this->hours << ":"
                << this->minutes << ":"
                << this->seconds << ":"
                << endl;
        }
        Time operator+(Time& t){
            Time temp;
            int Thours = t.getH() * 3600,Tminutes = t.getM() * 60;
            int Shours = this->getH() * 3600, Sminutes = this->getM() * 60;
            int total = Thours + Tminutes + t.getS() + Shours + Sminutes + this->getS();

            temp.hours = this->hours + (double)total/3600;// edge cases
            temp.minutes = this->minutes + (double)((total - total/3600)/60);
            temp.seconds = this->seconds + (total - total/3600 - ((total - total/3600) - total/60));
            return temp;
        }
        bool operator<(Time t){
            int Thours = t.getH() * 3600,Tminutes = t.getM() * 60;
            int Shours = this->getH() * 3600, Sminutes = this->getM() * 60;
            int Ttotal = Thours + Tminutes + t.getS() ;
            int Stotal = Shours + Sminutes + this->getS();
            return (Ttotal < Stotal);
        }
};
void test_circle(){
    circle b(5);circle a(4);
    bool compare = a > b;
    cout << compare << endl;
    circle c = b + a;
    compare = c > a;
    cout << compare << endl;
}
void test_rect(){
    rect a(2,2);rect b(3,3);
    bool compare = a < b;
    cout << compare << endl;
    rect c = b + a;
    compare = c < a;
    cout << compare << endl;
}
void test_time(){
    Time math(6,0,0); Time java(2,0,0); Time Cpp(4,0,0);
    bool compare = math < Cpp;
    cout << compare << endl;
    Time programming = java + Cpp;
    compare = math < programming;
    cout << compare << endl;
}
int main(void){
    test_circle();
    test_rect();
    test_time();
    return 0;
}