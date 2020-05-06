/*
 * @assignment EECS 268 Lab05 
 * @file: ListInterface.h
 * @author: Jack Gould
 * @brief: Interface header file provides a 'contract' for List classes to fulfill. LinkedList class will inherit from this class. 
 * @date: 04-01-2020
 */
#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

template <typename T>
class ListInterface
{
  public:

    //Destructor needs empty definition
    virtual ~ListInterface() {}

    /**
    * @pre The index is valid
    * @post The entry is added to the list at the index, increasing length by 1
    * @param index, position to insert at (1 to length+1)
    * @param entry, value/object to add to the list
    * @throw std::runtime_error if the index is invalid
    */
    virtual void insert(int index, T entry) = 0;

    /**
    * @pre The index is valid
    * @post The entry at given position is removed, reducing length by 1 
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    virtual void remove(int index) = 0;

    /**
    * @pre The index is valid
    * @post None 
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    virtual T getEntry(int index) = 0;

    /**
    * @pre None
    * @post List is empty
    * @throw None
    */
    virtual void clear() = 0;

    /**
    * @pre The index is valid (must already exist)
    * @post Given entry overrides the entry at the given index 
    * @param index, position to override at (1 to length)
    * @param entry, value/object to place at given index
    * @throw std::runtime_error if the index is invalid
    */
    virtual void setEntry(int index, T entry) = 0;

};
#endif
