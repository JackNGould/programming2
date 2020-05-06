/*
 * @project: elevator - templated stacks and queues
 * @file: main.cpp
 * @author: Jack Gould
 * @brief: main.cpp for elevator lab to test templated stacks and queues. Does very little, just initializes the program based on input, creating a single BuilsingExecutive object using the passed in file name, and running the object. Throws exception on bad input.
 * @date: 02-19-2020
 */
#include "BuildingExecutive.h"
#include <iostream>


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
      BuildingExecutive building(fName);
      building.run();
    }
    catch(PreconditionViolationException& rte)
    {
      std::cout << '\n' << rte.what() << '\n';
    }
  }

  return(0);
}

