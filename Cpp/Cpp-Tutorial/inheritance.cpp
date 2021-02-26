#include <iostream>
using namespace std;

class Point{
    // private:
        // int x,y;
    public:
    int x,y;
        Point(){
            x = 0; y = 0;
        }
        Point(int c1,int c2){
            x = c1; y = c2;
        }
        Point& operator=(Point a){
            x = a.x; y = a.y;
            return *this;
        }
        Point& operator+(Point a){
            x = x + a.x; y = y + a.y;
            return *this;
        }
        int getX() const { return x; }
        int getY() const { return y; }
};

ostream& operator<<(ostream& out, const Point& c){
    out << "Point: " << c.getX() << endl;
    out << "Point: " << c.getY() << endl;
    return out;
}

class Complex: public Point{
    private:
        int &real,&imag;
    public:
        Complex(int r,int i): Point(r,i),real(x),imag(y)
        { cout << "Forming.....\n" << *this << endl ;} 
        // Point& operator=(Point a){
        //     real = a.x; imag = a.y;
        //     return *this;
        // }
};

ostream& operator<<(ostream& out, const Complex& c){
    out << "Complex x: " << c.getX() << endl;
    out << "Complex y: " << c.getY() << endl;
    return out;
}



// template<typename T>
void swap(Complex a,Complex b){
    Complex temp = a;
    a = b;
    b = temp;
}

int main()
{
    Complex c1(15, 15), c2 (100, 100);
    // swap(c1,c2);
    cout << c1;
    cout << c2;
    return 0;
}


