/*
 * @project: Max Heap - Hospital patient simulation
 * @file: main.cpp
 * @author: Jack Gould
 * @brief: main.cpp for max heap hospital queue simulation. Does very little, just initializes the program with an executive object passed in at runtime. Throws exception on bad input.
 * @date: 04-14-2020
 */
#include "executive.h"
#include <iostream>
#include <stdexcept>


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
      std::string fName = argv[1];
      executive Hospital(fName);
      Hospital.run();
    }
    catch(std::runtime_error& rte)
    {
      std::cout << '\n' << rte.what() << '\n';
    }
  }

  return(0);
}

