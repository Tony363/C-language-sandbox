#ifndef FITNESSAPP_H
#define FITNESSAPP_H 

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Plans{
    public:
        Plans(){

        };

        int goalCalories; // maximum intake of calories 
        string planName;
        string dateIntended; // date plan is intended to be

        void editGoal();
};

class DietPlan:public Plans{
    public:
        DietPlan(){

        };
        DietPlan readNextPlan(ifstream& Dfile,DietPlan& plan);
        //destructor
        ~DietPlan() {};
};

class ExercisePlan:public Plans{
    public:
        ExercisePlan(){

        }
        ExercisePlan readNextPlan(ifstream& Efile,ExercisePlan& plan);
        
        //destructor
        ~ExercisePlan() {};
};

class FitnessAppWrapper{
    private: 
        ifstream dietfile,exercisefile;
        vector<DietPlan> StoredDietPlans = {};
        vector<ExercisePlan> StoredExercisePlans = {};

    public:
        FitnessAppWrapper();
        ~FitnessAppWrapper(){};

        void runApp(void);

        // exercise plan diet plan differentiate
        void loadDailyPlan(ifstream &Dietfile,DietPlan &plan);

        void loadDailyPlan(ifstream &Exercisefile,ExercisePlan &plan);

        // read first line, then create object.
        // need reference to file and reference to object *2 layers of deferencing for dailyload plan and overloading  operator
        // pass reference
        // determine by which file stream to call which method
        void loadWeeklyPlan(ifstream &filestream,int type);

        void displayDailyPlan(ExercisePlan& plan);

        void displayDailyPlan(DietPlan& plan);
        
        void displayWeeklyPlan(vector<ExercisePlan> plan);

        void displayWeeklyPlan(vector<DietPlan> plan);

        // ?? does this is even work to not overwrite file of original?
        void storeDailyPlan(ExercisePlan& plan);

        // ?? does this is even work to not overwrite file of original?
        void storeDailyPlan(DietPlan plan);

        void storeWeeklyPlan(vector<ExercisePlan> plans);
        
        void storeWeeklyPlan(vector<DietPlan> plans);
        
        void editDietPlans();

        void editExercisePlans();

        void closeApp();
        
        void displayMenu();

        void evalChoice(int choice);
};  

ifstream& operator>>(ifstream& is, ExercisePlan& plans);
ifstream& operator>>(ifstream& is, DietPlan& plans);
ostream& operator<<(ostream& out,ExercisePlan& plans);
ostream& operator<<(ostream& out,DietPlan& plans);
ostream& operator<<(ostream& out,int& goal);

#endif