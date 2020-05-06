/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: Node.h
 * @author: Jack Gould
 * @brief: Header file for templated Node class. Defines member methods. Used for a node based implementation of a Queue. A single Queue<std::string> is used in the executive class to store lines of the input file.
 * @date: 04-17-2020
 */
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
private:
	T node_entry; // the data stored in this node
	Node<T>* node_next; // pointer to the next node in the list structure
	
public:

 /* Constructor
  * @pre
  * @param T entry - the data to be stored in the created node
  * @post - A new node is created, with node_entry = entry
  */
  Node(T entry);

 /* 
  * @pre
  * @return T - returns the data of type T stored in this node
  */
	T nodeGetEntry()const;

 /* 
  * @pre
  * @param T entry - the data to be stored in this node
  * @post node_entry of this node is set to T entry
  */
	void nodeSetEntry(T entry);

 /* 
  * @pre
  * @return Node<T>* - returns a pointer to the next node in the list structure
  */
	Node<T>* nodeGetNext()const;

 /* 
  * @pre
  * @param Node<T>* next - a pointer to a Node<T> that will be set as next in the list, after the calling node
  * @post node_next is set equal to the parameter next
  */
	void nodeSetNext(Node<T>* next);
};
#include "Node.cpp"
#endif
