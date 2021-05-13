#include <iostream>
#include <fstream>
using namespace std;

class ID{
    friend std::ostream& operator<<(std::ostream& out,ID& id);
    private:
        int SID;
    public:
        ID():SID(0){}
        ID(int id):SID(id){}
        ~ID(){}
        int getID(){return this->SID;}
        int getModID(){return ((this->SID)%5) + 1;}
        void setID(int id){this->SID=id;}
};
class cGoogleCompany:public ID{
    public:
        cGoogleCompany(int id):ID(id){};
        ~cGoogleCompany(){}
};
class cIITDepartment:public ID{
    public:
        cIITDepartment(int id):ID(id){};
        ~cIITDepartment(){};
};
class cJiasoxiTownship:public ID{
    public:
        cJiasoxiTownship(int id):ID(id){};
        ~cJiasoxiTownship(){};
};
class cMyMobile:public ID{
    public:
        cMyMobile(int id):ID(id){};
        ~cMyMobile(){};
}; 
class cCPPCourse:public ID{
    public:
        cCPPCourse(int id):ID(id){};
        ~cCPPCourse(){};
};

ostream& operator<<(std::ostream& out,ID& id){
    out << "You ID is: " 
        << id.getID() << "\n"
        << "ID % 5 + 1 = " 
        << id.getModID() 
        << endl;
    return out;
}
void test_suite(){
    cGoogleCompany* cg = new cGoogleCompany(409840317);
    cIITDepartment* ci = new cIITDepartment(409840317);
    cJiasoxiTownship* cj = new cJiasoxiTownship(409840317);
    cMyMobile* cm = new cMyMobile(409840317);
    cCPPCourse* cp = new cCPPCourse(409840317);
    cout << *cg << endl;
    cout << *ci << endl;
    cout << *cj << endl;
    cout << *cm << endl;
    cout << *cp << endl;
}
int main(void){
    test_suite();
    return 0;
}