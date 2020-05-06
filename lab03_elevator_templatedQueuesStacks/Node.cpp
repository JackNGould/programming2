/*
 * @project: elevator - templated stacks and queues
 * @file: Node.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Node class. Defines member methods. Used for a node based implementation of a Queue. Used for command input list and elevator line
 * @date: 02-19-2020
 */

template <typename T>
void Node<T>::nodeSetEntry(T entry)
{
	node_entry = entry;
}

template <typename T>
T Node<T>::nodeGetEntry()const
{
	return (node_entry);
}

template <typename T>
Node<T>* Node<T>::nodeGetNext()const
{
	return (node_next);
}

template <typename T>
void Node<T>::nodeSetNext(Node<T>* next)
{
	node_next = next;
}

template <typename T>
Node<T>::Node(T entry)
{
	node_next=nullptr;
	node_entry=entry;
}
