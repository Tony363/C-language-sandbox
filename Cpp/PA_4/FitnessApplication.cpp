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
class readFile;


ifstream& operator>>(ifstream& is, ExercisePlan& plans);
ifstream& operator>>(ifstream& is, DietPlan& plans);

iostream& operator<<(iostream& out,ExercisePlan& plans);
iostream& operator<<(iostream& out,DietPlan& plans);
iostream& operator<<(iostream& out,int& goal);

// void BindInput( ifstream & inputChannel ); 

int main(){
    FitnessAppWrapper app();
    DietPlan diet(); 
    ExercisePlan exercise();
    return 0;
}

class Plans{
    public:
        Plans(){

        };

        int goalCalories; // maximum intake of calories 
        string planName;
        string dateIntended; // date plan is intended to be

        void editGoal() {
            cout << "Pleasifstream& operator>>(ifstream& is, plans)e enter goal(calories):" << endl;
            cin >> goalCalories;
        }
};

class DietPlan:public Plans{
    public:
        DietPlan(){

        };
};

class ExercisePlan:public Plans{
    public:
        ExercisePlan(){

        }
};

class FitnessAppWrapper{
    private: 
        ifstream dietfile,exercisefile;
        vector<DietPlan> StoredDietPlans = {};
        vector<ExercisePlan> StoredExercisePlans = {};

    public:
        FitnessAppWrapper(){
            runApp();
        }

        void runApp(void){
            cout << "starting main application" << endl;
            dietfile.open("dietPlans.txt");
            exercisefile.open("exercisePlans.txt");
            }

        void loadDailyPlan(ifstream &Dietfile,DietPlan &plan){
            dietfile.open("dietPlans.txt");
            if (dietfile.is_open()){
                dietfile >> plan;
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }

        void loadDailyPlan(ifstream &Exercisefile,ExercisePlan &plan){
            exercisefile.open("exercisePlans.txt");
            if (exercisefile.is_open()){
                exercisefile >> plan;
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

        template<class plans>
        void displayDailyPlan(plans & plan){
            cout << plan;
        }
        void closeApp(){
            cout << "closing APP" << endl;
            dietfile.close();
            exercisefile.close();
        }
};  

class readFile{

    private: 
        int count=planName,curPos=0;
        enum {planName,goalCalories,dateIntended};
        string line;

    public:
        template<class plans>
        readFile(ifstream& file,plans& plan){
            file.seekg(curPos);
            while (getline(file,line) && count <= dateIntended){
                if (count==0){
                    plan.planName = line;
                } else if (count==1){
                    plan.goalCalories = stoi(line);
                } else if (count==2){
                    plan.dateIntended = line;
                } 
                count ++;
                // cout << line << endl;
            }
            store_Pos(file);
            returnStream(file);
        }

        void store_Pos(ifstream& stream){
            curPos = stream.tellg();
        }

        ifstream& returnStream(ifstream& stream){
            return stream;
        }

};

ifstream& operator>>(ifstream& is, ExercisePlan& plans){
    readFile file(is,plans);
    return is;
}
ifstream& operator>>(ifstream& is, DietPlan& plans){
    readFile file(is,plans);
    return is;
}

iostream& operator<<(iostream& out,ExercisePlan& plans){
            out << "Plan: " << plans.planName 
                << "Goals: "<< plans.goalCalories 
                << "Date: " << plans.dateIntended 
                << endl;
            return out;
        }
iostream& operator<<(iostream& out,DietPlan& plans){
            out << "Plan: " << plans.planName 
                << "Goals: "<< plans.goalCalories 
                << "Date: " << plans.dateIntended 
                << endl;
            return out;
        }
iostream& operator<<(iostream& out,int& goal){
            out << "You goal is updated (" << goal << ")" << endl;
            return out;
        }
