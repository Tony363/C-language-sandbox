#include <FitnessApp.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Plans::editGoal() {
    cout << "Pleaes enter goal(calories):\n" 
        << "-> " 
        << endl;
    cin >> goalCalories;
}

FitnessAppWrapper::FitnessAppWrapper(){

}

DietPlan DietPlan::readNextPlan(ifstream& Dfile,DietPlan& plan){
    Dfile >> plan.planName;
    Dfile >> plan.goalCalories;
    Dfile >> plan.dateIntended;
    return plan;    
}

ExercisePlan ExercisePlan::readNextPlan(ifstream& Efile,ExercisePlan& plan){
    Efile >> plan.planName;
    Efile >> plan.goalCalories;
    Efile >> plan.dateIntended;
    return plan;    
}

void FitnessAppWrapper::runApp(void){
    cout << "starting main application" << endl;
    dietfile.open("dietPlans.txt");
    exercisefile.open("exercisePlans.txt");
    displayMenu();
    }

// exercise plan diet plan differentiate
void FitnessAppWrapper::loadDailyPlan(ifstream &Dietfile,DietPlan &plan){
    // Dietfile.open("dietPlans.txt");
    if (Dietfile.is_open()){
        Dietfile >> plan;
        // each stored vector object same or different?
        StoredDietPlans.push_back(plan);
    } else {
        cout << "Unable to open dietPlans.txt" << endl;
    }
}

void FitnessAppWrapper::loadDailyPlan(ifstream &Exercisefile,ExercisePlan &plan){
    // Exercisefile.open("exercisePlans.txt");
    if (Exercisefile.is_open()){
        Exercisefile >> plan;
        // each stored vector object same or different?
        StoredExercisePlans.push_back(plan);
    } else {
        cout << "Unable to open dietPlans.txt" << endl;
    }
}

void FitnessAppWrapper::loadWeeklyPlan(ifstream &filestream,int type){
    for(int i=0;i<7;i++){
        DietPlan forDiet;ExercisePlan forExercise;
        if (type == 0){
            loadDailyPlan(filestream,forDiet);
        }else{
            loadDailyPlan(filestream,forExercise);
        }
    }
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan){
    cout << plan;
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan){
    cout << plan;
}

void FitnessAppWrapper::displayWeeklyPlan(vector<ExercisePlan> plan){
    for (auto& it:plan){
        displayDailyPlan(it);
    }
}

void FitnessAppWrapper::displayWeeklyPlan(vector<DietPlan> plan){
    for (auto& it:plan){
        displayDailyPlan(it);
    }
}

// ?? does this is even work to not overwrite file of original?
void FitnessAppWrapper::storeDailyPlan(ExercisePlan& plan){
    ofstream outfile;
    outfile.open("exerciseStore.txt",ios::out |ios::app);
    outfile << plan;
    outfile.close();
}

// ?? does this is even work to not overwrite file of original?
void FitnessAppWrapper::storeDailyPlan(DietPlan plan){
    ofstream outfile;
    outfile.open("dietStore.txt",ios::out |ios::app);
    outfile << plan;
    outfile.close();
}

void FitnessAppWrapper::storeWeeklyPlan(vector<ExercisePlan> plans){
    for (auto& it:plans){
        storeDailyPlan(it);
    }
}

void FitnessAppWrapper::storeWeeklyPlan(vector<DietPlan> plans){
    for (auto& it:plans){
        storeDailyPlan(it);
    }
}

void FitnessAppWrapper::editExercisePlans(){
    string inputDay;
    cout << "Please enter plan day to edit:\n"
    << "-> ";
    cin >> inputDay; 
    if (inputDay == "Monday"){
        StoredExercisePlans[0].editGoal();
    }else if (inputDay == "Tuesday"){
        StoredExercisePlans[1].editGoal();
    }else if (inputDay == "Wednessday"){
        StoredExercisePlans[2].editGoal();
    }else if (inputDay == "Thursday"){
        StoredExercisePlans[3].editGoal();
    }else if (inputDay == "Friday"){
        StoredExercisePlans[4].editGoal();
    }else if (inputDay == "Saturday"){
        StoredExercisePlans[5].editGoal();
    }else if (inputDay == "Sunday"){
        StoredExercisePlans[6].editGoal();
    }else {
        cout << "Please input day of week with first letter capitalized" 
        << endl;
    }    
}
void FitnessAppWrapper::editDietPlans(){
    string inputDay;
    cout << "Please enter plan day to edit:\n"
    << "-> ";
    cin >> inputDay; 
    if (inputDay == "Monday"){
        StoredDietPlans[0].editGoal();
    }else if (inputDay == "Tuesday"){
        StoredDietPlans[1].editGoal();
    }else if (inputDay == "Wednessday"){
        StoredDietPlans[2].editGoal();
    }else if (inputDay == "Thursday"){
        StoredDietPlans[3].editGoal();
    }else if (inputDay == "Friday"){
        StoredDietPlans[4].editGoal();
    }else if (inputDay == "Saturday"){
        StoredDietPlans[5].editGoal();
    }else if (inputDay == "Sunday"){
        StoredDietPlans[6].editGoal();
    }else {
        cout << "Please input day of week with first letter capitalized" 
        << endl;
    } 
}

void FitnessAppWrapper::closeApp(){
    cout << "closing APP" << endl;
    dietfile.close();
    exercisefile.close();
}

void FitnessAppWrapper::displayMenu(){
    int choice;
    char yesno;
    cout << "Please Choose Options\n"
            << "[1] Load weekly diet plan from file\n"
            << "[2] Load weekly exercise plan from file\n"
            << "[3] Store weekly diet plan to file\n"
            << "[4] Store weekly exerise plan to file\n"
            << "[5] Display weekly diet plan to screen\n"
            << "[6] Display weekly exercise plan to screen\n"
            << "[7] Edit daily diet plan\n"
            << "[8] Edit daily exercise plan\n"
            << "[9] Exit.\n"
            << "-> ";

    cin >> choice;
    evalChoice(choice);
    cout << "continue using app? [y/n]" << endl;
    cin >> yesno;
    if (yesno == 'y'){
        displayMenu();
    }else {
        evalChoice(9);
    }
}

void FitnessAppWrapper::evalChoice(int choice){
    switch (choice){
        case 1: 
            loadWeeklyPlan(exercisefile,1);
            break;
        case 2: 
            loadWeeklyPlan(dietfile,0);
            break;
        case 3: 
            storeWeeklyPlan(StoredDietPlans);
            break;
        case 4:
            storeWeeklyPlan(StoredExercisePlans);
            break;
        case 5: 
            displayWeeklyPlan(StoredDietPlans);
            break;
        case 6: 
            displayWeeklyPlan(StoredExercisePlans);
            break;
        case 7: 
            editDietPlans();
            break;
        case 8: 
            editExercisePlans();
            break;
        case 9:
            closeApp();
            break;
    }
} 

ifstream& operator>>(ifstream& is, ExercisePlan& plans){
    plans.readNextPlan(is,plans);
    return is;
}
ifstream& operator>>(ifstream& is, DietPlan& plans){
    plans.readNextPlan(is,plans);
    return is;
}

ostream& operator<<(ostream& out,ExercisePlan& plans){
            out << "Plan: " << plans.planName << "\n"
                << "Goals: "<< to_string(plans.goalCalories) << "\n"
                << "Date: " << plans.dateIntended << endl;
            return out;
        }
ostream& operator<<(ostream& out,DietPlan& plans){
            out << "Plan: " << plans.planName << "\n"
                << "Goals: "<< to_string(plans.goalCalories) << "\n"
                << "Date: " << plans.dateIntended << endl;
            return out;
        }
ostream& operator<<(ostream& out,int& goal){
            out << "You goal is updated (" << to_string(goal) << ")" << endl;
            return out;
        }
