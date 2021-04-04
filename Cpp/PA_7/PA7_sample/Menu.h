#pragma once
#include <iostream>
#include <fstream>
#include "Data.h"
#include "List.h"

using namespace std;

class Menu
{
public:

	//constructor
	Menu();

	//function
	void run(List<Data>& list);

	void print();

	void importCourseList(List<Data> list);

private:

	fstream courseList;
};
