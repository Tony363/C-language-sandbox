#include <iostream>
using namespace std;
/*
https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
*/
class Animal{
    public:
        // Constructor
        Animal():name_("Ani"),weight_(0.0){cout << "Animal::Animal( ), Animal Default Constructor" << endl;};
        Animal(string name, double weight);
        string getName(){return this->name_;}
        double getWeight(){return this->weight_;}
    private:
        // Member vars
        string name_;
        double weight_;
};

Animal::Animal(string name, double weight){
    this->name_ = name ;
    this->weight_ = weight ;
    cout << "Animal::Animal(..... ), Animal Overloaded Constructor" << endl;
}

class Dog : public Animal {
    public:
        Dog():Animal("DogXXX",200.2){cout << "Dog::Dog( ), Dog Default Constructor" << endl;};
        Dog(string name, double weight):Animal(name,weight){cout << "Dog Overloaded Constructor" << endl;};
        // Getters
        string getDogName() { return this->getName();}; // Return Animal's name_
        double getDogWeight() { return this->getWeight();}; // Return Dog's weight_
        // Methods
        void bark();
        double top_speed();
};

void Dog::bark(){
    cout << "woof woof" << endl;
}
double Dog::top_speed() {
    return (this->getDogWeight() < 40) ? 15.5 : (this->getDogWeight() < 90) ? 17.0 : 16.2;
}
int main(){
    Dog aDog, bDog("NameB", 23.4) ;
    return 0;
}