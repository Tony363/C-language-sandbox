#include <iostream>

using namespace std;

void outputScore(char grade){
    switch (grade) {
        case 'A':
            cout << "Good job" << endl;
            break;
        case 'B':
            cout << "Fair job" << endl;
            break;
        case 'C':
            cout << "Okay" << endl;
            break;
        case 'D':
            cout << "You can do better" << endl;
            break;
        case 'F':
            cout << "Failure" << endl;
            break;
        default:
            cout << "invalid" << endl;
        }
        cin.get();
}

int main(){
    int score;
    char grade;
    cout << "Enter your score:" << endl;
    cin >> score;
    if (score < 100 && score >= 90)
        grade = 'A';
    else if (score < 90 && score >= 80)
        grade = 'B';
    else if (score < 80 && score >= 70)
        grade = 'C';
    else if (score < 70 && score >= 60)
        grade = 'D';
    else 
        grade = 'F';
    cout << grade << endl;
    outputScore(grade);
    return 0;
}