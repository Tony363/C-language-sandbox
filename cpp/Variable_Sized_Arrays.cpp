nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int rows,queries,elements,value,row_idx,col_idx;
    cin >> rows >> queries; 
    int vector[rows];
    for (int i=0;i<rows;i++){
        cin >> elements;
        vector[i][elements];
        for (int j=0;j<elements;j++){
            cin >> value;
            vector[i][j] = value; 
        }
    }
    for (int i=0;i<queries;i++){
        cin >> row_idx >> col_idx;
        cout << vector[row_idx][col_idx];
    }
    return 0;
}
