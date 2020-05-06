/*
 * @assignment EECS 268 Lab05 
 * @file: Executive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Executive class. Defines member methods. Class governs the programs 'executive' actions of parsing the input file for instructions, running those instructions, and displaying the results.
 * @date: 04-01-2020
 */
#include "Executive.h"
#include <iostream>
#include <fstream>

Executive::Executive(std::string fileName)
{
  badLine = 0;
  cError = 0;
	std::ifstream inFile(fileName);
	if(inFile.is_open())
	{
		std::string line;
		int lineCount = 0;
		while(getline(inFile, line))
		{
			commandList.insert(lineCount+1, line);
			++lineCount;
		}
		inFile.close();
	}
	else
	{
		throw(std::runtime_error("\nFile couldn't be opened.\n"));
	}
}

Executive::~Executive()
{
  commandList.clear();
  histList.clear();
}

void Executive::run()
{
  std::cout << "\nLooking for valid input lines...\n";
  int commandCount = commandList.getLength();
  std::string command = "";
  for(int i=0;i<commandCount;++i)
  {
    try
    {
      command = commandList.getEntry(1);
      commandList.remove(1);
      this->executeCommand(command, i+1);
    }
    catch(std::runtime_error& rte)
    {
      std::cout << '\n' << rte.what() << '\n';
    }
  }
  std::cout << "\n\nSUMMARY:\n\tLines Parsed:" << commandCount << "\n\tBad Lines:" << badLine << "\n\tCommands Found:" << commandCount-badLine << "\n\tCommand Errors:" << cError << "\nExiting Program now...\n";
}

void Executive::executeCommand(std::string command, int lineNum)
{
  if (strStartsWith(command, "NAVIGATE ") == true)
  {
    try
    {
      std::string navURL = strEndsWith(command, "NAVIGATE ");
      jackBrowser.navigateTo(navURL);
      //std::cout << "\nLine #" << lineNum << " - \"" << command << "\" SUCCESS.\n";
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout << "\nLine #" << lineNum << " - \"" << command << "\" FAILED.\n";
      std::cout << '\t' << rte.what() << '\n';
    }
  }
  else if(strStartsWith(command, "BACK") == true)
  {
    try 
    {
      jackBrowser.back();
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout << "\nLine #" << lineNum << " - \"BACK\" Already at beginning of history.\n";
      std::cout << '\t' << rte.what() << '\n';
    }

  }
  else if(strStartsWith(command, "FORWARD") == true)
  {
    try
    {
      jackBrowser.forward();
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout << "\nLine #" << lineNum << " - \"FORWARD\" Already at end of history.\n";
      std::cout << "\t" << rte.what() << '\n';
    }
  }
  else if(strStartsWith(command, "HISTORY") == true)
  {
    try
    {
      histList.clear();
      jackBrowser.copyCurrentHistory(histList);
      std::cout << "\nLine #" << lineNum << " requests HISTORY.";
      std::cout << "\nOldest\n===========\n";
      int histLength = histList.getLength();
      if(histLength == 0)
      {
        std::cout << "History Empty!\n";
      }
      for(int i=1;i<=histLength;++i)
      {
        if(histList.getEntry(i) == jackBrowser.current())
        {
          std::cout << histList.getEntry(i) << "  <==current\n";
        }
        else
        {
          std::cout << histList.getEntry(i) << '\n';
        }
      }
      std::cout << "===========\nNewest\n";
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout << "\nLine #" << lineNum << " HISTORY error.\n";
      std::cout << '\t' << rte.what() << '\n';
    }
  }
  else
  {
    ++badLine;
    std::cout << "\nLine #" << lineNum << " - \"" << command << "\" could not be interpreted as a valid command.\nConsult the README.md";
    throw(std::runtime_error("\tInput file: Bad line ignored!"));
  }
}

bool Executive::strStartsWith(std::string str, std::string start)
{
  if (start.size() <= str.size())
  {
    if(str.compare(0,start.size(),start) == 0)
    {
      return true;
    }
  }
  return false;
}

std::string Executive::strEndsWith(std::string str, std::string start)
{
  if(start.size() < str.size())
  {
    std::string end = str.substr(start.size(), str.size());
    return end;
  }
  else
  {
    throw(std::runtime_error("Bad call on strEndsWith, size of starting string must be less than the entire command string. This could happen if a NAVIGATE command was passed in without providing URL argument."));
  }
}
