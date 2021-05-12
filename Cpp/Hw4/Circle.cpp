#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

class object{};

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

        circle (const object& o){}
        circle& operator=(const object& o){return *this;}
        operator object(){return object();}

        circle operator+(object& c){
            if (typeid(c)==typeid(circle)){
                circle C = c;
                C.r = this->r + C.getR();
                return C;
            }
            cout << "invalid type" << endl;
            return *this;
        }

        bool operator>(object& c){
            if(typeid(c)==typeid(circle)){
                circle C = c;
                return (C.Area() > this->Area());
            }
            cout << "invalid type" << endl;
            return false;
        }
        bool operator>(circle& c){return this->Area() > c.Area();}
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

        rect (const object& o){}
        rect& operator=(const object& o){return *this;}
        operator object(){return object();}
        
        rect operator+(rect& r){
            rect temp;
            temp.height = this->height + r.getH();
            temp.breadth = this-> breadth + r.getB();
            return temp;
        }
        rect operator+(object& r){
            if (typeid(r)==typeid(rect)){
                rect R = r;
                R.height = this->height + R.getH();
                R.breadth = this-> breadth + R.getB();
                return R;
            }
            cout << "invalid type" << endl;
            return *this;
        }
        bool operator<(object& r){
            if (typeid(r)==typeid(rect)){
                rect R = r;
                return this->Area() < R.Area();
            }
            cout << "invalid type" << endl;
            return false;
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
        Time operator+(object& t){
            if (typeid(t)==typeid(Time)){
                Time T = t;
                int Thours = T.getH() * 3600,Tminutes = T.getM() * 60;
                int Shours = this->getH() * 3600, Sminutes = this->getM() * 60;
                int total = Thours + Tminutes + T.getS() + Shours + Sminutes + this->getS();

                T.hours = this->hours + (double)total/3600;// edge cases
                T.minutes = this->minutes + (double)((total - total/3600)/60);
                T.seconds = this->seconds + (total - total/3600 - ((total - total/3600) - total/60));
                return T;
            }
            cout << "invalid type" << endl;
            return *this;
        }
        
        Time (const object& o){}
        Time& operator=(const object& o){return *this;}
        operator object(){return object();}

        bool operator<(object t){
            if (typeid(t)==typeid(Time)){
                Time T = t;
                int Thours = T.getH() * 3600,Tminutes = T.getM() * 60;
                int Shours = this->getH() * 3600, Sminutes = this->getM() * 60;
                int Ttotal = Thours + Tminutes + T.getS() ;
                int Stotal = Shours + Sminutes + this->getS();
                return (Ttotal < Stotal);
            }
            cout << "invalid type" << endl;
            return false;
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
    cout << boolalpha << compare << endl;
    circle c = b + a;
    compare = c > a;
    cout  << boolalpha<< compare << endl;
}
void test_rect(){
    rect a(2,2);rect b(3,3);
    bool compare = a < b;
    cout << boolalpha << compare << endl;
    rect c = b + a;
    compare = c < a;
    cout << boolalpha << compare << endl;
}
void test_time(){
    Time math(6,0,0); Time java(2,0,0); Time Cpp(4,0,0);
    bool compare = math < Cpp;
    cout<< boolalpha << compare << endl;
    Time programming = java + Cpp;
    compare = math < programming;
    cout << boolalpha << compare << endl;
}
int main(void){
    test_circle();
    test_rect();
    test_time();
    return 0;
}