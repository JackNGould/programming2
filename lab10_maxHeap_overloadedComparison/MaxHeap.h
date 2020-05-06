/*
 * @project: Max Heap - Hospital patient simulation
 * @file: MaxHeap.h
 * @author: Jack Gould
 * @brief: Header File for templated MaxHeap class. Lists member methods. Objects that fill these maxHeaps must be comparable (likely with overloaded comparison operators, as in this lab). Class inherits from MaxHeapInterface
 * @date: 04-14-2020
 */

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "MaxHeapInterface.h"

template <typename ItemType>
class MaxHeap : public MaxHeapInterface<ItemType>
{
  public: 
   /* Constructor
    * @pre
    * @post - A new MaxHeap is created. 
    */
	  MaxHeap();

   /* Destructor
    * @pre Existing MaxHeap object calls this
    * @post - It is deleted
    */
  	~MaxHeap();
  
   /* 
    * @pre 
    * @return bool - Returns true if the MaxHeap is empty, false otherwise
    */
    bool isEmpty() const;
  
   /* 
    * @pre 
    * @return int - Returns the number of objects inside the MaxHeap
    */
    int getNumberOfNodes() const;
  
   /* 
    * @pre 
    * @return int - Returns the height(number of rows) of the MaxHeap
    */
    int getHeight() const;
  
   /* 
    * @pre The MaxHeap contains at least one object
    * @return ItemType - Returns the Item at the root of the MaxHeap. Const to prevent modification
    * @throws std::runtime_error if a peek is attempted on an empty Heap
    */
    ItemType peekTop() const; //can throw std::runtime_error
  
   /* 
    * @pre The MaxHeap contains at least one object
    * @param ItemType data - The object that is to be added to the MaxHeap
    * @post data is added to the MaxHeap, and upHeap is called on it to get it where it needs to go
    */
    void add(ItemType data);
  
   /* 
    * @pre The MaxHeap contains at least one object
    * @post the maximum value (root) of the MaxHeap is removed, and the last value is moved up to its spot, and then downHeaped
    * @throws std::runtime_error if a remove is attempted on an empty Heap
    */
    void remove(); //can throw std::runtime_error
  
   /* 
    * @pre The MaxHeap
    * @post MaxHeap is cleared of all values, but the object itself remains intact, except when called by the destructor
    */
    void clear();

  private:

    int m_arraySize; //counter that stores the size of the full array. Can only be sized in increments of full rows of the binary MaxHeap

    int m_heapSize; //counter that stores the heaps size. Equal to the number of objects inside

    int m_height; //counter that stores the height/num of rows of the MaxHeap

   /* 
    * @pre
    * @post The two objects passed in are swapped
    */
    void swap(ItemType &x, ItemType &y);

   /* 
    * @pre
    * @param int index - the index to find the parent of
    * @return int - returns the array index of the passed in index's parent
    */
    int getParentIndex(int index) const;

   /* 
    * @pre
    * @return bool - returns true if the current Row of the maxHeap is full, false otherwise
    */
    bool needNewRow() const;

   /* 
    * @pre - The array is full 
    * @post - the Array is increased in size. Adds enough space to fill the next row
    */
    void increaseArraySize();

   /* 
    * @pre A value was removed, emptying a previously filled row
    * @post - the Array is decreased in size. Deletes the space necessary for the now vacant row
    */
    void decreaseArraySize();

   /* Recursive
    * @pre A value was placed at the root/index 0 of the array, calling this function. Or, this function called itself recursively
    * @post - Recursively swaps the object with the maximum of its two children, until it satisfies the MaxHeap's rules
    */
    void downHeap(int index);
  
   /* Recursive
    * @pre A value was placed at the back, calling this function. Or, this function called itself recursively
    * @post - Recursively swaps the object with its parent if necessary, until MaxHeap structure is satisfied
    */
    void upHeap(int index);
  
    ItemType* m_array; // The Actual Array which stores all the data
};
#include "MaxHeap.cpp"
#endif
