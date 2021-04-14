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
            return this->degressKelvin;
        }
        inline double getCelsius(){
            return this->degressKelvin - 273.15; 
        }
        inline double getTempFahrenheit(){
            return ((this->degressKelvin - 273.15)/((double)5/(double)9))+32;
        }
        ~Temperature(){

        }
};

int main (void){

    return 0;
}