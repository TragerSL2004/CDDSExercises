#pragma once
#include <iostream>
#include "Node.h"

template<typename AnyType>
class Iterator
{
public:
	Iterator();
	Iterator(Node<AnyType>* node);

	Iterator<AnyType> operator ++();
	Iterator<AnyType> operator --();

	const bool operator ==(const Iterator<AnyType>& iter);
	const bool operator !=(const Iterator<AnyType>& iter);

	AnyType operator*();
private:
	Node<AnyType>* m_current;
};

template<typename AnyType>
inline Iterator<AnyType>::Iterator(){}

template<typename AnyType>
inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
{
	m_current = node;
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator++()
{
	return Iterator<AnyType>(m_current->next);
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator--()
{
	return Iterator<AnyType>(m_current->previous);
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
{
	if (iter == m_current)
	{
		return true;
	}
	return false;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
{
	if (iter != m_current)
	{
		return true;
	}
	return false;
}

template<typename AnyType>
inline AnyType Iterator<AnyType>::operator*()
{
	return AnyType();
}
