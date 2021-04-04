#include "Menu.h"
#include "Data.h"

//constructor
Menu::Menu()
{

}

//function overloading
ostream& operator<< (ostream& lhs, Data& rhs)
{
	string first = rhs.getName().firstName;
	string last = rhs.getName().lastName;
	lhs << rhs.getRecord()
		<< rhs.getID()
		<< first
		<< last
		<< rhs.getEmail() 
		<< rhs.getUnits() 
		<< rhs.getProgram() 
		<< rhs.getLevel();

	return lhs;
}
//function
void Menu::run(List<Data>& list)
{
	int choice = 0;

	while (choice != 7)
	{
		print();
		cin >> choice;

		if (choice == 1)
		{
			importCourseList(list);
		}
		else if(choice == 7)
		{
			break;
		}
	}
}

//print
void Menu::print()
{
	cout << "Please Select an Option " << endl;
	cout << "1. Import Course List" << endl;
	cout << "7. Exit" << endl;
}

void Menu::importCourseList(List<Data> list)
{
	courseList.open("C:\\Users\\88032\\source\\repos\\PA 7\\classList.csv", ios::in);
	if (!courseList.is_open())
	{
		cout << "Failed to open the file!" << endl;
	}

	//
	string line;

	//read the file till the end of file
	while (getline(courseList,line)) //check if its the end of file
	{
		string delimiter = ",";
		size_t pos = 0;
		string infoTemp;

		int i = 0;
		string info[7];

		while ((pos = line.find(delimiter)) != std::string::npos)
		{
			info[i]= line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			i++;
		}

		Name name = { info[2], info[3] };
		Data data(info[0], info[1], name, info[4], info[5], info[6], line);

		list.insert(data);

		cout << data;

		break;
	}

	list.print();
}
