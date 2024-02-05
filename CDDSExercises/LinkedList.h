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

	Iterator<AnyType> begin() const;
	Iterator<AnyType> end() const;

	AnyType first() const;
	AnyType last() const;

	bool contains(const AnyType value) const;

	void pushFront(const AnyType& value);
	void pushBack(const AnyType& value);

	AnyType popFront();
	AnyType popBack();

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);

	void print() const;
	void initialize();
	
	bool isEmpty() const;

	bool getData(Iterator<AnyType>& iter, int index);

	int getLength() const;

	void operator = (const LinkedList<AnyType>& otherList);

	void sort();

private:
	Node<AnyType>* m_first;
	Node<AnyType>* m_last;
	int m_nodeCount;
};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	initialize();
}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;

	m_first = other.m_first;
	m_last = other.m_last;

	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{
		pushBack(iter);
	}
}

template<typename AnyType>
inline LinkedList<AnyType>::~LinkedList()
{
	destroy();
}

template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	if (m_nodeCount == 0)
		return;

	for (int i = 0; i < m_nodeCount; i++)
	{
		popBack();
	}

	initialize();
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const 
{
	return Iterator<AnyType>(m_first);
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	if (!m_last)
		return Iterator<AnyType>(nullptr);

	return Iterator<AnyType>(m_last->next);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::first() const
{
	return m_first;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::last() const
{
	return m_last;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::contains(const AnyType value) const
{
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	//Create a new node to put the value in.
	Node<AnyType>* newNode = new Node<AnyType>(value);

	//Increase the node count by 1 to include the new node.
	m_nodeCount++;

	//If the first node is null then the list must be empty.
	if (!m_first)
	{
		//set the new node to be the first and last.
		m_first = newNode;
		m_last = newNode;
		return;
	}
	m_first->previous = newNode;
	newNode->next = m_first;
	m_first = newNode;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	Node<AnyType>* newNode = new Node<AnyType>(value);

	m_nodeCount++;
	if (!m_last)
	{
		m_last = newNode;
		m_first = newNode;
		return;
	}

	m_last->next = newNode;
	newNode->previous = m_last;
	m_last = newNode;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	if (m_nodeCount == 0)
		return AnyType();

	AnyType value = m_first->data;
	m_first = m_first->next;

	if (m_first->previous)
	{
		delete m_first->previous;
		m_first->previous = nullptr;
	}

	m_nodeCount--;

	return value;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	//If the list is empty..
	if (m_nodeCount == 0)
		//...return default value. 
		return AnyType();

	//Store the data in the node to remove.
	AnyType value = m_last->data;

	//Mark the second to last node as the last.
	m_last = m_last->previous;

	//If the node has a next...
	if (m_last->next)
	{
		//...delete it.
		delete m_last->next;
		m_last->next = nullptr;
	}

	//Decrease the node count to account for the node that was removed.
	m_nodeCount--;
	
	//Give back the value in the old last node.
	return value;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	//If the index given is outside the bounds of the list...
	if (index < 0 || index >= m_nodeCount)
		//...Return false.
		return false;

	//If the list is empty...
	if (m_nodeCount == 0)
	{
		//...use the logic from pushback to add it to the list.
		pushBack(value);
		return true;
	}

	if (index == 0)
	{
		pushFront(value);
		return true;
	}

	Node<AnyType>* newNode = new Node<AnyType>(value);

	Node<AnyType>* iter = m_first;

	for (int i = 0; i <= index; i++)
	{
		if (iter->next == nullptr)
			break;

		iter = iter->next;
	}

	newNode->next = iter;
	newNode->previous = iter->previous;

	newNode->previous->next = newNode;
	iter->previous = newNode;

	m_nodeCount++;

	return true;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < m_nodeCount; i++)
	{
		if (iter == nullptr)
			return false;

		if (iter->data == value)
			break;

		iter = iter->next;
	}

	if (iter == m_first)
	{
		popFront();
	}
	if (iter == m_last)
	{
		popBack();
	}

	if (iter == m_last)
	{
		popBack();
		return true;
	}
	else if (iter == m_first)
	{
		popFront();
		return true;
	}

	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;

	delete iter;

	return true;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

template<typename AnyType>
inline void LinkedList<AnyType>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::isEmpty() const
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
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{


	}
	iter = index;
	return true;
}

template<typename AnyType>
inline int LinkedList<AnyType>::getLength() const
{
	return m_nodeCount;
}

template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherList)
{
	for (Iterator<int>iter = begin(); iter != end(); ++iter)
	{
		*this[iter] = otherList[iter];
	}
	
}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{
		if (this[iter] < this[iter - 1])
		{
			this[iter] = this[iter - 1];
			this[iter - 1] = this[iter];
		}
	}
}
