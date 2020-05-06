/*
 * @assignment EECS 268 Lab05 
 * @file: main.cpp
 * @author: Jack Gould
 * @brief: main initializes the program based on input. Program looks for the first parameter as file name of the input data. 
 * @date: 04-01-2020
 */

#include "Executive.h"
#include <iostream>
#include <stdexcept>


int main(int argc, char* argv[])
{
	if(argc < 2) std::cout << "No parameter/argument given\n";
	else
	{
		try
		{
			Executive lab05(argv[1]);
			lab05.run();
		}
		catch(std::runtime_error& rte)
		{
			std::cout << "\n" << rte.what();
		}
	}

  return(0);
}

