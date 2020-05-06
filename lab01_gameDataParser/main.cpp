/*
 * @project: gameDataParser
 * @file: main.cpp.
 * @author: Jack Gould
 * @brief: This is main.cpp for the game data parser lab. It does very little, just initializing the program based on input and creating an executive object with the filename passed in at runtime. Throws exception on bad input.
 * @date: 01-01-2020
 */
#include "dataManager.h"
#include "game.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
     dataManager gameList(argv[1]); //sample creation of executive object
     gameList.run();
  }

  return(0);
}

