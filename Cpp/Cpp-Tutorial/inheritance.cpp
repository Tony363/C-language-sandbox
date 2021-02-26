#include <iostream>
using namespace std;

class Point;
class Complex;
ostream& operator<<(ostream& out, const Complex& c);
ostream& operator<<(ostream& out, const Point& c);

class Point{
    private:
        int x,y;
    public:
    // int x,y;
        Point(){
            x = 0; y = 0;
        }
        Point(int c1,int c2){
            x = c1; y = c2;
        }
        Point& operator=(const Point a){
            x = a.x; y = a.y;
            return *this;
        }
        Point& operator+(const Point a){
            x = x + a.x; y = y + a.y;
            return *this;
        }
        int getX() const { return x; }
        int getY() const { return y; }
};

class Complex: public Point{
    // private:
    //     int &real,&imag;
    public:
        int c1,c2;
        Complex(int r,int i): Point(r,i)//,real(x),imag(y)
        {  
            c1 = r;c2 = i;
            cout << "Forming..." << *this;
        } 
        Complex& operator=(const Complex &a){
            // c1 = a.c1; c2 = a.c2;
            Complex::operator=(a);
            return *this;
        }
        int getc1()const{return c1;}
        int getc2()const{return c2;}
};
/*
Forming...x (real): 15 15 y (imag): 30 30
Forming...x (real): 100 100 y (imag): 200 200

c1: (Point) x:100 y:200
c2: x:15 y:30

c1: x (real): 100 100 y (imag): 200 100
c2: x (real): 15 15 y (imag): 30 30

*/
ostream& operator<<(ostream& out, const Complex& c){
    out << "x (real): " << c.getc1() << " " << c.getc1() << " ";
    out << "y (imag): " << c.getc2() << " " << c.getc2() << endl;
    return out;
}

ostream& operator<<(ostream& out, const Point& c){
    out << "x:" << c.getX() << " ";
    out << "y:" << c.getY() << endl;
    return out;
}

template<class T>
void SwapP(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    Complex c1(15, 30), c2 (100, 200);
    Point& p_c1 = c1; Point& p_c2 = c2;
    cout << endl;
    SwapP <Point> (p_c1, p_c2);  // swapping Complex objects as Point objects
    
    cout << "c1: (Point) " << p_c1 << "c2: " << p_c2 << endl;	    
    cout << "c1: " << c1 << "c2: " << c2 << endl;
    return 0;
}

// swap function for anything 