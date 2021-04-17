#ifndef AT_H
#define AT_H
#include <iostream>
using namespace std;

template<class T>
class Node{
    public:
        T Data;
        Node<T>* pprev;
        Node<T>* pnext;
        Node(T data);
        T getData();
        ~Node();
};

class Stack{
    public:
        Node<string>* head;
        Node<string>* tail;
        string dates;
        int Nabsences;
        Stack();
        Stack(string date);
        void push(string date);
        Node<string>* pop();
        string peek();
        bool isEmpty();
        ~Stack();
};

class Data{
    private:
    public:
        string recordNumber, IDnumber,credits,name,email,program,level;
        Stack* datesOfAbsence;
        Data();
        Data(string record,string ID,string AUcredit,string Name,string Email,string Program,string Level);
        void absent();
        tm* getTimeNow();
        ~Data();
};

template<class T>
class List{
    public:
        Node<T>* head;
        Node<T>* tail;
        bool test;
        List();
        List(T data);
        void addList(T data);
        void AbsentStudents();
        void AbsentStudents(bool test);
        void markAbsent(Node<T>* curr);
        void markAbsent(Node<T>* curr,string absent);
        void getReports(int type,int threshold=2);
        string getListNode(Node<T>* currNode);
        ~List();
};

class Menu{
    public:
        int option,loadtoMasterCount;
        bool test;
        List<Data>* master;
        List<string>* recordNArr;
        List<string>* IDArr;
        List<string>* nameArr;
        List<string>* emailArr;
        List<string>* creditsArr;
        List<string>* programArr;
        List<string>* levelArr;
        Menu();
        Menu(int option);
        void readCSV();
        void loadMasterList();
        void markAbsentStudents();
        void generateReports();
        void subMenu();
        ~Menu();
        void Options(int option);
};

class Tests{
    private:
    public:
        Menu* menu;
        Tests();
        bool testReadFile();
        bool testMarkStudentAbsence();
        bool testGenerateReport();
        ~Tests();
};

#endif