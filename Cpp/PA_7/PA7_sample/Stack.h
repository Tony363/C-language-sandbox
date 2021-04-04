#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
public:

	//constructor
	Stack();

	//function
	void push(string absenceDate);

	string pop();

	string peek();

	bool isEmpty();

private:

	vector <string> absenceDates;

};
