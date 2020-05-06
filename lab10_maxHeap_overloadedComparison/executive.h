/*
 * @project: Max Heap - Hospital patient simulation
 * @file: executive.h
 * @author: Jack Gould
 * @brief: Header File for Executive class. Lists member methods. Class governs the programs 'executive' actions of parsing the input file for hospital commands and attempting to run them using the max heap
 * @date: 04-14-2020
 */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Queue.h"
#include "patient.h"
#include "MaxHeap.h"

class executive
{
  public:

   /* Constructor
    * @pre
    * @param std::string fname - name of the file to be opened for parsing
    * @post - A new executive is created, reading in from the file to create the command List
    * @throws - std::runtime_error if the file could not be opened or found
    */
    executive(std::string fname);

   /* 
    * @pre - the file was opened successfully, contents read into commmandList
    * @post - begins operation of passed in commands
    */
    void run();

   /* Destructor
    * @pre
    * @post - The executive object is deleted
    */
    ~executive();

  private:

    Queue<std::string> commandList; //Queue contains the list of commands passed in at runTime
    int arrivalOrder; //a tracker that is used to mark the arrivalOrder of each patient. Used as a tiebreaker in patient comparisons if two patients have the same severity and age
    MaxHeap<patient> waitingRoom; //The MaxHeap that patients are pulled from

   /* Helper method for executeCommand(std::string command) method
    * @pre - called inside the executeCommand() method to pick command
    * @param std::string str - the full string - in this case, the full command
    * @param std::string start - a string to test the beginning of the full string for
    * @return bool - Returns true if the passed in string str begins with the other passed in string start. False otherwise
    * @throws std::runtime_error if command could not be completed
    */
    bool strStartsWith(std::string str, std::string start);

   /* Helper method for executeCommand(std::string command) method
    * @pre - called inside the executeCommand() method to pick command
    * @param std::string str - the full string - in this case, the full command
    * @param std::string start - the start of the string, to strip from the output. 
    * @return std::string - Returns the string without the start - effectively grabs the argument of those commands with parameters
    * @throws std::runtime_error if the size of starting string is not less than full string. Should be impossible in current implementation
    */
    std::string strEndsWith(std::string str, std::string start);

   /* 
    * @pre - called inside the run() function
    * @param std::string command - the command to be executed currently
    * @post - parses the passed in string command and executes its function. 
    * @throws std::runtime_error if command could not be completed
    */
    void executeCommand(std::string command);

   /* 
    * @pre - called inside the run() function
    * @post - peeks at the top of the MaxHeap and prints all of that Patients info to the screen as the next to see the doctor
    */
    void printNext();

};
#endif
