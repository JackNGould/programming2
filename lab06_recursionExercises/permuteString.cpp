/*
 * @assignment: EECS_268 Lab5.2
 * @author: permuteString.cpp
 * @author: Jack Gould
 * @brief: Implementation file for the permuteString class, which will print all possible permutations of a passed in string.
 *    Assumes string contains all unique characters. If this is not the case, duplicates will occur.
 * @date: 04-10-2020
 */
#include "permuteString.h"
#include <iostream>
#include <string>


void permuteString::swap(char &x, char &y)
{
  char temp;
  temp = x;
  x = y;
  y = temp;
}

void permuteString::printPermutations(std::string str, int focus, int end)
{
  if (focus == end)
  {
    ++permutationCounter;
    std::cout << permutationCounter << ") " << str << '\n';
  }
  else
  {
    for (int i = focus; i <= end; ++i) 
    {
      swap((str[focus]), (str[i])); //swap two characters in string.
      printPermutations(str, (focus+1), end); //recursion occurs here. Advances to next character index in string.    
      swap((str[focus]), (str[i])); //undo the swaps before next iteration of loop
    }
  }
}

