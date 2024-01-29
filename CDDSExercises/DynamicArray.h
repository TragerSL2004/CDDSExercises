#pragma once
#include <iostream>

template<typename AnyType>
class DynamicArray
{
public:
	AnyType getItem(int index);

	void addItem(AnyType item);

	void print();

private:
	AnyType* m_items;
	int m_itemCount;
};

template<typename AnyType>
inline AnyType DynamicArray<AnyType>::getItem(int index)
{
	if (index < 0 || index >= m_itemCount)
		return AnyType();

	return m_items[index];
}

template<typename AnyType>
inline void DynamicArray<AnyType>::addItem(AnyType item)
{
	AnyType* temp = new AnyType[m_itemCount + 1];

	for (int i = 0; i < m_itemCount; i++)
	{
		temp[i] = m_items[i];
	}

	m_items = temp;
	m_items[m_itemCount] = item;

	m_itemCount++;
}

template<typename AnyType>
inline void DynamicArray<AnyType>::print()
{
	for (int i = 0; i < m_itemCount; i++)
	{
		std::cout << m_items[i] << std::endl;
	}
}
