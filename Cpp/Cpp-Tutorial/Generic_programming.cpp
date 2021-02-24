#include <iostream>
using namespace std;

class Point;
std::ostream& operator<<(std::ostream& out, const Point& c);

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
    // private:
    //     int x,y;
    public:
        int x,y;
        Point(int a,int b){
            x = a;
            y = b;
        }
        Point& operator = (Point rhs)
        {
            // your code goes here
            x = rhs.x;y = rhs.y;
            return *this;
        }
};

int main() {

    Point p1(5,5), p2(100, 100);
    Swap (p1, p2);
  
    cout << "p1: " << p1 << "p2: " << p2 << std::endl;
    return 0;
}

std::ostream& operator<<(std::ostream& out, const Point& c)
{
   out<< "x:" << c.x << " ";
   out<< "y:" << c.y << "\n";
   return out;
}