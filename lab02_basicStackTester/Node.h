/*
 * @project: basicStackTester
 * @file: Node.h
 * @author: Jack Gould
 * @brief: Header file for Node class. Lists member methods. Not yet templated. Allows char entry types. Will fill the stack in this lab
 * @date: 02-05-2020
 */
#ifndef NODE_H
#define NODE_H

class Node
{
private:
	char m_entry;
	Node* m_next;
	
public:
	Node(char entry);
	char getEntry() const;
	void setEntry(char entry);
	Node* getNext() const;
	void setNext(Node* next);
};
#endif
