#include <iostream>
using namespace std;

int main(void){
    int age[] = {16,48,72,66,23};
    for(int i=0;i<5;i++){
        if (age[i] < 20){
            cout << "Child" << endl;
        } else if (age[i] >= 20 && age[i] < 60){
            cout << "Adult" << endl;
        }else {
            cout << "Retired" << endl;
        }
    }
    return 0;
}