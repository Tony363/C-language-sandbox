#include "Stack.h"

//constructor
Stack::Stack()
{
	//nothing to be initialized
}

//function
void Stack::push(string absenceDate)
{
	//seeing a vectors end as the stacks head
	absenceDates.push_back(absenceDate);
}

string Stack::pop()
{
	//seeing a vectors head as the end of the stack
	string top = peek();
	absenceDates.pop_back();
	return top;
}

string Stack::peek()
{
	return absenceDates.at(absenceDates.size() - 1);
}

bool Stack::isEmpty()
{
	return absenceDates.empty();
}