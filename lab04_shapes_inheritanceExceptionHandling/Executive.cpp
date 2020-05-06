/*
 * @project: shapes - inheritance and exception handling
 * @file: executive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Executive class. Defines member methods. Class governs the programs 'executive' actions of parsing the input file for commands, attempting to run them, and displaying the results.
 * @date: 02-26-2020
 */
#include "Executive.h"
#include <iostream>
#include <fstream>
#include <cstring> //to use a string comparison method that I like

Executive::Executive(std::string fName)
{
  m_fName = fName;
  commandsFound = 0;
  commentCounter = 0;
  cError = 0;
  std::ifstream inFile(fName);
  if (inFile.is_open())
  {
    std::string line;
    while (getline(inFile, line))
    {
        commandList.enqueue(line.c_str());
    }
    inFile.close();

  }
  else
  {
    throw(std::runtime_error("\nFile not found/opened.\n"));
  }
}

Executive::~Executive()
{
	delete boxOfShapes;
  while(commandList.isEmpty() != true) //This check is not needed, assuming the file is formatted correctly.
  {
    commandList.dequeue();
  }
}

bool Executive::strStartsWith(std::string str, std::string start)
{
  if (start.size() <= str.size())
  {
    if(strncmp(str.c_str(), start.c_str(), start.size()) ==0)
    {
      return true;
    }
  }
  return false;
}

std::string Executive::strEndsWith(std::string str, std::string start)
{
  if (start.size() < str.size())
  {
    std::string end = str.substr(start.size(), str.size());
    return end;
  }
  else
  {
    throw(std::runtime_error("bad call. size of starting string must be less than whole command."));
  }
}

void Executive::run()
{
  int commandCount = commandList.getLength();
  std::string command;
  for(int i=0;i<commandCount;++i)
  {
    if(exit == false)
    {
      try
      {
        if(i == 0)
        {
          command = commandList.peek();
          std::stringstream firstEntry(command);
          if(firstEntry >> containerSize)
          {
            if(containerSize > 0 && containerSize <= 250000)
            {
              boxOfShapes = new ShapeContainer(containerSize);
              commandList.dequeue();
            }
            else
            {
              throw(std::runtime_error("\nInput file gave a bad value for containerSize. Program accepts values between 1 and 250,000.\n"));
            }
          }
          else
          {
            throw(std::runtime_error("\nCould not get an integer containerSize out of input file's first entry.\n"));
          }
        }
        else
        {
          command = commandList.peek();
          this->executeCommand(command, i+1);
          commandList.dequeue();
        }
      }
      catch(std::runtime_error& rte)
      {
        std::cout << '\n' << rte.what() << "\nError, bad command list length or format?\n";
      }
    }
  }
}

void Executive::addShape(std::stringstream& ss)
{
  
  std::string indexString = "";
  ss >> indexString;
  int addIndex = std::stoi(indexString);
  std::string shapeCode = "";
  ss >> shapeCode;
  if(shapeCode == "CIR")
  {
    std::string circleRadius = "";
    ss >> circleRadius;
    double radius = std::stod(circleRadius);
    Circle* tempCirc = new Circle(radius);
    boxOfShapes->add(tempCirc, addIndex);
  }
  else if(shapeCode == "TRI")
  {
    std::string triBase = "";
    std::string triHeight = "";
    ss >> triBase;
    ss >> triHeight;
    double base = std::stod(triBase);
    double height = std::stod(triHeight);
    Triangle* tempTri = new Triangle(base, height);
    boxOfShapes->add(tempTri, addIndex);
  }
  else if(shapeCode == "REC")
  {
    std::string recLength = "";
    std::string recWidth = "";
    ss >> recLength;
    ss >> recWidth;
    double length = std::stod(recLength);
    double width = std::stod(recWidth);
    Rectangle* tempRec = new Rectangle(length, width);
    boxOfShapes->add(tempRec, addIndex);
  }
  else
  {
    throw(std::runtime_error("Incorrect shapeCode provided"));
  }
}

void Executive::executeCommand(std::string command, int lineNum)
{
  if(command[0] == '#')
  {
    ++commentCounter;
    return;
  }
  std::stringstream ssWhole(command);
  std::string instruction = "";
  ssWhole >> instruction;
  if(instruction == "EXIT")
  {
    ++commandsFound;
    std::cout << "\nCommand #" << commandsFound << " on line #" << lineNum << " of " << m_fName << " said to exit!\n";
    std::cout << "Summary:\n\tCommand Lines Parsed:" << lineNum-1 << "\n\t# of unrecognized Input Commands:" << (lineNum-1-commentCounter-commandsFound) << "\n\tCommands Found:" << commandsFound;
    std::cout << "\n\tCommand Errors:" << cError;
    std::cout << "\nExiting program...\n";
    exit = true;
  }
  else if(instruction == "ADD")
  {
    ++commandsFound;
    try
    {
      addShape(ssWhole);
      std::cout << "\nCommand #" << commandsFound << " on line #" << lineNum << " successfully added a shape!\n";
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout <<"\nADD ERROR\n";
      std::cout << "\tCommand #" << commandsFound << " on line #" << lineNum << " of " << m_fName << " - \"" << command << "\"";
      std::cout << "\n\t" << rte.what() << '\n';
    }
  }
  else if(instruction == "DELETE")
  {
    ++commandsFound;
    try
    {
      int deletionIndex = 0;
      if(ssWhole >> deletionIndex)
      {
        boxOfShapes->remove(deletionIndex);
        std::cout << "\nCommand #" << commandsFound << " on line #" << lineNum << " successfully deleted shape " << deletionIndex;
      }
      else
      {
        throw(std::runtime_error("Could not get an integer deletion index from string input. No delete performed."));
      }
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout << "\nDELETE ERROR\n";
      std::cout << "\tCommand #" << commandsFound << " on line #" << lineNum << " of " << m_fName << " - \"" << command << "\"";
      std::cout << "\n\t" << rte.what() << "\n";
    }
  }
  else if(instruction == "PRINT")
  {
    ++commandsFound;
    try
    {
      int printIndex = 0;
      if(ssWhole >> printIndex)
      {
        std::cout << '\n' << boxOfShapes->shapeName(printIndex) << " in index " << printIndex <<  " has area: " << boxOfShapes->area(printIndex) << "\n";
        std::cout << "Command #" << commandsFound << " on line #" << lineNum << " successfully printed shape at container index " << printIndex << '\n';
      }
      else
      {
        throw(std::runtime_error("Could not get an integer printing index from string input, no print performed."));
      }
    }
    catch(std::runtime_error& rte)
    {
      ++cError;
      std::cout << "\nPRINT ERROR\n";
      std::cout << "\tCommand #" << commandsFound << " on line #" << lineNum << " of " << m_fName << " - \"" << command << "\"";
      std::cout << "\n\t" << rte.what() << "\n";
    }
  }
  else
  {
    std::cout << "\nINPUT ERROR for attempted command on line #" << lineNum << " of " << m_fName << " - \"" << command << "\"";
    std::cout << "\nNo valid command recognized!\nOptions are: ADD,DELETE,PRINT,EXIT";
    std::cout << "\nTo avoid these messages remove or comment out invalid input lines by beginning the line with a '#'\n";
  }
}
