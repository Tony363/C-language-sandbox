#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <assert.h>
using namespace std;

tm* getTimeNow(){
    time_t now = time(0);
    tm* localtm = localtime(&now);
    return localtm;
}

template<class T>
class Node{
    T Data;
    public:
        Node<T>* pprev;
        Node<T>* pnext;
        Node(T data){
            this->Data = data;
            this->pprev = nullptr;
            this->pnext = nullptr;
        }
        T getData(){
            return this->Data;
        }
        ~Node(){
            cout << "Data destroyed" << endl;
        }
};

class Stack{
    public:
        Node<string>* head;
        Node<string>* tail;
        string dates;
        int Nabsences;
        Stack(){
            this->head=nullptr;
            this->tail=nullptr;
        }
        Stack(string date){
            this->head = new Node<string>(date);
            this->tail = this->head;
        }
        void push(string date){
            this->tail->pnext = new Node<string>(date);
            this->tail = this->tail->pnext;
        }
        Node<string>* pop(){
            Node<string>* temp = this->tail;
            this->tail = this->tail->pprev;
            return temp;
        }
        string peek(){
            return this->tail->getData();
        }
        bool isEmpty(){
            if(this->head==nullptr || this->tail==nullptr){
                return true;
            }
            return true;
        }
        ~Stack(){
            cout << "stack of dates destroyed" << endl;
        }
};

class Data{
    string recordNumber, IDnumber,credits,name,email,program,level;
    Stack* datesOfAbsence;
    private:
    public:
        Data(){
            cout << "class template Node data filled" << endl;
        }
        Data(string record,string ID,string AUcredit,string Name,string Email,string Program,string Level){
            this->recordNumber = record;
            this->IDnumber = ID;
            this->credits = AUcredit;
            this->name = Name;
            this->email = Email;
            this->program = Program;
            this->level = Level;
            char buffer[80];
            strftime(buffer,80,"%D",getTimeNow());
            this->datesOfAbsence = new Stack(buffer);
        }
        ~Data(){
            cout << "class template Node destroyed" << endl;
        }
};

template<class T>
class List{
    public:
        Node<T>* head;
        Node<T>* tail;
        List(){
            this->head = NULL;
            this->tail = NULL;
        }
        List(T data){
            this->head = new Node<T>(data);;  
            this->tail = this->head; 
        }
        void addList(T data){
            this->tail->pnext = new Node<T>(data);
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
                << "Option 3: Stores the contents of the master list's nodes to master.txt\n"
                << "Option 4: Runs through the master list, displays each student's name and prompts if he/she was absent for the current day.\n"
                << "Option 5: Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit\n"
                << "Option 6: Leads to submenu ->\n1. Generate report for all students;\nshowing only the most recent absence for each student.\n2.Generate report for students with absences that match for exceeed(int prompt by user)"
                << "Option 7: Exit the program\n"
                << endl;
            cin >> option;
            Options(option);
        }
        bool readCSV(){
            ifstream infile;
            infile.open("../classList.csv");
            if (infile.is_open()){
                string line,recordN,ID,name,email,credits,program,level;
                bool firstline = true;
                List<Data>* master = NULL;
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
                    Data* data = new Data(recordN,ID,credits,name,email,program,level);
                    if (firstline){
                        List<Data>* master = new List<Data>(*data);
                        firstline = false;
                    }
                    master->addList(*data);
                }
                infile.close();
                return true;
            }else{
                cout << "Unable to open file" << endl;
                infile.close();
                return false;
            }
        }
        ~Menu(){
            cout << "exiting program....." << endl;
        }
        void Options(int option){
            switch(option){
                case 1:
                    readCSV();
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                    exit(1);
            }
        }
};

class Tests{
    private:
    public:
        Tests(){

        }
        bool testReadFile(){
            Menu menu;
            if (menu.readCSV()){
                return true;
            }
            return false;
        }
        ~Tests(){

        }
};

void test_suit(){
    Tests test;
    assert(test.testReadFile()==true);
}
int main(void){
    test_suit();
    // Node<Data> node;
    return 0;
}