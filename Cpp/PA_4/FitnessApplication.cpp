#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Plans;
class DietPlan; 
class ExercisePlan; 
class FitnessAppWrapper;
ifstream& operator>>(ifstream& is, DietPlan& plan);
ifstream& operator>>(ifstream& is, ExercisePlan& plan);

typedef struct planNode{

}dailyPlan;

int main(){
    class FitnessAppWrapper app;class DietPlan diet; class ExercisePlan exercise;
    app.dietfile.open("dietPlans.txt");app.exercisefile.open("exercisePlans.txt");
    if (app.dietfile.is_open()){
        app.dietfile >>  diet();
    } else {
        cout << "Unable to open dietPlans.txt" << endl;
    }
    if (app.exercisefile.is_open()){
        app.exercisefile >> exercise();
    } else {
        cout << "Unable to open exercisePlans.txt" << endl;
    }
    app.dietfile.close();app.exercisefile.close();
    return 0;
}

class Plans{
    public:
        Plans();

        int goalCalories; // maximum intake of calories 
        string planName;
        string dateIntended; // date plan is intended to be

        iostream& operator<<(int goal){
            cout << "You goal is updated (" << goal << ")" << endl;
        }
        void editGoal() {
            cout << "Please enter goal(calories):" << endl;
            cin >> goalCalories;
        }
};

class DietPlan:Plans{
    private:
        
    public:
        DietPlan(){

        };
};

class ExercisePlan:Plans{
    public:

        ExercisePlan(){
            
        }
};

class FitnessAppWrapper{
    public:
        ifstream dietfile,exercisefile;
        
        FitnessAppWrapper(){
            vector<dailyPlan> StoredExercisePlans = {};
            vector<dailyPlan> StoredDietPlans = {};
        }

        void runApp(void){cout << "starting main application" << endl;}

        void loadDailyPlan(ifstream &fileStream,DietPlan &plan){
            dietfile.open("dietPlans.txt");
            if (dietfile.is_open()){
                dietfile >> plan;
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }

        void loadDailyPlan(ifstream &fileStream,ExercisePlan &plan){
            dietfile.open("exercisePlans.txt");
            if (dietfile.is_open()){
                dietfile >> plan;
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }
};  

ifstream& operator>>(ifstream& is, DietPlan& plan){
    string line;
    while (getline(is,line)){
        cout << line << endl;
    }
    return is;
}

ifstream& operator>>(ifstream& is, ExercisePlan& plan){
    string line;
    while (getline(is,line)){
        cout << line << endl;
    }
    return is;
}