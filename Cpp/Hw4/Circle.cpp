#include <iostream>
#include <cmath>

using namespace std;

class circle{
    private:
        double pi,r;

    public:
        circle(double r){
            this->r=r;
            this->pi=M_PI;
            };
        ~circle(){};
        double getR(){return this->r;}
        double Area(){return (r*pi)*(r*pi);}
        void operator+(circle c){
            this->r += c.getR();
        }
        bool operator>(circle c){return this->Area() > c.Area();}
};

class rect{
    private:
        double height,breadth;
    public:
        rect(double h,double b){
            this->height=h;
            this->breadth=b;
        }
        ~rect(){}

        double getH(){return this->height;}
        double getB(){return this->breadth;}
        double Area(){return (this->breadth)*(this->height);}
        void operator+(rect r){
            this->breadth += r.getB();
            this->height += r.getH();
        }
        bool operator<(rect r){return (this->Area() < r.Area());}
};

class time{
    private:
        int hours,minutes,seconds;
    public:
        time(){
            this->hours=0;
            this->minutes=0;
            this->seconds=0;
        }
        ~time(){}
        int getH(){return this->hours;}
        int getM(){return this->minutes;}
        int getS(){return this->seconds;}

        void printTime(){
            cout << this->hours << ":"
                << this->minutes << ":"
                << this->seconds << ":"
                << endl;
        }
        void operator+(time t){
            int Thours = t.getH() * 3600,Tminutes = t.getM() * 60;
            int Shours = this->getH() * 3600, Sminutes = this->getM() * 60;
            int total = Thours + Tminutes + t.getS() + Shours + Sminutes + this->getS();

            this->hours += (double)total/3600;// edge cases
            this->minutes += (double)((total - total/3600)/60);
            this->seconds += (total - total/3600 - ((total - total/3600) - total/60));
        }
        bool operator<(time t){
            int Thours = t.getH() * 3600,Tminutes = t.getM() * 60;
            int Shours = this->getH() * 3600, Sminutes = this->getM() * 60;
            int Ttotal = Thours + Tminutes + t.getS() ;
            int Stotal = Shours + Sminutes + this->getS();
            return (Ttotal < Stotal);
        }
};
int main(void){
    return 0;
}