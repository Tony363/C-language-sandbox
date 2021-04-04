#include "Menu.h"
#include "Data.h"

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

int main()
{
	List<Data> list;
	Menu Application;
	
	Application.run(list);
	// Data data = Data();
	// cout << data;
	return 0;
}