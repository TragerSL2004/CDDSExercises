#pragma once

template<typename AnyType>
class Node
{
public:
	Node<AnyType>();
	Node<AnyType>(AnyType value);

	Node<AnyType>* next;
	Node<AnyType>* previous;
	AnyType data;
};

template<typename AnyType>
inline Node<AnyType>::Node()
{
	previous = nullptr;
	next = nullptr;
}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
	previous = nullptr;
	next = nullptr;
	data = value;
}
