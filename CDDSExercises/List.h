#pragma once
#include <iostream>
#include "Iterator.h"

template<typename AnyType>
class List
{
public:
	list();

	list(const List<AnyType>& other);

	~List();

	void destroy();

	const Iterator<AnyType> begin();
	const Iterator<AnyType> end();

	const AnyType first();
	const AnyType last();

	const bool contains(const AnyType value);

	void pushFront(const AnyType& value);
	void pushBack(const AnyType& value);

	AnyType popFront();
	AnyType popBack();

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);

	const void print();
	void initialize();
	const bool isEmpty();

};