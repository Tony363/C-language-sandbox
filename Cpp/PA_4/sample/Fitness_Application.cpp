#include "Fitness_Application.h"

DietPlan::DietPlan () 
{
	mPlanName = "";
	mGoalCalories = 0;
	mDate = "00/00/00";
}

//constructor - DietPlan
DietPlan::DietPlan (string name, int cal, string date) 
{
	mPlanName = name;
	mGoalCalories = cal;
	mDate = date;
}

//copy constructor
DietPlan::DietPlan(const DietPlan& copy)
{
	mPlanName = copy.get_PlanName();
	mGoalCalories = copy.get_GoalCalories();
	mDate = copy.get_Date();

}

//getters
string DietPlan::get_PlanName() const
{
	return mPlanName;
}

int DietPlan::get_GoalCalories() const
{
	return mGoalCalories;
}

string DietPlan::get_Date() const
{
	return mDate;
}

//setter
void DietPlan::set_PlanName(string& newPlanName)
{
	mPlanName = newPlanName;
}

void DietPlan::set_GoalCalories(int& newGoalCalories)
{
	mGoalCalories = newGoalCalories;
}

void DietPlan::set_Date(string& newDate)
{
	mDate = newDate;
}

//constructor - FitnessAppWrapper
FitnessAppWrapper::FitnessAppWrapper()
{
	dietPlans.resize(7);

	dietFile.open("dietPlans.txt", ios::in);
	if(!dietFile.is_open()) 
	{
		cout << "Failed to open the file!";
	}

}

//Writes a daily plan to the screen. 
//You must apply the overloaded stream insertion operator here! 
//Note: you must determine the appropriate parameters and return type. 
//Once again you must define two of these!
void FitnessAppWrapper::displayDailyPlan(int pos)
{
	cout << dietPlans.at(pos);
}

//writes a weekly plan to the screen. This function must call displayDailyPlan(). 
//Note: you must determine the appropriate parameters and return type.
//Once again you must define two of these!
void FitnessAppWrapper::displayWeeklyPlan()
{
	displayDailyPlan(0);
}

//Starts the main application
void FitnessAppWrapper::runApp(void)
{
	//call display menu
	loadWeeklyPlan(dietFile, dietPlans);
	displayWeeklyPlan();
}

////Displays nine menu options
//void FitnessAppWrapper::displayMenu()
//{
//
//}

//This function reads one record from the given stream. 
//These will be considered overloaded functions!
//Precondition: file is already open!
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}

//This function must read in all seven daily plans from the given stream.
//Note: the array parameter would change if using a vector or linked list! This function should call loadDailyPlan () directly.
//Precondition: file is already open!
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, vector<DietPlan>& weeklyPlan)
{	
	// pass latest vector pos
	loadDailyPlan(fileStream, weeklyPlan.at(0));
}

//The overloaded stream insertion (<<) for both displaying a plan to the screen and for writing a plan to a file
ostream& operator<< (ostream& lhs, const DietPlan& rhs)
{
	//lhs << "Length: " << rhs.get_length() << "Width: " << rhs.get_width();
	lhs << "Plan Name: " << rhs.get_PlanName() << "\nCalories: " << rhs.get_GoalCalories() << "\nDate: " << rhs.get_Date() << endl;

	return lhs;
}

//The extraction (>>) operator for reading a plan from a file.
istream& operator>> (istream& lhs, DietPlan& rhs)
{
	string plan;
	int num;
	string date;

	lhs >> plan >> num >> date;

	rhs.set_PlanName(plan);

	rhs.set_GoalCalories(num);

	rhs.set_Date(date);

	return lhs;
}