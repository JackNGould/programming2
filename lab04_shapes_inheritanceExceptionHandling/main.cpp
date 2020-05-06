/*
 * @project: shapes - inheritance and exception handling
 * @file: main.cpp
 * @author: Jack Gould
 * @brief: main.cpp for shapes lab. Does very little, just initializing the program based on the input, creating an executive object using the passed in file name and running the executive object. Throws exception on bad input.
 * @date: 02-26-2020
 */
#include "Executive.h"
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
      Executive shapeBuilder(fName);
      shapeBuilder.run();
    }
    catch(std::runtime_error& rte)
    {
      std::cout << '\n' << rte.what() << '\n';
    }
  }

  return(0);
}

