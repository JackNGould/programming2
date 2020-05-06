/*
 * @project: Max Heap - Hospital patient simulation
 * @file: MaxHeapInterface.h
 * @author: Jack Gould
 * @brief: Header File for MaxHeapInterface class. Lists member methods, defines empty destructor. Class provides a 'contract' for inheriting subclasses to fulfill. MaxHeap inherits from this interface in this lab 
 * @date: 04-14-2020
 */
#ifndef MAX_HEAP_INTERFACE_H
#define MAX_HEAP_INTERFACE_H


template <typename ItemType>
class MaxHeapInterface
{
   public:
   virtual ~MaxHeapInterface(){};

   /* 
    * @pre 
    * @return bool - Returns true if the MaxHeap is empty, false otherwise
    */
   virtual bool isEmpty() const = 0;

   /* 
    * @pre 
    * @return int - Returns the number of objects inside the MaxHeap
    */
   virtual int getNumberOfNodes() const = 0;

   /* 
    * @pre 
    * @return int - Returns the number of objects inside the MaxHeap
    */
   virtual int getHeight() const = 0;

   /* 
    * @pre The MaxHeap contains at least one object
    * @return ItemType - Returns the Item at the root of the MaxHeap. Const to prevent modification
    * @throws std::runtime_error if a peek is attempted on an empty Heap
    */
   virtual ItemType peekTop() const = 0; //Can throw std::runtime_error

   /* 
    * @pre The MaxHeap contains at least one object
    * @param ItemType data - The object that is to be added to the MaxHeap
    * @post data is added to the MaxHeap, and upHeap is called on it to get it where it needs to go
    */
   virtual void add(ItemType data) = 0;

   /* 
    * @pre The MaxHeap contains at least one object
    * @post the maximum value (root) of the MaxHeap is removed, and the last value is moved up to its spot, and then downHeaped
    * @throws std::runtime_error if a remove is attempted on an empty Heap
    */
   virtual void remove() = 0; //Can throw std::runtime_error

   /* 
    * @pre The MaxHeap
    * @post MaxHeap is cleared of all values, but the object itself remains intact, except when called by the destructor
    */
   virtual void clear() = 0;

};
#endif
