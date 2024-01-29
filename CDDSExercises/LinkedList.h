#pragma once
#include <iostream>
#include "Iterator.h"
#include "Node.h"

template<typename AnyType>
class LinkedList
{
public:
	LinkedList();

	LinkedList(const LinkedList<AnyType>& other);

	~LinkedList();

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

	bool getData(Iterator<AnyType>& iter, int index);

	const int getLength();

	void operator = (const LinkedList<AnyType>& otherList);

	void sort();

private:
	Node<AnyType>* m_first;
	Node<AnyType>* m_last;
	int m_nodeCount;
};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(){}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	m_nodeCount = other;
}

template<typename AnyType>
inline LinkedList<AnyType>::~LinkedList()
{
	destroy();
}

template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	for (int i = 0; i < m_nodeCount; i++)
	{
		delete list[i];
	}

	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline const Iterator<AnyType> LinkedList<AnyType>::begin()
{
	return Iterator<AnyType>(m_first);
}

template<typename AnyType>
inline const Iterator<AnyType> LinkedList<AnyType>::end()
{
	return Iterator<AnyType>(m_last->next);
}

template<typename AnyType>
inline const AnyType LinkedList<AnyType>::first()
{
	return m_first;
}

template<typename AnyType>
inline const AnyType LinkedList<AnyType>::last()
{
	return m_last;
}

template<typename AnyType>
inline const bool LinkedList<AnyType>::contains(const AnyType value)
{
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (list[i] == value)
		{
			return true;
		}
	}
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	Node newNode = new node(value);
	newNode->previous = m_first->previous;
	newNode->next = m_first;
	m_first->previous = newNode;
	newNode->previous->next = newNode;
	m_nodeCount++:
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	Node newNode = new node(value);
	newNode->next = m_last->next;
	newNode->previous = m_last;
	m_last->next = newNode;
	newNode->next->previous = newNode;
	m_nodeCount++:
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	m_first->next->previous = m_first->previous;
	m_first->next->next = m_first->next;
	delete m_first;
	m_nodeCount--;
	return m_first->data;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	m_last->previous->next = m_last->next;
	m_last->previous->previous = m_last->previous;
	delete m_last;
	m_nodeCount--;
	return m_last->data;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	if (index != 0)
	{
		Node newNode = new node(value);
		newNode->next = list[index]->next;
		newNode->previous = list[index];
		list[index]->next = newNode;
		newNode->next->previous = newNode;
		m_nodeCount++;

		return true;
	}
	
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (list[i] == value)
		{
			list[i]->previous->next = list[i]->next;
			list[i]->previous->previous = list[i]->previous;
			delete list[i];

			return true;
		}
	}
	return false;
}

template<typename AnyType>
inline const void LinkedList<AnyType>::print()
{
	for (int i = 0; i < m_nodeCount; i++)
	{
		std::cout >> list[i];
	}
}

template<typename AnyType>
inline void LinkedList<AnyType>::initialize()
{
	m_first = 0;
	m_last = 0;
	m_nodeCount = 0;
}

template<typename AnyType>
inline const bool LinkedList<AnyType>::isEmpty()
{
	if (m_nodeCount <= 0)
	{
		return true;
	}
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	if (index <= 0 || index > m_nodeCount)
	{
		return false;
	}

	iter = list[index];
	return true;
}

template<typename AnyType>
inline const int LinkedList<AnyType>::getLength()
{
	return m_nodeCount;
}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (list[i] < list[i - 1])
		{
			list[i] = list[i - 1];
			list[i - 1] = list[i];
		}
	}
}
