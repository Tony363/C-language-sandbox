#ifndef FITNESS_APPLICATION_H
#define FITNESS_APPLICATION_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

//Diet Plan class
class DietPlan
{
public:
	//constructor
	DietPlan();
	DietPlan(string name, int mGoalCalories, string date);

	//copy constructor
	DietPlan(const DietPlan& copy);

	//destructor
	~DietPlan() {};

	//getters
	string get_PlanName() const;
	int get_GoalCalories() const;
	string get_Date() const;


	//setters
	void set_PlanName(string& newPlanName);
	void set_GoalCalories(int& newGoalCalories);
	void set_Date(string& newDate);

	//functions
	//void EditGoal();

private:

	string mPlanName;
	int mGoalCalories;
	string mDate;

};

//Exercise Plan class
//class ExercisePlan
//{
//public:
//	//constructor
//	ExercisePlan();
//
//	//copy constructor
//
//	//destructor
//	~ExercisePlan();
//
//	//getters
//
//	//setters
//
//	//functions
//	//void EditGoal();
//
//private:
//	
//	std::string mPlanName;
//	int mGoalSteps;
//	std::string mDate;
//};

//Fitness App Wrapper class
 class FitnessAppWrapper
 {
 public:
     //constructor
     FitnessAppWrapper();

 	//member functions

 	//starts the main application
 	void runApp(void);

 	////Displays nine menu options
 	//void displayMenu();

 	//This function reads one record from the given stream. 
 	//These will be considered overloaded functions!
 	//Precondition: file is already open!
 	void loadDailyPlan(fstream& fileStream, DietPlan& plan);

 	//This function must read in all seven daily plans from the given stream.
 	//Note: the array parameter would change if using a vector or linked list! This function should call loadDailyPlan () directly.
    //Precondition: file is already open!
    void loadWeeklyPlan(fstream& fileStream, vector<DietPlan>& weeklyPlan);

 	//Writes a daily plan to the screen. 
 	//You must apply the overloaded stream insertion operator here! 
 	//Note: you must determine the appropriate parameters and return type. 
 	//Once again you must define two of these!
 	void displayDailyPlan(int pos);

 	//writes a weekly plan to the screen. This function must call displayDailyPlan(). 
 	//Note: you must determine the appropriate parameters and return type.
 	//Once again you must define two of these!
 	void displayWeeklyPlan();

 	////Writes a daily plan to a file. You must apply the overloaded stream insertion operator here! 
 	////Note: you must determine the appropriate parameters and return type. 
 	////Once again you must define two of these!
 	//void storeDailyPlan();

 	////Writes a weekly plan to a file. This function must call storeDailyPlan (). You must apply the overloaded stream insertion operator here! 
 	////Note: you must determine the appropriate parameters and return type.
 	////Once again you must define two of these!
 	//void storeWeeklyPlan();
 private:

     vector<DietPlan> dietPlans;
     fstream dietFile;

 };

//three nonmember functions must be declared. 
//Note: an overloaded operator is considered an overloaded function. 
//The overloaded stream insertion (<<) for both displaying a plan to the screen and for writing a plan to a file
ostream& operator<< (ostream& lhs, const DietPlan& rhs);

//The extraction (>>) operator for reading a plan from a file.
istream& operator>> (istream& lhs, DietPlan& rhs);


#endif
