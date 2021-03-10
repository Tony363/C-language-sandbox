#include <iostream>
using namespace std;
struct Pixel {  
    int  column ;
    int  row;
};

void Display(Pixel P) ;

int main(void){
    Pixel X = {40,50}, Y , Z; 
    Z = X; 
    X. column +=10; 
    Y = Z; 
    Y. column += 10; 
    Y. row += 20; 
    Z. column  -= 15; 
    Display(X); 
    Display(Y); 
    Display(Z);
    return 0;
}

void Display(Pixel P){ 
    cout<<"Col: "<<P.column << " Row : "<<P.row<<endl;
}