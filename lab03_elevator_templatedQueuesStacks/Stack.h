/*
 * @project: elevator - templated stacks and queues
 * @file: Stack.h
 * @author: Jack Gould
 * @brief: Header file for templated Stack class. Lists member methods. Templated, Node based implementation. A stack is used in this lab to store the elevator's contents. Last in, first out structure.
 * @date: 02-19-2020
 */
#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include "PreconditionViolationException.h"



template <typename T>
class StackInterface
{
  public:
    virtual ~StackInterface() {}
  
    virtual bool isEmpty() const = 0;
    //returns true if the stack is empty, false otherwise
    
    virtual void push(const T value) = 0;
    /*Entry added to top of stack
    thrown PreconditionViolationException if push cannot occur (e.g. stack full)
    */

    virtual void pop() = 0;
    /*assumes the stack is not empty
    top of the stack is removed
    throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
    */

    virtual T peek() const = 0;
    /*assumes the stack is not empty
    returns the value at the top of the stack
    throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
    */
};

template <typename T>
class Stack: public StackInterface<T>
{
  private:
    Node<T>* m_top; // pointer to the top of the stack
    int m_length; // counter that holds the size of the stack
    const int stackCapacity = 50; // const int controlling the capacity of the stack. Currently set to 50 since a max size of the stack was NOT specified in lab 03 instructions on the wiki

  public:

   /* Constructor
    * @pre
    * @post - A new stack is created
    */
    Stack();
    

   /** 
    * @pre 
    * @post Returns length/size of stack
    **/
    int getLength() const;
  
    /**
     * @pre
     * @post - returns true if the stack is empty, false otherwise
     * @throw
     **/
    bool isEmpty() const;
  
    /**
     * @pre - assumes the Stack is not at capacity
     * @param const T value - the value of the entry to be added to the stack
     * @post - a new entry is added to the top of the stack with data set to value
     * @throw PreconditionViolationException if trying to add to a stack that is already at capacity
     **/
    void push(const T value);

    /**
     * @pre - assumes the Stack is not empty
     * @post - removes Node at the top of the stack
     * @throw PreconditionViolationException when a pop is attempted on an empty stack.
     **/
    void pop();

    /**
     * @pre - assumes the Stack is not empty
     * @return T - Returns the value stored at the top Node in the stack
     * @throw PreconditionViolationException when a peek is attempted on an empty stack. Does not return a value in this case.
     **/
    T peek() const;

};
#include "Stack.cpp"
#endif
