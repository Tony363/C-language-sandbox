#include <iostream>
#define MAX_SIZE 16;
using namespace std;

class Class{
    public:
        Class();
        void getTwoNumbers();
        int makeSum();
        void print();
        void getOperands();
        void getData();
        void doAdd();
        void doSub();
        void doProduct();
        void doDiv();
        void printAll();
        void setSum();
        ~Class();
    private:
        char operand1,operand2;
        int sum,first,last,maxSize;
        int* data;
};

int main(void){
    Class SumObject1, SumObject2;
    SumObject1.getTwoNumbers();
    SumObject1.setSum();
    SumObject1.print();
    cout << "\n\n";
    SumObject2.getTwoNumbers();
    SumObject2.setSum();
    SumObject2.print();
    cout << "\n\n";
    SumObject1.getOperands();
    SumObject1.getData();
    SumObject1.printAll();
    return 0;
}

Class::Class(){
    sum = 0;
    first = 0;
    last = 0;
    maxSize = 0;
    operand1 = ' ';
    operand2 = ' ';
}

void Class::getTwoNumbers(){
    cout << "Enter First and Last Numbers for Class object ot make sum: " << endl;
    cin >> first >> last;
}

void Class::setSum(){
    sum = makeSum();
}

int Class::makeSum(){
    int sum=0;
    for (int i=0;i<last;i++){
        sum += i;
    }
    return sum;
}

void Class::print(){
    cout << "Sum from " << first << " to " << last << " = " << sum << endl;
}

void Class::getOperands(){
    cout << "Please enter operand: " << endl;
    cin >> operand1 >> operand2;
}

void Class::getData(){
    cout << "Please enter MAX_SIZE interger: " << endl;
    cin >> maxSize;
    data = new int[maxSize];
    for (int i=0;i<maxSize;i++){
        cout << "Please enter values until MAX_SIZE" << endl;
        cin >> data[i];
    }
}

void Class::doSub(){
    cout << "Subtracting Inputs: " << (double)first - (double)last << endl;
}

void Class::doAdd(){
    cout << "Adding Inputs: " << (double)first + (double)last << endl;
}

void Class::doProduct(){
    cout << "Multiplying Inputs: " << (double)first * (double)last << endl;
}

void Class::doDiv(){
    cout << "Dividing Inputs: " << (double)first / (double)last << endl;
}

void Class::printAll(){
    if (operand1 == '+' || operand2 == '+'){
        doAdd();
    } 
    if (operand1 == '-' || operand2 == '-'){
        doSub();
    }
    if (operand1 == '*' || operand2 == '*'){
        doProduct();
    }
    if (operand1 == '/'|| operand2 =='/'){
        doDiv();
    }
}
Class::~Class(){

}