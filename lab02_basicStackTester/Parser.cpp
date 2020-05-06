/*
 * @project: basicStackTester
 * @file: Parser.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Parser class. Defines member methods. Class checks if a sequence is balanced using a stack of char objects. 
 * @date: 02-05-2020
 */


#include "Parser.h"
#include <iostream>
#include <stdexcept>
#include <limits>

Parser::Parser()
{
	sequence = "";
	length = 0;

}

void Parser::run()
{
	std::cout << "\nEnter your sequence: ";
	std::cin >> sequence;
	while(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\nInvalid Input, try again: ";
		std::cin >> sequence;
		std::cout << '\n';
	}
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	makeStack(sequence);
	if(isBalanced() == true)
	{
	std::cout << "\nSequence IS balanced\n";
	}
	else
	{
	std::cout << "\nSequence is NOT balanced\n";
	}	
}

void Parser::makeStack(std::string seq)
{
	length = seq.length();
	for(int i=0;i<length;++i)
	{
		seqStack.push(seq[i]);
	}

}

bool Parser::isBalanced()
{
	int count = 0;
	if(length == 0)
	{
    std::cout << "\nString is empty! Balanced by definition.\n";
		return true;
	}
	else if (length % 2 != 0)
	{
    std::cout << "\nNumber of chars is odd, balance impossible.\n";
		return false;
	}
	else
	{
    std::cout << "\nChar count is even, checking for balance starting from the back...\n";
		for(int i=0;i<length;++i)
		{
			char temp = seqStack.peek();
			seqStack.pop();
			if(temp == '}')
			{
				++count;
			}
			else if(temp == '{')
			{
				--count;
			}
			else if(temp != '{' && temp != '}')
			{
				std::cout << "\nNon curly brace found, please ONLY include curly braces {} in the string.\n";
				return false;
			}
			if(count < 0)
			{
        std::cout << "\nUn-closed brace found, balance impossible.\n";
				return false;
			}
		}
		if(count == 0)
		{
      std::cout << "\nAll braces closed, balance guaranteed.\n";
			return true;
		}
		else
    {
      std::cout << "\nSequence is missing 2 or more opening braces. Balance impossible.\n";
      return false;
    }
	}
}
