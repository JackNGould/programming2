/*
 * @assignment EECS 268 Lab05 
 * @file: executive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Executive class. Defines member methods. Class governs the programs 'executive' actions of parsing the input file for instructions, running those instructions, and displaying the results.
 * @date: 04-01-2020
 */
#include "executive.h"
#include "matchParenthesis.h"
#include "permuteString.h"
#include "fibonacci.h"
#include "matchBraceBracketParen.h"
#include <iostream>
#include <fstream>

executive::executive(int argc, char** argv)
{
  char p[] = "parens";
  char s[] = "perm";
  char f[] = "fib";
  char v[] = "parensV2";
  if(cStrEndsWith(argv[0], p) == true)
  {
    char* input = argv[1];
    int length = strlen(argv[1]);
    matchParenthesis GO;
    if(GO.check(input, length))
    {
      std::cout << "\nExpression is Balanced\n";
    }
    else
    {
      std::cout << "\nExpression is NOT Balanced\n";
    }
  }
  else if(cStrEndsWith(argv[0], s) == true)
  {
    std::string input = argv[1];
    int length = input.length();
    permuteString stringPermuter;
    stringPermuter.printPermutations(input, 0, length-1);
  }
  else if(cStrEndsWith(argv[0], f) == true)
  {
    if(argc < 3)
    {
      std::cout << "Not enough parameters! Please include a value\n";
    }
    else
    {
      fibonacci fib;
      int number = atoi(argv[2]);
      if(strcmp(argv[1], "-i") == 0)
      {
        if(number <= 46)
        {
          int fibNumber = fib.runI(number);
          if(fibNumber >= 0)
          {
            std::cout << fibNumber << '\n';
          }
          else
          {
            std::cout << "Invalid index passed in. The fibonacci sequence begins at index 0 with a value of 0.\n";
          }
        }
        else
        {
          std::cout << "Invalid index passed in.\nConstraints on the int data type limit this program to generating index 46 or lower of the fibonacci sequence.\n";
        }
      }
      else if(strcmp(argv[1], "-v") == 0)
      {
        fib.runV(number); //calls fibonacci verify option
      }
    }
  }
  else if(cStrEndsWith(argv[0], v) == true)
  {
    char* input = argv[1];
    int length = strlen(argv[1]);
    int relevantCharCount = 0;
    for(int i=0;i<length;++i) //Counts relevant characters
    {
      if(input[i] == '[' || input[i] == ']' || input[i] == '{' || input[i] == '}' || input[i] == '(' || input[i] == ')')
      {
        ++relevantCharCount;
      }
    }
    char reducedString[relevantCharCount]; //creates char array of the necessary size, as determined by the loop above
    int indexTracker = 0; //tracks indices of the new array as the array is populated.
    for(int i=0;i<length;++i) //populates the new char array with all the relevant characters from the full string. 
    {
      if(input[i] == '[' || input[i] == ']' || input[i] == '{' || input[i] == '}' || input[i] == '(' || input[i] == ')')
      {
        reducedString[indexTracker] = input[i];
        ++indexTracker;
      }
    }//reducedString is now a char array containing ONLY the relevant characters of ()[]{} 
    
    
    matchBraceBracketParen checker;
    if(checker.check(reducedString, relevantCharCount))
    {
      std::cout << "\nThe sequence " << input << " is Balanced\n";
    }
    else
    {
      std::cout << "\nThe sequence " << input << " is NOT Balanced\n";
    }
  }
}

executive::~executive()
{
}

bool executive::cStrEndsWith(char* str, char* end)
{
  if (strlen(end) <= strlen(str))
  {
    int start = strlen(str)-strlen(end);
    if(strncmp(str+start,end,strlen(end)) == 0)
    {
      return true;
    }
  }
  return false;
}
