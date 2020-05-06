/*
 * @assignment: EECS 268 Lab05 
 * @file: Node.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Node class. Defines member methods. Included for a Node based implementation of a LinkedList
 * @date: 04-01-2020
 */

template <typename T>
void Node<T>::setEntry(T entry)
{
	m_entry = entry;
}

template <typename T>
T Node<T>::getEntry()const
{
	return (m_entry);
}

template <typename T>
Node<T>* Node<T>::getNext()const
{
	return (m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}

template <typename T>
Node<T>::Node(T entry)
{
	m_next=nullptr;
	m_entry=entry;
}
