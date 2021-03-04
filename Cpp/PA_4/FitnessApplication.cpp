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
ofstream& operator>>(ofstream& os,ExercisePlan& plans);
ofstream& operator>>(ofstream& os,ExercisePlan& plans);

ostream& operator<<(ostream& out,ExercisePlan& plans);
ostream& operator<<(ostream& out,DietPlan& plans);
ostream& operator<<(ostream& out,int& goal);

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
            cout << "Pleas enter goal(calories):\n" 
                << "-> " 
                << endl;
            cin >> goalCalories;
        }
};

class DietPlan:public Plans{
    public:
        DietPlan(){

        };
        DietPlan readNextPlan(ifstream& Efile,DietPlan& plan){
            Efile >> plan.planName;
            Efile >> plan.goalCalories;
            Efile >> plan.dateIntended;
            return plan;    
        }
};

class ExercisePlan:public Plans{
    public:
        ExercisePlan(){

        }
        ExercisePlan readNextPlan(ifstream& Efile,ExercisePlan& plan){
            Efile >> plan.planName;
            Efile >> plan.goalCalories;
            Efile >> plan.dateIntended;
            return plan;    
        }
};

class FitnessAppWrapper{
    private: 
        ifstream dietfile,exercisefile;
        vector<DietPlan> StoredDietPlans = {};
        vector<ExercisePlan> StoredExercisePlans = {};
        // enum days {
        //     Monday="Monday",
        //     Tuesday="Tuesday", 
        //     Wednesday="Wednessday",
        //     Thursday="Thursday",
        //     Friday="Friday",
        //     Saturday="Saturday",
        //     Sunday="Sunday"
        //     };

    public:
        FitnessAppWrapper(){
            runApp();
        }

        void runApp(void){
            cout << "starting main application" << endl;
            dietfile.open("dietPlans.txt");
            exercisefile.open("exercisePlans.txt");
            }

        // exercise plan diet plan differentiate
        void loadDailyPlan(ifstream &Dietfile,DietPlan &plan){
            Dietfile.open("dietPlans.txt");
            if (Dietfile.is_open()){
                Dietfile >> plan;
                // each stored vector object same or different?
                StoredDietPlans.push_back(plan);
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }

        void loadDailyPlan(ifstream &Exercisefile,ExercisePlan &plan){
            Exercisefile.open("exercisePlans.txt");
            if (Exercisefile.is_open()){
                Exercisefile >> plan;
                // each stored vector object same or different?
                StoredExercisePlans.push_back(plan);
            } else {
                cout << "Unable to open dietPlans.txt" << endl;
            }
        }
        // read first line, then create object.
        // need reference to file and reference to object *2 layers of deferencing for dailyload plan and overloading  operator
        // pass reference
        // determine by which file stream to call which method
        void loadWeeklyPlan(ifstream &filestream,int type){
            for(int i=0;i<7;i++){
                DietPlan forDiet;ExercisePlan forExercise;
                if (type == 0){
                    loadDailyPlan(filestream,forDiet);
                }else{
                    loadDailyPlan(filestream,forExercise);
                }
            }
        }
        // void loadWeeklyPlan(ifstream &Exercisefile){
        //     for(int i=0;i<7;i++){
        //         ExercisePlan forExercise;
        //         loadDailyPlan(Exercisefile,forExercise);
        //     }
        // }

        void displayDailyPlan(ExercisePlan& plan){
            cout << plan;
        }

        void displayDailyPlan(DietPlan& plan){
            cout << plan;
        }
        
        void displayWeeklyPlan(vector<ExercisePlan> plan){
            for (auto& it:plan){
                displayDailyPlan(it);
            }
        }

        void displayWeeklyPlan(vector<DietPlan> plan){
            for (auto& it:plan){
                displayDailyPlan(it);
            }
        }  
        // ?? does this is even work to not overwrite file of original?
        void storeDailyPlan(ExercisePlan& plan){
            ofstream outfile;
            outfile.open("exerciseStore.txt",ios::out |ios::app);
            outfile << plan;
            outfile.close();
        }
        // ?? does this is even work to not overwrite file of original?
        void storeDailyPlan(DietPlan plan){
            ofstream outfile;
            outfile.open("dietStore.txt",ios::out |ios::app);
            outfile << plan;
            outfile.close();
        }

        void storeWeeklyPlan(vector<ExercisePlan> plans){
            for (auto& it:plans){
                storeDailyPlan(it);
            }
        }
        
        void storeWeeklyPlan(vector<DietPlan> plans){
            for (auto& it:plans){
                storeDailyPlan(it);
            }
        }
        
        void editDietPlans(){
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

        void editExercisePlans(){
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

        void closeApp(){
            cout << "closing APP" << endl;
            dietfile.close();
            exercisefile.close();
        }
        
        void displayMenu(){
            int choice;
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
        }

        void evalChoice(int choice){
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
};  

// class readFile{

//     private: 
//         int count=planName,curPos=0;
//         enum {planName,goalCalories,dateIntended};
//         string line;

//     public:
//         template<class plans>
//         readFile(ofstream &file,plans& plan){
//             file << plan.planName;
//             file << plan.goalCalories;
//             file << plan.dateIntended;
//             file << "\n";
//         }
//         template<class plans>
//         readFile(ifstream& file,plans& plan){
//             file.seekg(curPos);
//             while (getline(file,line) && count <= dateIntended){
//                 if (count==0){
//                     plan.planName = line;
//                 } else if (count==1){
//                     plan.goalCalories = stoi(line);
//                 } else if (count==2){
//                     plan.dateIntended = line;
//                 } 
//                 count ++;
//                 // cout << line << endl;
//             }
//             store_Pos(file);
//             returnStream(file);
//         }

//         void store_Pos(ifstream& stream){
//             curPos = stream.tellg();
//         }

//         ifstream& returnStream(ifstream& stream){
//             return stream;
//         }

// };

ifstream& operator>>(ifstream& is, ExercisePlan& plans){
    plans.readNextPlan(is,plans);
    return is;
}
ifstream& operator>>(ifstream& is, DietPlan& plans){
    plans.readNextPlan(is,plans);
    return is;
}

// ofstream& operator<<(ofstream& os,ExercisePlan& plans){
//     readFile file(os,plans);
//     return os;
// }
// ofstream& operator<<(ofstream& os,DietPlan& plans){
//     readFile file(os,plans);
//     return os;
// }

ostream& operator<<(ostream& out,ExercisePlan& plans){
            out << "Plan: " << plans.planName 
                << "Goals: "<< to_string(plans.goalCalories)
                << "Date: " << plans.dateIntended 
                << endl;
            return out;
        }
ostream& operator<<(ostream& out,DietPlan& plans){
            out << "Plan: " << plans.planName 
                << "Goals: "<< to_string(plans.goalCalories) 
                << "Date: " << plans.dateIntended 
                << endl;
            return out;
        }
ostream& operator<<(ostream& out,int& goal){
            out << "You goal is updated (" << to_string(goal) << ")" << endl;
            return out;
        }
