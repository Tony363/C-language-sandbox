#include <iostream>
using namespace std;

class Point;
ostream& operator<<(ostream& out, const Point& c);

template<typename T>
void Swap(T &a, T&b)
{
    T temp = a;
    a = b;
    b = temp; 
}

class Point
{
    // Your code goes here
    private:
        int x,y;
    public:
        // int x,y;
        Point(){
            x=0;y=0;
            // cout << "wtf" << endl;
        }
        Point(int a,int b){
            x = a;
            y = b;
        }
        int getX() const{
            return x;
        }
        int getY() const {
            return y;
        }
        Point& operator = (Point rhs)
        {
            // your code goes here
            x = rhs.x;y = rhs.y;
            return *this;
        };
        Point& operator + (Point a)
        {
            x = a.x + x;
            y = a.y + y;
            return *this;
        };
};

int main() {

    Point p1(5,5), p2(100, 100);
    Swap (p1, p2);
    p1 = p2;
    Point p3;
    p3 = p3 + p1;
    cout << "p1: " << p1 << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    return 0;
}

ostream& operator<<(ostream& out,const Point& c)
{
   out<< "x:" << c.getX() << " ";
   out<< "y:" << c.getY() << "\n";
   return out;
}