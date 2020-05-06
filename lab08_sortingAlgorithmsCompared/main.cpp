/*
 * @project Sorting Algorithms
 * @file: main.cpp.
 * @author: Jack Gould
 * @brief: This is main.cpp for the sorting algorithm lab. It initializes the program based on the input, passing instructions to the executive class after parsing the arguments passed in at execution time. Throws exceptions on bad input. 
 * @date: 04-13-2020
 */
#include "executive.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  
  if(argc < 6)
  {
    std::cout << "Not enough arguments!\n";
  }
  else
  {
    bool runAssert = false;
    std::string sortType = argv[1];
    int lBound = atoi(argv[2]);
    int uBound = atoi(argv[3]);
    int step = atoi(argv[4]);
    std::string outputFile = argv[5];
    if(argc >= 7)
    {
      std::string isAssert = argv[6];
      if(isAssert.compare("assert") ==0)
      {
        runAssert = true;
      }
    }
    if(sortType.compare("bubble") == 0 || sortType.compare("selection") == 0 || sortType.compare("insertion") == 0 || sortType.compare("merge") == 0 || sortType.compare("quick") == 0 || sortType.compare("quickWithMedian") == 0)
    {
      
      if (lBound > 0 && uBound > 0 && uBound > lBound && step>0 && (uBound-lBound)%step == 0)
      {
        executive sorter(sortType, lBound, uBound, step, outputFile, runAssert);
        sorter.runSorts();
      }
      else
      {
        std::cout << "Bad array size bounds entered. Lower first, upper second, size step next. All must be positive, and the step must evenly traverse the bounds\n";
          return 0;
      }
    }
    else
    {
      std::cout << "Invalid sort entered, options include:\nbubble\nselection\ninsertion\nmerge\nquick\nquickWithMedian\n";
      return 0;
    }

  }
  return(0);
}

