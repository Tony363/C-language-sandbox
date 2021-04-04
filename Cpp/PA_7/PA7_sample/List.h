#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

template <class T>
class List
{
public:

	//constructor
	List();

	//getters
	Node<T>* getHeadPtr() const;

	//setters
	void setHeadPtr(Node<T>* newHead);

	void insert(T data);

	void print();


private:

	Node<T>* pHead;

};

//constructor
template <class T>
List<T>::List()
{
	pHead = nullptr;
}

//getters
template <class T>
Node<T>* List<T>::getHeadPtr() const
{
	return pHead;
}

//setters
template <class T>
void List<T>::setHeadPtr(Node<T>* newHead)
{
	pHead = newHead;
}

template <class T>
void List<T>::insert(T data) 
{
	Node<T>* node = new Node<T>(data);

	if (getHeadPtr() == nullptr) 
	{
		setHeadPtr(node);
		return;
	}

	Node<T>* current = getHeadPtr();
	while (current != nullptr) 
	{
		current = current->getNextPtr();
	}

	current->setNextPtr(node);
}

template <class T>
void List<T>::print() 
{
	Node<T>* current = getHeadPtr();
	while (current != nullptr)
	{
		current = current->getNextPtr();
		//T data = current->getData();
		//cout << data << endl;
	}

}
