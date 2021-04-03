#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
using namespace std;

tm* getTimeNow(){
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return localtm;
}

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
        string getDate(){
            return dates;
        }
        ~Node(){
            cout << "class template Node destroyed" << endl;
        }
};
template <class INT,class STR>
class Stack{
    Node<INT,STR>* head=NULL;
    Node<INT,STR>* prev=NULL;
    Node<INT,STR>* tail=NULL;
    public:
        Stack(string date){
            this->head = new Node(dates);
            this->tail = this->head;
            this->prev = NULL;
        }
        void push(string date){
            this->tail->pnext = new Node(date);
            this->prev = this->tail;
            this->tail = this->tail->pnext;
        }
        Node<INT,STR>* pop(){
            Node<INT,STR* temp = this->tail;
            this->tail = this->prev;
            return temp;
        }
        string peek(){
            return this->tail->getDate();
        }
        bool isEmpty(){
            if(head==NULL || tail==NULL){
                return true;
            }
            return true;
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
    Data* tail;
    public:
        List(){
            cout << "Master List instantiated" << endl;
        }
        List(INT record,INT ID,INT AUcredit,STR Name,STR Email,STR Program,STR Level){
            Data* Head = new Data(record,ID,AUcredit,Name,Email,Program,Level);
            this->head = Head;  
            this->tail = this->head; 
        }
        void addList(INT record,INT ID,INT AUcredit,STR Name,STR Email,STR Program,STR Level){
            Data* data = new Data(record,ID,AUcredit,Name,Email,Program,Level);
            this->tail->pnext = data;
            this->tail = this->tail->pnext;
        }
        ~List(){
            cout << "Master List destroyed" << endl;
        }
};

class Menu{
    public:
        int option;
        Menu(){
            cout << "Option 1: Reads the .csv course file and overwrites the master list\n"
                << "Option 2: Populates the master list with previous nodes from master.txt\n"
                << "Option 3: Stores the contents of teh master list's nodes to master.txt\n"
                << "Option 4: Runs through the master list, displays each student's name and prompts if he/she was absent for the current day.\n"
                << "Option 5: Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit\n"
                << "Option 6: Leads to submenu ->\n1. Generate report for all students;\nshowing only the most recent absence for each student.\n2.Generate report for students with absences that match for exceeed(int prompt by user)"
                << "Option 7: Exit the program\n"
                << endl;
            cin >> option;
            Options(option);
        }
        void readCSV(){
            ifstream infile;
            infile.open("records.txt");
            if (infile.is_open()){
                string line,recordN,ID,name,email,credits,program,level;
                while(getline(infile,line)){
                    stringstream ss;
                    ss << line;
                    getline(ss,recordN,',');
                    getline(ss,ID,',');
                    getline(ss,name,',');
                    getline(ss,email,',');
                    getline(ss,credits,',');
                    getline(ss,program,',');
                    getline(ss,level,',');
                }
            }else{
                cout << "Unable to open file" << endl;
            }
            infile.close();
        }
        void Options(int option){
            switch(option){
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    ~Menu();
            }
        }
        ~Menu(){
            cout << "exiting program....." << endl;
        }
};

int main(void){

    return 0;
}