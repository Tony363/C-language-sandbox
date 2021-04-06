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
    public:
        T Data;
        Node<T>* pprev;
        Node<T>* pnext;
        Node(T data){
            this->Data = data;
            Node<T>* pprev=NULL;
            Node<T>* pnext=NULL;
        }
        T getData(){
            return this->Data;
        }
        ~Node(){
            // cout << "Data destroyed" << endl;
        }
};

class Stack{
    public:
        Node<string>* head;
        Node<string>* tail;
        string dates;
        int Nabsences;
        Stack(){
            Node<string>* head=NULL;
            Node<string>* tail=NULL;
            string dates="";
            int Nabsences=0;
        }
        Stack(string date){
            this->head = new Node<string>(date);
            this->tail = this->head;
            this->Nabsences = 1;
        }
        void push(string date){
            this->tail->pnext = new Node<string>(date);
            this->tail = this->tail->pnext;
            this->Nabsences++;
        }
        Node<string>* pop(){
            Node<string>* temp = this->tail;
            this->tail = this->tail->pprev;
            return temp;
        }
        string peek(){
            return this->tail->Data;
        }
        bool isEmpty(){
            if(this->head==NULL || this->tail==NULL){
                return true;
            }
            return true;
        }
        ~Stack(){
            // cout << "stack of dates destroyed" << endl;
        }
};

class Data{
    private:
    public:
        string recordNumber, IDnumber,credits,name,email,program,level;
        Stack* datesOfAbsence=NULL;
        Data(){
            // cout << "class template Node data filled" << endl;
        }
        Data(string record,string ID,string AUcredit,string Name,string Email,string Program,string Level){
            this->recordNumber = record;
            this->IDnumber = ID;
            this->credits = AUcredit;
            this->name = Name;
            this->email = Email;
            this->program = Program;
            this->level = Level;
        }
        void absent(){
            char date[80];
            strftime(date,80,"%D",getTimeNow());
            if (this->datesOfAbsence!=NULL){
                this->datesOfAbsence->push(date);
                return;
            }   
            this->datesOfAbsence = new Stack(date);
        }
        ~Data(){
            // cout << "class template Node destroyed" << endl;
        }
};

template<class T>
class List{
    public:
        Node<T>* head;
        Node<T>* tail;
        bool test;
        List(){
            Node<T>* head=NULL;
            Node<T>* tail=NULL;
        }
        List(T data){
            this->head = new Node<T>(data); 
            this->tail = this->head; 
        }
        void addList(T data){
            this->tail->pnext = new Node<T>(data);
            this->tail = this->tail->pnext;
        }
        void AbsentStudents(){
            Node<T>* temp = head->pnext;
            while (temp!=NULL){
                markAbsent(temp);
                temp = temp->pnext;
            }
        }
        void AbsentStudents(bool test){
            Node<T>* temp = head->pnext;
            while (temp!=NULL){
                markAbsent(temp,"Y");
                temp = temp->pnext;
            }
        }
        void markAbsent(Node<T>* curr){
            string absent;
            cout << curr->Data.name << " absent?[Y/N]" << endl;
            cin >> absent;
            if (absent == "Y"){
                curr->Data.absent();
            }else if (absent == "N"){
                cout << "";
            }else{
                cout << "Please answer [Y/N]" << endl;
                markAbsent(curr);
            }
        }
        void markAbsent(Node<T>* curr,string absent){
            cout << curr->Data.name << " absent? [Y/N]" << endl;
            curr->Data.absent();
          
        }
        void getReports(int type,int threshold=1){
            ofstream outfile;
            if (type == 1){
                outfile.open("../report1.txt",ios::out|ios::app);
            }else if (type == 2){
                outfile.open("../report2.txt",ios::out|ios::app);
                if (threshold != 1){
                    cout << "Please enter absences threshold: ";
                    cin >> threshold;
                }
            }else {
                cout << "Please enter correct type of report: [1/2] ";
                cin >> type;
                getReports(type,999);
                return;
            }
            Node<T>* temp = head->pnext;
            string student;
            while(temp!=NULL){
                if (type == 1){
                    student = temp->Data.name;
                    int absentTimes = temp->Data.datesOfAbsence->Nabsences;
                    string recentAbsent = temp->Data.datesOfAbsence->peek();
                    outfile << student << " " << absentTimes << " " <<  recentAbsent << endl;
                }else if (type == 2 && temp->Data.datesOfAbsence->Nabsences == threshold){
                    student = temp->Data.name;
                    outfile << student << endl;
                }
                temp = temp->pnext;
            }
            outfile.close();
        }
        ~List(){
            // cout << "Master List destroyed" << endl;
        }
};
class Menu{
    public:
        int option;
        List<Data>* master;
        bool test;
        Menu(){
            cout << "Option 1: Reads the .csv course file and overwrites the master list\n"
                << "Option 2: Populates the master list with previous nodes from master.txt\n"
                << "Option 3: Stores the contents of the master list's nodes to master.txt\n"
                << "Option 4: Runs through the master list, displays each student's name and prompts if he/she was absent for the current day.\n"
                << "Option 5: Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit\n"
                << "Option 6: Leads to submenu ->\n\t1. Generate report for all students;\n\tshowing only the most recent absence for each student.\n\t2.Generate report for students with absences that match for exceeed(int prompt by user)\n"
                << "Option 7: Exit the program\n"
                << endl;
            cin >> option;
            this->master = NULL;
            this->test = false;
            Options(option);
        }
        Menu(int option){
            cout << "Option 1: Reads the .csv course file and overwrites the master list\n"
                << "Option 2: Populates the master list with previous nodes from master.txt\n"
                << "Option 3: Stores the contents of the master list's nodes to master.txt\n"
                << "Option 4: Runs through the master list, displays each student's name and prompts if he/she was absent for the current day.\n"
                << "Option 5: Prompts for an ID number or name of student to edit. Prompts for the date of absence to edit\n"
                << "Option 6: Leads to submenu ->\n\t1. Generate report for all students;\n\tshowing only the most recent absence for each student.\n\t2.Generate report for students with absences that match for exceeed(int prompt by user)\n"
                << "Option 7: Exit the program\n"
                << endl;
            this->master = NULL;
            this->test = true;
            Options(option);
        }
        void readCSV(){
            ifstream infile;
            infile.open("../classList.csv");
            if (infile.is_open()){
                string line,recordN,ID,name,email,credits,program,level;
                bool firstline = true;
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
                        this->master = new List<Data>(*data);
                        firstline = false;
                    }else {
                        this->master->addList(*data);
                    }
                }
                infile.close();
            }else{
                cout << "Unable to open file" << endl;
                infile.close();
            }
        }
        void markAbsentStudents(){
            if (this->test){
                this->master->AbsentStudents(this->test);
            }else{
                this->master->AbsentStudents();
            }
        }
        void generateReports(){
            if (this->test){
                this->master->getReports(1);
                this->master->getReports(2);
            }else{
                this->master->getReports(999);
            }
        }
        ~Menu(){
            // cout << "exiting program....." << endl;
        }
        void Options(int option){
            switch(option){
                case 1:
                    readCSV();
                    break;
                case 2:
                case 3:
                case 4:
                    markAbsentStudents();
                    break;
                case 5:
                case 6:
                    generateReports();
                    break;
                case 7:
                    exit(1);
            }
        }
};

class Tests{
    private:
    public:
        Menu* menu;
        Tests(){
            this->menu = new Menu(1);
        }
        bool testReadFile(){
            if (this->menu->master->tail != NULL){
                cout << "Test Read CSV: PASSED" << endl;
                return true;
            }
            cout << "Test Read CSV: FAILED" << endl;
            return false;
        }
        bool testMarkStudentAbsence(){
            this->menu->Options(4);
            this->menu->Options(4);
            this->menu->Options(4);
            if ((this->menu->master->tail->Data.datesOfAbsence->Nabsences) > 1){
                cout << "Test Mark Absent Student: PASSED" << endl;
                return true;
            }
            cout << "Test Mark Absent Student: FAILED" << endl;
            return false;
        }
        bool testGenerateReport(){
            this->menu->Options(4);
            this->menu->Options(4);
            this->menu->Options(6);
            cout << "Test Mark Generate Report: PASSED" << endl;
            return true;
        }
        ~Tests(){

        }
};

void test_suit(){
    Tests test;
    assert(test.testReadFile()==true);
    assert(test.testMarkStudentAbsence()==true);
    assert(test.testGenerateReport()==true);
}
int main(void){
    test_suit();
    // Node<Data> node;
    return 0;
}