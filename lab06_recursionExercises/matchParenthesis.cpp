/*
 * @assignment: EECS_268 Lab05 Exercise1
 * @file: matchParenthesis.cpp
 * @author: Jack Gould
 * @brief: Implementation file for matchParenthesis class. It recursively evaluates character arrays for matching sets of parenthesis 
 * @date: 04-10-2020
 */
#include "matchParenthesis.h"


bool matchParenthesis::check(char* str, int length) 
{  
    if (length == 0)
    {
      return true; 
    }
    if (length == 1) 
    {
      return false; 
    }
    if (str[0] == ')')
    {
      return false; 
    }
  
    int count = 0;
    int i = 0; // i must be instantiated before the for loop so that it is included in the scope of the subsequent if statements
    for (i = 1; i < length; ++i)
    {
      if (str[i] == '(')
      {
        ++count;
      }
      if (str[i] == ')')
      {
        if (count <= 0) //deals with too many closing parenthesis
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
      return false; // Missing closing bracket
    }

    if (i == 1) 
    {
      return check((str+2), (length-2));  // Handles recursion for matching set of parenthesis with nothing inside. Checks remainder of string
    }
    
    /**
     * The else statement below handles recursion for matched parenthesis with another possible set inside.
     * First check evaluates the contents of the previous set found.
     * Second check continues evaluation of the string after the matched set.  
     **/
    else
    {
      return check((str+1), (i-1)) && check((str+1+i), (length-1-i)); 
    }
} 
  
