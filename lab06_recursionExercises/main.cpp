/*
 * @assignment EECS 268 Lab 06
 * @file: main.cpp
 * @author: Jack Gould
 * @brief: This is main.cpp for the recursive exercise lab. It simply passes the parameters to an executive task manager.
 * @date: 04-10-2020
 */
#include "executive.h"
#include <iostream>
#include <cstring>


int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    executive taskManager(argc, argv);
  }
  return(0);
}


