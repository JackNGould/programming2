/*
 * @assignment: EECS 268 Lab 06
 * @file: matchParenthesis.cpp
 * @author: Jack Gould
 * @brief: Implementation file for matchParenthesis class. It recursively evaluates character arrays for matching sets of parenthesis, brackets, and braces
 * @date: 04-10-2020
 */
#include "matchBraceBracketParen.h"
#include <cstring>


char matchBraceBracketParen::getCloseChar(char c)
{
  switch(c)
  {
    case'(':
      return ')';
    case '[':
      return ']';
    case '{':
      return '}';
    default:
      return 'j';
  }
}

bool matchBraceBracketParen::check(char* str, int length) 
{  
    if (length == 0)
    {
      return true; 
    }
    if (length == 1) 
    {
      return false; 
    }
    if (str[0] == ')' || str[0] == ']' || str[0] == '}')
    {
      return false; 
    }
  
    char close = getCloseChar(str[0]); // holds the correct closing char for current opening char being evaluated(str[0])
    int count = 0;
    int i = 0; // i must be instantiated before the for loop so that it is included in the scope of the subsequent if statements
    for (i = 1; i < length; ++i)
    {
      if (str[i] == str[0])
      {
        ++count;
      }
      if (str[i] == close)
      {
        if (count <= 0) // Deals with too many closing characters 
        {
          break;
        } 
        else
        {
          --count;
        }
      } 
    } 
  
    if (i == length)
    {
      return false; // Missing closing char
    }

    if (i == 1) 
    {
      return this->check((str+2), (length-2)); //Handles recursion for matching set of parenthesis with nothing inside. Checks remainder of string
    }
  
    /**
     * The else statement below handles recursion for matched characters with another possible set inside.
     * First check evaluates the contents of the previous set found.
     * Second check continues evaluation of the string after the matched set.  
     **/
    else
    {
      return this->check((str+1), (i-1)) && this->check((str+1+i), (length-1-i)); 
    }
} 

