/*
 * @project: Max Heap - Hospital patient simulation
 * @file: executive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Executive class. Defines member methods. Class governs the programs 'executive' actions of parsing the input file for hospital commands and attempting to run them using the max heap
 * @date: 04-14-2020
 */


#include <stdexcept>
#include "executive.h"
#include <iostream>
#include <fstream>
#include <cstring> //to use a string comparison method that I like
#include <sstream>


executive::executive(std::string fName)
{
  arrivalOrder = 0;
  std::ifstream inFile(fName);
  if (inFile.is_open())
  {
    std::string line;
    while (getline(inFile, line))
    {
        commandList.enqueue(line);
    }
    inFile.close();
  }
  else
  {
    throw(std::runtime_error("\nFile not found/opened.\n"));
  }
}

executive::~executive()
{
  while(commandList.isEmpty() != true) //This check is not needed, assuming the file is formatted correctly.
  {
    commandList.dequeue();
  }
}

bool executive::strStartsWith(std::string str, std::string start)
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

std::string executive::strEndsWith(std::string str, std::string start)
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

void executive::run()
{
  int commandCount = commandList.getLength();
  std::string command = "";
  for(int i=0;i<commandCount;++i)
  {
    try
    {
      command = commandList.peekFront();
      this->executeCommand(command);
      commandList.dequeue();
    }
    catch(std::runtime_error& rte)
    {
      std::cout << '\n' << rte.what() << "\nError, bad command list length or format?\n";
    }
  }
}

void executive::executeCommand(std::string command)
{
  if(strStartsWith(command, "ARRIVE") == true)
  {
    try
    {
      ++arrivalOrder;
      std::string patientInfo = strEndsWith(command, "ARRIVE");
      std::string firstName, lastName, illness;
      int age, severity;
      std::stringstream ss(patientInfo);
      ss >> firstName >> lastName >> age >> illness >> severity;
      patient newPatient(firstName, lastName, age, illness, severity, arrivalOrder);
      waitingRoom.add(newPatient);
    }
    catch(std::runtime_error& rte)
    {
      std::cout << rte.what();
    }
  }
  else if(strStartsWith(command, "NEXT") == 1)
  {
    try
    {
      printNext();
    }
    catch(std::runtime_error& rte)
    {
      std::cout << rte.what();
    }

  }
  else if(strStartsWith(command, "TREAT") == 1)
  {
    try
    {
      waitingRoom.remove();
    }
    catch(std::runtime_error& rte)
    {
      std::cout << rte.what();
    }
  }
  else if(strStartsWith(command, "COUNT") == 1)
  {
    int patientCount = waitingRoom.getNumberOfNodes();
    std::cout << "\nThere are " << patientCount << " patients waiting to be seen.\n";
  }
}

void executive::printNext()
{
  patient temp = waitingRoom.peekTop();
  std::cout << "\nNext patient:\n\tName: " << temp.getLast() << ", " << temp.getFirst() << ".\n";
  std::cout << "\tAge: " << temp.getAge();
  std::cout << "\n\tSuffers from: " << temp.getCondition();
  std::cout << "\n\tIllness Severity: " << temp.getSeverity() << '\n';
}
