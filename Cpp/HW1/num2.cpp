#include <iostream>

using namespace std;

struct PLAY{
    int Bonus;
    int Score;
};

void Calculate(PLAY &p,int n=10){
    p.Score ++;
    p.Bonus += n;
}

int main(void){
    PLAY PL={10,15};
    Calculate(PL,5);
    cout<<PL.Score<<":"<<PL.Bonus<<endl;
    Calculate(PL);
    cout<<PL.Score<<":"<<PL.Bonus<<endl;
    Calculate(PL,15);
    cout<<PL.Score<<":"<<PL.Bonus<<endl;
    return 0;
}