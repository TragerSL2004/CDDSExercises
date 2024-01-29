#pragma once
#include <iostream>

template<typename AnyType>
class Node
{
public:
	Node();
	Node(AnyType value);

	Node<AnyType>* next;
	Node<AnyType>* previous;
	AnyType data;
};

template<typename AnyType>
inline Node<AnyType>::Node(){}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
	data = value;
}
