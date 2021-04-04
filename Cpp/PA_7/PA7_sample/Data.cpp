#include  "Data.h"

//constructor
Data::Data() {
	this->record = "";
	this->ID = "";
	this->name = {"", ""};
	this->email = "";
	this->units = "";
	this->program = "";
	this->level = "";
	numAbsences = 0;
}

Data::Data(const string& record, const string& ID, const Name& name, const string& email, const string& units, const string& program, const string& level)
{
	this->record = record;
	this->ID = ID;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = program;
	this->level = level;
	numAbsences = 0;
}

//getters
string Data::getRecord() const //TODO: max 3 digits
{
	return record;
}

string Data::getID() const //TODO: max 9 digits
{
	return ID;
}

Name Data::getName() const
{
	return name;
}

string Data::getEmail() const
{
	return email;
}

string Data::getUnits() const
{
	return units;
}

string Data::getProgram() const
{
	return program;
}

string Data::getLevel() const
{
	return level;
}

// //function overloading
// ostream& operator<< (ostream& lhs, Data& rhs)
// {
// 	string first = rhs.getName().firstName;
// 	string last = rhs.getName().lastName;
// 	lhs << rhs.getRecord()
// 		<< rhs.getID()
// 		<< first
// 		<< last
// 		<< rhs.getEmail() 
// 		<< rhs.getUnits() 
// 		<< rhs.getProgram() 
// 		<< rhs.getLevel();

// 	return lhs;
// }

//setters
void Data::setRecord(string newRecord)//TODO: max 3 digits
{
	record = newRecord;
}

void Data::setID(string newID)//TODO: max 9 digits
{
	ID = newID;
}

void Data::setEmail(string newEmail)
{
	email = newEmail;
}

void Data::setUnits(string newUnits)
{
	units = newUnits;
}

void Data::setProgram(string newProgram)
{
	program = newProgram;
}

void Data::setLevel(string newLevel)
{
	level = newLevel;
}