#include <iostream>

using namespace std;

class Temperature{
    private:
        double degressKelvin,constant;
    public:
        Temperature(){
            this->degressKelvin = 0;
            this->constant = 1;
        };
        void setConst(double converter){
            this->constant = ((double)5/(double)9)*((double)converter-32);
        }
        void setTempKelvin(double kelvin){
            this->degressKelvin = kelvin;
        }
        void setTempFahrenheit(double fahrenheit){
            setConst(fahrenheit);
            this->degressKelvin = this->constant + 273.15;
        }
        void setTempCelsius(double celsius){
            setConst(celsius);
            this->degressKelvin = this->constant;
        }
        inline double getTempKelvin(){
            double kelvin = this->degressKelvin;
            return kelvin;
        }
        inline double getTempCelsius(){
            double celsius = this->degressKelvin - 273.15;
            return celsius; 
        }
        inline double getTempFahrenheit(){
            double fahrenheit = ((this->degressKelvin - 273.15)/((double)5/(double)9))+32;
            return fahrenheit;
        }
        ~Temperature(){

        }
};

int main (void){
    Temperature temp;
    temp.setTempKelvin(100);
    cout << "Kelvin Input: " << temp.getTempKelvin() << endl;
    temp.setTempFahrenheit(100);
    cout << "Fahrenheit Input: " << temp.getTempFahrenheit() << endl;
    temp.setTempCelsius(100);
    cout << "Celsius Input: " << temp.getTempCelsius() << endl;
    return 0;
}