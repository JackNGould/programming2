/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: main.cpp
 * @author: Jack Gould
 * @brief: main.cpp for BST lab. Initializes program based on input. Creates executive object, passing in a data file. Catches and prints exceptions for bad input.
 * @date: 04-17-2020
 */
#include "executive.h"
#include <iostream>
#include "jackException.h"


int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    try
    {
      executive pokedexTree(argv[1]); //sample creation of executive object
      pokedexTree.run();
    }
    catch(jackException& rte)
    {
      std::cout << rte.what();
    }
  }

  return(0);
}

