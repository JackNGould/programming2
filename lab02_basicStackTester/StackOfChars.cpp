/*
 * @project: basicStackTester
 * @file: StackOfChars.cpp
 * @author: Jack Gould
 * @brief: Implementation file for StackOfChars class. Defines member methods. Node based stack class that accepts chars as data. 
 * @date: 02-05-2020
 */


#include "StackOfChars.h"

StackOfChars::StackOfChars()
{
	m_top = nullptr;
}

StackOfChars::StackOfChars(const StackOfChars& orig)
{
  Node *traverse1 = nullptr;
  Node *traverseOrig = orig.m_top;
  while(traverseOrig != nullptr)
  {
    Node *temp = new Node(traverseOrig->getEntry());
    if(m_top == nullptr)
    {
      m_top = temp;
      traverse1 = temp;
    }
    else
    {
      traverse1->setNext(temp);
      traverse1 = temp;
    }
    traverseOrig = traverseOrig->getNext();
  }
  
}


StackOfChars::~StackOfChars()
{
	while(isEmpty() != true)
	{
		pop();
	}
}

void StackOfChars::operator=(const StackOfChars& rhs)
{
  while(this->m_top != nullptr)
  {
    this->pop();
  }
  Node *traverse1 = nullptr;
  Node *traverseRHS = rhs.m_top;
  while(traverseRHS != nullptr)
  {
    Node *temp = new Node(traverseRHS->getEntry());
    if(m_top == nullptr)
    {
      m_top = temp;
      traverse1 = temp;
    }
    else
    {
      traverse1->setNext(temp);
      traverse1 = temp;
    }
    traverseRHS = traverseRHS->getNext();
  }
}

void StackOfChars::push(char entry)
{
	if(m_top == nullptr)
	{
		m_top = new Node(entry);
		m_top->setNext(nullptr);
	}
	else
	{
		Node* temp = m_top;
		m_top = new Node(entry);
		m_top->setNext(temp);
	}
}

void StackOfChars::pop()
{
	if(m_top != nullptr)
	{
		Node* temp = m_top;
		m_top = m_top->getNext();
		delete temp;
	}
}

char StackOfChars::peek() const
{
	if(m_top != nullptr)
	{
		return (m_top->getEntry());
	}
  else
  {
    /*
     * std::cout << "\nThis else block will never run, so these won't print...\n";
     * std::cout << "...\n...unless peek() somehow gets attempted on an empty stackOfChars.\n";
     * std::cout << "\nProgram flow has been designed to make this impossible...";
     * std::cout << "... but '!' will nonetheless be returned as the char in said hypothetical scenario.\n";
     * std::cout << "\nI did this to prevent a compiler warning from reaching end of non-void function.\n";
     * std::cout << "\nTypically one would throw an exception here...\n";
     * std::cout << "...but those haven't been covered yet and I didn't want to include it.\n";
     * ...
     * ...I also forgot that I would have to #include <iostream> here to make this compile.
     * ...So forget it its now a comment.
     */
    return '!';
  }
}

bool StackOfChars::isEmpty() const
{
	if(m_top == nullptr)
	{
		return true;
	}
	return false;
}

