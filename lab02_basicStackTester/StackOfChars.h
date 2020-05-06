/*
 * @project: basicStackTester
 * @file: StackOfChars.h
 * @author: Jack Gould
 * @brief: Header file for StackOfChars class. Lists member methods. Node based stack class that accepts chars as data. 
 * @date: 02-05-2020
 */

#ifndef STACKOFCHARS_H
#define STACKOFCHARS_H

#include "Node.h"

class StackOfChars
{
	private:
	Node* m_top;
	
	public:
	
	StackOfChars();

  /** COPY CONSTRUCTOR
  * @pre StackOfChars orig exists already
  * @post new StackOfChars is created with identical contents to orig
  * @param StackOfChars& orig the stack to construct a copy of
  * @throw None
  **/
	StackOfChars(const StackOfChars& orig);

  /**
  * @pre None
  * @post StackOfChars is deleted
  * @param 
  * @throw None
  **/
  ~StackOfChars();

  /** ASSIGNMENT OPERATOR OVERLOADING
  * @pre StackOfChars rhs exists already, called by another stack.
  * @post the calling stack has its contents erased, then set to a copy of Stack rhs. 
  * @param StackOfChars& rhs the stack to duplicate in the calling stack
  * @throw None
  **/
	void operator=(const StackOfChars& rhs);
	
       /** Here's an example of a doxygen comment block. Do this for all methods
       * @pre None
       * @post entry is added to top of the stack
       * @param entry, the element to be added to the stack
       * @throw None
       **/
	void push(char entry);
	
       /** Here's an example of a doxygen comment block. Do this for all methods
       * @pre Stack is non-empty
       * @post Top element is removed from the stack
       * @param None
       * @throw None  
       **/
	void pop();
  
  /** Here's an example of a doxygen comment block. Do this for all methods
  * @pre called only by reverse() function
  * @post Recursive function used to reverse a stack. Recursively puts an entry on bottom of stack
  * @param char entry: the entry to be placed at the bottom of stack
  * @throw None  
  **/
  char putOnBottom(char entry);

  /**
  * @pre called by the copy constructor or assignment operator
  * @post reverses entire stack by recursively calling putOnBottom()
  * @param 
  * @throw None  
  **/
  static void reverse();
	
  /**
  * @pre
  * @post returns char stored on top of stack (m_top)
  * @param 
  * @throw None  
  **/
	char peek() const;

  /**
  * @pre
  * @post returns bool true if stack is empty, false otherwise
  * @param 
  * @throw None  
  **/
	bool isEmpty() const;

};
#endif
