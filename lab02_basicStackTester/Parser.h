/*
 * @project: basicStackTester
 * @file: Parser.h
 * @author: Jack Gould
 * @brief: Header file for Parser class. Lists member methods. Class checks if a sequence is balanced using a stack of char objects. 
 * @date: 02-05-2020
 */


#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "StackOfChars.h"

class Parser
{
	private:

    /*
     * @pre - called during run. Passes in the sequence given by the user, to convert it to a stack of chars from a std:;string
     * @param std::string seq: the sequence given by the user to be converted to a stack of chars
     * @post - the chars of seq are stored in StackOfChars seqStack
     */
		void makeStack(std::string seq);

    /*
     * @pre - called during run. 
     * @return - boolean representing whether the sequence stored in seqStack is a balanced string of curly braces.
     */
		bool isBalanced();

    //PRIVATE MEMBER VARIABLES
		std::string sequence;
		int length;
		StackOfChars seqStack;

	public:
    /* CONSTRUCTOR
     * @pre - program run in -p parser mode
     * @post - Parser object created
     */
		Parser();

    /*
     * @pre - Parser object successfully created
     * @post - program runs, requesting a sequence from the user to check if balanced
     */
		void run();

};
#endif
