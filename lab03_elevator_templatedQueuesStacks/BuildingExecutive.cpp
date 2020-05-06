/*
 * @project: elevator - templated stacks and queues
 * @file: BuildingExecutive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for BuildingExecutive class. Defines member methods. Class govers the programs 'executive' actions: defining elevator operations and parsing the input file for commands.
 * @date: 02-19-2020
 */
#include "BuildingExecutive.h"
#include "PreconditionViolationException.h"
#include <iostream>
#include <fstream>
#include <cstring> //to use a string comparison method that I like

BuildingExecutive::BuildingExecutive(std::string fName)
{
  waitCount = 0; //initialize helper variable that needs to be in scope of both run() and executeCommand() functions
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
    throw(PreconditionViolationException("\nFile not found/opened.\n"));
  }
}

BuildingExecutive::~BuildingExecutive()
{
  while(waitLine.isEmpty() != true)
  {
    waitLine.dequeue();
  }
  while(elevator.isEmpty() != true)
  {
    elevator.pop();
  }
  while(commandList.isEmpty() != true) //This check is not needed, assuming the file is formatted correctly.
  {
    commandList.dequeue();
  }
}

bool BuildingExecutive::strStartsWith(std::string str, std::string start)
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

std::string BuildingExecutive::strEndsWith(std::string str, std::string start)
{
  if (start.size() < str.size())
  {
    std::string end = str.substr(start.size(), str.size());
    return end;
  }
  else
  {
    throw(PreconditionViolationException("bad call. size of starting string must be less than whole command."));
  }
}

void BuildingExecutive::run()
{
  int commandCount = commandList.getLength();
  std::string command = "";
  for(int i=0;i<commandCount;++i)
  {
    try
    {
      command = commandList.peekFront();
      this->executeCommand(command, i+1);
      commandList.dequeue();
    }
    catch(PreconditionViolationException& rte)
    {
      std::cout << '\n' << rte.what() << "\nError, bad command list length or format?\n";
    }
  }
}

void BuildingExecutive::executeCommand(std::string command, int commandNum)
{
  if(strStartsWith(command, "WAIT") == true)
  {
    try
    {
      std::string name = strEndsWith(command, "WAIT");
      waitLine.enqueue(name);
    }
    catch(PreconditionViolationException& rte)
    {
      std::cout << "\nCOMMAND #" << commandNum << " - Error on waitline enqueue. Maybe you made it too big?\n";
      std::cout << rte.what() << "\n\nIgnoring command #" << commandNum << " - \"" << command << "\"\n";
    }
    ++waitCount;
    return; 
  }
  /*WAITstreak printer
   * WAIT is intentionally the first command detected.
   * If a series of wait commands are inputted, all outputs will be 
   */
  if(waitCount > 0)
  {
    if(waitCount == 1)
    {
      std::string tName = waitLine.peekBack();
      std::cout << "\nCOMMAND #" << commandNum-1 << " - " << tName << " was added to the waitLine.\n";
    }
    else
    {
      std::cout << "\nCOMMAND #" << commandNum-1 << " - " << waitCount << " people were added to the elevator's waitline.\n";
      std::cout << "This was performed by commands " << ((commandNum-1)-(waitCount-1)) << " through " << commandNum-1 << '\n';
    }
    waitCount = 0;
  }
  if(strStartsWith(command, "PICK_UP") == 1)
  {
    int pickedUp = 0;
    try
    {
      std::string::size_type sz;
      std::string pickUpCount = strEndsWith(command, "PICK_UP");
      int pickUp = std::stoi (pickUpCount,&sz);
      for(int i=0;i<pickUp;++i)
      {
        if(waitLine.isEmpty() == 0)
        {
          std::string temp = waitLine.peekFront();
          elevator.push(temp);
          waitLine.dequeue();
          ++pickedUp;
        }
        else
        {
          throw(PreconditionViolationException("Nobody left in the wait line!"));
        }
      }
      std::cout << "\nCOMMAND #" << commandNum << " - Picked up " << pickedUp << " passengers.\n";
    }
    catch(PreconditionViolationException& rte)
    {
      if(strcmp(rte.what(), "A push was attempted on a full stack. Elevator is full") == 0)
      {
        std::cout << "\n\t" << rte.what();
        std::cout << "\n\tInstruction error for command #" << commandNum << " - \"" << command << "\"";
        if(pickedUp == 0)
        {
          std::cout << "\nCOMMAND #" << commandNum << " - Pick up requested on a full elevator, nothing to do\n";
        }
        else
        {
          std::cout << "\nCOMMAND #" << commandNum << " - Requested pick up count too high, " << pickedUp << " people got on before the elevator reached capacity\n";
        }
      }
      else if(strcmp(rte.what(), "Nobody left in the wait line!") == 0)
      {
        std::cout << "\n\t" << rte.what();
        std::cout << "\n\tInstruction error for command #" << commandNum << " - \"" << command << "\"";
        if(pickedUp == 0)
        {
          std::cout << "\nCOMMAND #" << commandNum << " - Pick up requested with an empty waitline, nothing to do.\n";
        }
        else
        {
          std::cout << "\nCOMMAND #" << commandNum << " - All " << pickedUp << " people waiting in line were picked up by the elevator.\n";
        }
      }
      else
      {
        std::cout << "\n\t" << rte.what() << "\n\tIgnoring invalid command #" << commandNum << " - \"" << command << "\"";
        std::cout << "\nCOMMAND #" << commandNum << " - Requested string could not be converted to an integer.\n";
      }
    }
    return;
  }
  else if(strStartsWith(command, "DROP_OFF") == 1)
  {
    int droppedOff = 0;
    try
    {
      std::string dropOffCount = strEndsWith(command, "DROP_OFF");
      int count = stoi(dropOffCount); // cast std::string to an integer using stoi 
      for(int i=0;i<count;++i)
      {
        elevator.pop();
        ++droppedOff;
      }
      std::cout << "\nCOMMAND #" << commandNum << " - Dropped off " << droppedOff << " passengers.\n";
    }
    catch(PreconditionViolationException& rte)
    {
      if(strcmp(rte.what(), "A pop was attempted on an empty stack. Nobody on the elevator.") == 0)
      {
        std::cout << "\n\t" << rte.what();
        std::cout << "\n\tInstruction error for command #" << commandNum << " - \"" << command << "\"";
        if(droppedOff == 0)
        {
          std::cout << "\nCOMMAND #" << commandNum << " - Drop off requested with an empty elevator, nothing to do.\n";
        }
        else
        {
          std::cout << "\nCOMMAND #" << commandNum << " - Requested drop off count excessively high, all " << droppedOff << " passengers dropped off already.\n";
        }
      }
      else
      {
        std::cout << "\n\t" << rte.what() << "\n\tIgnoring invalid command #" << commandNum << " - \"" << command << "\"";
        std::cout << "\nCOMMAND #" << commandNum << " - Requested string could not be converted to an integer.\n";
      }
    }
    return;
  }
  else if(strStartsWith(command, "INSPECTION") == 1)
  {
    try
    {
      std::cout << "\nCOMMAND #" << commandNum << " - INSPECTION";
      std::cout << "\nElevator Status:\n";
      if(elevator.isEmpty() == 1)
      {
        std::cout << "\tThe Elevator is empty.\n";
      }
      else 
      {
        std::cout << "\tThe Elevator is not empty.\n";
        std::string nextOFF = elevator.peek();
        std::cout << '\t' <<  nextOFF << " will be the next person to leave the elevator.\n";
      }
      if(waitLine.isEmpty() == 1)
      {
        std::cout <<"\tThe Wait Line is empty.\n";
      }
      else
      {
        std::string nextON = waitLine.peekFront();
        std::cout << '\t' << nextON << " will be the next person to get on the elevator.\n";
      }
    }
    catch(PreconditionViolationException& rte)
    {
      std::cout << '\n' << rte.what() << '\n';
    }
    return;
  }
  std::cout << "\nERROR - No matching command found for command #" << commandNum << " - \"" << command << "\"";
  std::cout << "\nCOMMAND #" << commandNum << " - Not a valid command. Consult the README.md\n";
}


