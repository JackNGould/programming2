/*
 * @assignment EECS 268 Lab05 
 * @file: LinkedList.h
 * @author: Jack Gould
 * @brief: Header file for LinkedList class. Lists member methods. Templated, singly-linked, Node based implementation. Inherits from ListInterface.
 * @date: 04-01-2020
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListInterface.h"
#include <stdexcept>
#include "Node.h"

template<typename T>
class LinkedList : public ListInterface<T> 
{
  public:

       /** CONSTRUCTOR
    * @pre - none
    * @post LinkedList object is created, member variables initialized.
    */
    LinkedList();
    
       /** DESTRUCTOR
    * @pre - none
    * @post LinkedList object is destroyed
    */
    ~LinkedList();


       /** ASSIGNMENT OPERATOR OVERLOADING
    * @pre - LinkedList rhs exists
    * @param const LinkedList<T>& rhs - LinkedList to be traversed such as to make a deep copy of it inside the calling LinkedList
    * @post - This calling LinkedList object is set to be identical to the rhs
    */
    void operator=(const LinkedList<T>& rhs);

       /** COPY CONSTRUCTOR
    * @pre - LinkedList original exists
    * @param const LinkedList<T>& original - LinkedList to be traversed such as to make a deep copy inside this constructed List
    * @post - This LinkedList object is set to be identical to the original
    */
    LinkedList<T>(const LinkedList<T>& original);

    /**
    * @pre The index is valid
    * @post The entry is added to the list at the index, increasing length by 1
    * @param index, position to insert at (1 to length+1)
    * @param entry, value/object to add to the list
    * @throw std::runtime_error if the index is invalid
    */
    void insert(int index, T entry);

    /**
    * @pre The index is valid
    * @post The entry at given position is removed, reducing length by 1 
    * @param index, position to remove at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    void remove(int index);

    /**
    * @pre The index is valid
    * @post None 
    * @param index, position in list to fetch and return the entry at.
    * @return T returns the value stored at the given index
    * @throw std::runtime_error if the index is invalid
    */
    T getEntry(int index);

    /**
    * @pre None
    * @post List is empty
    * @throw None
    */
    void clear();

    /**
    * @pre The index is valid (must already exist)
    * @post Given entry overrides the entry at the given index 
    * @param index, position to override at (1 to length)
    * @param entry, value/object to place at given index
    * @throw std::runtime_error if the index is invalid
    */
    void setEntry(int index, T entry);

    /**
    * @pre
    * @post
    * @return int returns the value of m_length, length of the list
    */
    int getLength();
  private:

    //Private member variable
    //Stores the length of this list
    int m_length;

    //Private member variable
    //Stores a pointer to the front of this list
    Node<T>* m_front;
   
    
       /** private helper function
    * @pre -
    * @param int index - position in this list to traverse to and return a pointer to 
    * @post - none
    * @return Node<T>* - a pointer to the Node in this object List given by the provided index
    */
    Node<T>* traverseList(int index) const;

       /** private helper function
    * @pre - called inside the general public-facing insert function. Handles all cases EXCEPT for inserting at the beginning and ending of the list.
    * @param Node<T>* prevNode - pointer to the Node in this List that must have the provided entry inserted directly following it.
    * @param T newEntry - new List entry to be added.
    * @post - newEntry is added to this List
    */
    void insertAfter(Node<T>* prevNode, T newEntry);

       /** private helper function
    * @pre - called inside the general public-facing insert function. Handles inserting at the beginning of the list
    * @param T newEntry - new List entry to be added.
    * @post - newEntry is added to the beginning of the List
    */
    void push(T newEntry);

       /** private helper function
    * @pre - called inside the general public-facing insert function. Handles inserting at the end of the list
    * @param T newEntry - new List entry to be added.
    * @post - newEntry is added to the end of the List
    */
    void append(T newEntry);


};
#include "LinkedList.cpp"
#endif
