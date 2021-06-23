#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class iotDriver{
    public:
        iotDriver(){};
        iotDriver(string name){
            this->dname = name.c_str();
        }
        iotDriver(string name,int ioNumber){
            this->dname = name.c_str();
            this->ioNumber=ioNumber;
        }
        ~iotDriver(){};
        void setName(string name){
            this->dname = name.c_str();
        }
        string getName(){return this->dname;}
        void setIo(int ioNumber){this->ioNumber=ioNumber;}
        int getIo(){return this->ioNumber;}
        virtual void dispInfo() = 0;
    private:
        const char* dname={0};
        int ioNumber=26;
};
class Arduino: public iotDriver{
    public:
        Arduino():iotDriver(){};
        Arduino(string name,int ioNumber):iotDriver(name,ioNumber){};
        ~Arduino(){};
        void dispInfo(){
            cout << "Name: " 
                << iotDriver::getName() << "\n"
                << "ioNumber: "
                << (float)iotDriver::getIo() 
                << endl;
        };
    private:
};
class RaspberyPI:public iotDriver{
    public:
        RaspberyPI(){};
        RaspberyPI(string name,int ioNumber):iotDriver(name,ioNumber){};
        ~RaspberyPI(){};
        void dispInfo(){
            cout << "Name: "
                << this->getName() << "\n"
                << "ioNumber: " 
                << this->getIo()
                << endl;
        }
    private:
};
int main(void){
    Arduino ar("Arduino",10);
    RaspberyPI ras("RaspberryPI",11);
    ar.dispInfo();
    ras.dispInfo();
    return 0;
}
