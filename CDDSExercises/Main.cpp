#include <iostream>
#include "DynamicArray.h"

template<typename AnyType>
AnyType add(AnyType a, AnyType b)
{
	return a + b;
}

int main()
{
	DynamicArray<int> nums = DynamicArray<int>();

	nums.addItem(1);
	nums.addItem(2);
	nums.addItem(3);
	nums.addItem(4);
	nums.addItem(5);

	nums.print();

	std::cout << add(2.5f, 2.5f);
}