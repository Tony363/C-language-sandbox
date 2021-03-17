#include <iostream>

using namespace std;

struct Pixels{ 
    int Color, Style;
};

void ShowPoint(Pixels P){
    cout<<P.Color<<P.Style<<endl;
}

int main(void){ 
    Pixels Point1={5,3}; 
    ShowPoint(Point1); 
    Pixels Point2=Point1; 
    Point1.Color+=2; 
    ShowPoint(Point2);
    return 0;
}
