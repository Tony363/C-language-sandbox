#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Stack.h"

using namespace std;

typedef struct name
{
	string firstName;
	string lastName;
}Name;


class Data
{
public:

	//constructor
	Data();
	Data(const string& record, const string& ID, const Name& name, const string& email, const string& units, const string& program, const string& level);

	//getters
	string getRecord() const; //TODO: max 3 digits
	string getID() const; //TODO: max 9 digits
	Name getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;

	//setters
	void setRecord(string newRecord); //TODO: max 3 digits
	void setID(string newID); //TODO: max 9 digits
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);


private:

	string record; //TODO: max 3 digits
	string ID; //TODO: max 9 digits
	Name name;
	string email;
	string units;
	string program;
	string level;
	unsigned int numAbsences;
	Stack stackAbsences;

};

//function overloading
ostream& operator<< (ofstream& lhs, const Data& rhs);
