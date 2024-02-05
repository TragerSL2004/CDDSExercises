#include <iostream>
#include "LinkedList.h"

template<typename AnyType>
AnyType add(AnyType a, AnyType b)
{
	return a + b;
}

int main()
{
	LinkedList<int> testList = LinkedList<int>();

	testList.pushFront(1);
	testList.pushFront(2);
	testList.pushFront(3);
	testList.pushFront(4);
	testList.pushFront(5);

	testList.destroy();

	testList.print();

	std::cout << add(2.5f, 2.5f);
}