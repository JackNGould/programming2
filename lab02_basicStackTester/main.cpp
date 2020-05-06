/*
 * @project: basicStackTester
 * @author: Jack Gould
 * @file: main.cpp
 * @brief: This is main.cpp for the basic stack tester lab. It initializes the program based on input. Two possible modes (-p or -t).  
 * @date 02-05-2020
 */
#include <iostream>
#include <cstring>
#include "StackOfChars.h"
#include "StackTester.h"
#include "Parser.h"
#include <limits>

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters\n";
  }
  else if((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "-t") == 0))
  {
    if(strcmp(argv[1], "-p") == 0)
    {
      Parser parserMode;
      parserMode.run(); 
    }
    else if(strcmp(argv[1], "-t") == 0)
    {
      StackTester testIt;
      testIt.runTests();
    }
  }
  else
  {
	std::cout << "Invalid flag specification. Please pass \"-p\" for parser mode or \"-t\" for test mode.\n";	
  }
  return(0);
}

