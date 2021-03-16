#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// read file store to array
vector<double> readFile(vector<double>inArray,ifstream &inFile){
    for (int i=0;i<64;i++){
        double grade;
        inArray.push_back(grade);
        inFile >> inArray[i];
        if (inArray[i] < 0){
            break;
        }else if (inFile.eof()){
            break;
        }
    }
    return inArray;
}

// calculate average
double calAverage(vector<double> inArray){
    double total; int i;
    for (i=0;i<inArray.size()-1;i++){
        total += inArray[i];
    }
    return total/i;
}

// print file
void printFile(vector<double>inArray){
    for (int i=0;i<inArray.size()-1;i++){
        cout << "Grade "<< i << ": " << inArray[i] << endl;
    } 
    cout << "Average is: " << calAverage(inArray) << endl;

}

// Main function
int main(int argc,char** argv){
    if(argc != 2){
        cout << "Please enter read file" << endl; 
        return -1;
    }

    ifstream infile(argv[1]);
    vector<double> Grades = {};

    if (infile.is_open()){ 
        Grades = readFile(Grades,infile);
    }else{
        cout << "Couldn't read file" << endl;
    }
    printFile(Grades);
    infile.close();
    return 0; 
}