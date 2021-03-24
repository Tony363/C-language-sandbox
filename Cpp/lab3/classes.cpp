#include <iostream>

using namespace std;

const int ARRAY_SIZE = 12;

class myArrayClass{
    private:
        double data[ARRAY_SIZE];
        double max;
        double min;
        double aver;
        double userInput;
        double total;
        int size;
    public:
        myArrayClass(){
            total = 0;
            aver = 0;
            min = 0;
            max = 0;
        }
        void getData(){
            for (int i=0;i<ARRAY_SIZE;i++){
                cout << "enter float value" << endl;
                cin >> userInput;
                if (i==0){
                    min = userInput;
                    max = userInput;
                }
                if (min > userInput)
                    min = userInput;
                if (max < userInput)
                    max = userInput;
                data[i] = userInput;
                total += userInput;
            }
        }
        void print(){
            for (int i=0; i<ARRAY_SIZE;i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
        double findAver(){
            return (double)(total / ARRAY_SIZE);
        }
        double findMax(){
            return max;
        }
        double findMin(){
            return min;
        }
        ~myArrayClass(){ 

        }
};


int main (void){
    myArrayClass myclass = myArrayClass();
    myclass.getData();
    myclass.print();
    cout << "Average is:" << myclass.findAver() << endl;
    cout << "Min is:" << myclass.findMin() << endl;
    cout << "Max is:" << myclass.findMax() << endl; 
    return 0;
}