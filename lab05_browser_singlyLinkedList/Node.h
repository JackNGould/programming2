/*
 * @assignment: EECS 268 Lab05 
 * @file: Node.h
 * @author: Jack Gould
 * @brief: Header file for templated Node class. Lists member methods. Included for a Node based implementation of a LinkedList
 * @date: 04-01-2020
 */
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
private:

  //Private member variable
	T m_entry; // the data stored in this node
  //Private member variable
	Node<T>* m_next; // pointer to the next node in the list structure
	
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
	T getEntry()const;

 /* 
  * @pre
  * @param T entry - the data to be stored in this node
  * @post node_entry of this node is set to T entry
  */
	void setEntry(T entry);

 /* 
  * @pre
  * @return Node<T>* - returns a pointer to the next node in the list structure
  */
	Node<T>* getNext()const;

 /* 
  * @pre
  * @param Node<T>* next - a pointer to a Node<T> that will be set as next in the list, after the calling node
  * @post node_next is set equal to the parameter next
  */
	void setNext(Node<T>* next);
};
#include "Node.cpp"
#endif
