#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Plans;
class DietPlan; 
class ExercisePlan; 
class FitnessAppWrapper;
ifstream& operator>>(ifstream& is, DietPlan& plan);
ifstream& operator>>(ifstream& is, ExercisePlan& plan);

// typedef struct TodayPlan{
//     string planName;
//     int goalCalories;
//     string dateIntended;
// }TodayPlan;

int main(){
    class FitnessAppWrapper app;class DietPlan diet; class ExercisePlan exercise;
    app.dietfile.open("dietPlans.txt");app.exercisefile.open("exercisePlans.txt");
    
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

class DietPlan:public Plans{
    public:
        // TodayPlan dietP;
        DietPlan(){
            
        };
        int coolvar;
};

class ExercisePlan:public Plans{
    public:
        // TodayPlan exerciseP;
        ExercisePlan(){

        }
};

class FitnessAppWrapper{
    public:
        ifstream dietfile,exercisefile;
        vector<DietPlan> StoredDietPlans = {};
        vector<ExercisePlan> StoredExercisePlans = {};
        FitnessAppWrapper(){
           
        }

        void runApp(void){cout << "starting main application" << endl;}

        void loadDailyPlan(ifstream &Dietfile,DietPlan &plan){
            Dietfile.open("dietPlans.txt");
            if (Dietfile.is_open()){
                Dietfile >> plan;
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }

        void loadDailyPlan(ifstream &Exercisefile,ExercisePlan &plan){
            Exercisefile.open("exercisePlans.txt");
            if (Exercisefile.is_open()){
                Exercisefile >> plan;
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }

        void loadWeeklyPlan(ifstream &Exercisefile,vector<DietPlan> PlansToStore){
            class DietPlan forDiet;
            for(int i=0;i<7;i++){
                loadDailyPlan(dietfile,forDiet);
            }
        }

        void loadWeeklyPlan(ifstream &Exercisefile,vector<ExercisePlan> PlansToStore){
            class ExercisePlan forExercise;
            for(int i=0;i<7;i++){
                loadDailyPlan(dietfile,forExercise);
            }
        }
        iostream& operator<<(iostream& out,ExercisePlan& plan){
            out << "Plan: " << plan.planName 
                << "Goals: "<< plan.goalCalories 
                << "Date: " << plan.dateIntended 
                << endl;
            return out;
        }

        iostream& operator<<(iostream& out,DietPlan& plan){
            out << "Plan: " << plan.planName 
                << "Goals: "<< plan.goalCalories 
                << "Date: " << plan.dateIntended 
                << endl;
            return out;
        }

        template<class plans>
        void displayDailyPlan(plans & plan){
            cout << plan;
        }
};  

ifstream& operator>>(ifstream& is, DietPlan& plan){
    string line;
    int count;
    while (getline(is,line)){
        if (count==0){
            plan.planName = line;
            plan.coolvar = 3;
        } else if (count==1){
            plan.goalCalories = stoi(line);
        } else if (count==2){
            plan.dateIntended = line;
            for (auto& it : plan.StoredDietPlans){
                if (plan.dietP.dateIntended != it.dateIntended){
                    plan.StoredDietPlans.push_back(plan.dietP);
                    break;
                }
            }
        } else{
            count = 0;
            continue;
        }
        count ++;
        cout << line << endl;
    }
    return is;
}

ifstream& operator>>(ifstream& is, ExercisePlan& plan){
    string line;
    int count;
    while (getline(is,line)){
        if (count==0){
            plan.exerciseP.planName = line;
        } else if (count==1){
            plan.exerciseP.goalCalories = stoi(line);
        } else if (count==2){
            plan.exerciseP.dateIntended = line;
            for (auto& it : plan.StoredExercisePlans){
                if (plan.exerciseP.dateIntended != it.dateIntended){
                    plan.StoredExercisePlans.push_back(plan.exerciseP);
                    break;
                }
            }
        } else{
            count = 0;
            continue;
        }
        count ++;
        cout << line << endl;
    }
    return is;
}