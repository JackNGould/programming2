/*
 * @assignment EECS 268 Lab07 
 * @file: main.cpp.
 * @author: Jack Gould
 * @brief: This is main.cpp for lab07. It takes in the maze data as an input file name and passes it to the mazeReader in an attempt to solve it. Catches exceptions and displays relevant output.
 * @date: 04-08-2020
 */
#include "MazeReader.h"
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
       MazeReader drawMaze(argv[1]);
     }
     catch(std::exception& e)
     {
       std::cout << e.what(); //print what happened
     }
  }

  return(0);
}

