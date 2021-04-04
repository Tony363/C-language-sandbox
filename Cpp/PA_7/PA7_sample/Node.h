#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Node
{
public:

	//constructor
	Node(T data);

	//getters
	T getData() const;

	Node* getNextPtr() const;
	void setNextPtr(Node<T>* node);


private:

	T data;

	Node* mpNextPtr;

};

//constructor
template <class T>
Node<T>::Node(T data)
{
	this->data = data;
}

//getters
template <class T>
T Node<T>::getData() const
{
	return data;
}

template <class T>
void Node<T>::setNextPtr(Node<T>* node) {
	mpNextPtr = node;
}

template <class T>
Node<T>* Node<T>::getNextPtr() const
{
	return mpNextPtr;
}