#include <iostream>
#include <vector>
using namespace std;

template <class INT,class STR>
class Node{
    INT recordNumber, IDnumber,credits;
    STR name,email,program,level;
    Node* pnext;
    private:
        string dates;
        int Nabsences;
    public;
        Node(){
            cout << "class template Node data filled" << endl;
        }
        Node(string date){
            this->dates = dates;
            this->Nabsences = 0;
        }
        ~Node(){
            cout << "class template Node destroyed" << endl;
        }
};
template <class INT,class STR>
class Stack{
    Node<INT,STR>* head;
    Node<INT,STR>* tail;
    public:
        Stack(string date){
            this->head = new Node(dates);
            this->tail = this->head;
        }
        void addAbsence(string date){
            this->tail->pnext = new Node(date);
            this->tail = this->tail->pnext;
        }
        ~Stack(){
            cout << "stack of dates destroyed" << endl;
        }
};

template<class INT,class STR>
class Data:public Node<INT,STR>{
    Stack* datesOfAbsence;
    public:
        Data(INT record,INT ID,INT AUcredit,STR Name,STR Email,STR Program,STR Level){
            this->recordNumber = record;
            this->IDnumber = ID;
            this->credits = AUcredit;
            this->name = Name;
            this->email = Email;
            this->program = Program;
            this->level = Level;
            this->pnext = NULL;
            this->datesOfAbsence = new Stack(string date,int absences);
        }
        ~Data(){
            cout << "Data destroyed" << endl;
        }
};

template<class INT,class STR>
class List{
    Data* head;
    public:
        List(INT record,INT ID,INT AUcredit,STR Name,STR Email,STR Program,STR Level){
            Data* Head = new Data(record,ID,AUcredit,Name,Email,Program,Level);
            this->head = Head;
            cout << "Master List instantiated" << endl;
        }
        ~List(){
            cout << "Master List destroyed" << endl;
        }
};


int main(void){

    return 0;
}