/*
 * @project: basicStackTester
 * @file: Node.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Node class. Defines member methods. Not yet templated. Allows char entry types. Will fill the stack in this lab
 * @date: 02-05-2020
 */
#include "Node.h"

void Node::setEntry(char entry)
{
	m_entry = entry;
}
char Node::getEntry()const
{
	return (m_entry);
}
Node* Node::getNext()const
{
	return (m_next);
}
void Node::setNext(Node* next)
{
	m_next = next;
}
Node::Node(char entry)
{
	m_next=nullptr;
	m_entry=entry;
}
