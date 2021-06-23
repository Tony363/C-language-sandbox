#include <iostream>

using namespace std;


class Rectangle{
    public:
        Rectangle(){};
        Rectangle(int len,int wid):length(len),width(wid){};
        ~Rectangle(){};
        void setLen(int len){this->length=len;}
        void setWid(int wid){this->width=wid;}
        int getLen(){return this->length;}
        int getWid(){return this->width;}
        int getArea(){return this->getLen()*this->getWid();}
        void Display(){
            cout << "Length: " 
                << this->getLen() << "\n"
                << "Width: "
                << this->getWid()
                << endl; 
        }
    private:
        int length,width;
};

class Block: public Rectangle{
    public:
        Block(){};
        Block(int len,int wid,int height):Rectangle(len,wid){
            this->height=height;
        };
        ~Block(){};
        void setH(int height){this->height=height;}
        int getH(){return this->height;}
        int getArea(){return Rectangle::getArea()*this->getH();}
        void Display(){
            Rectangle::Display();
            cout << "Height: " 
                << this->height 
                << endl;
        }
    private:
        int height;
};
int main(void){
    Rectangle rect(2,3);
    rect.Display();
    cout << "rect Area " << rect.getArea() << endl;
    Block cube(2,2,2);
    cube.Display();
    cout << "cube Volume " << cube.getArea() << endl;
    return 0;
}