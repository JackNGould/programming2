/*
 * @project: elevator - templated stacks and queues
 * @file: BuildingExecutive.h
 * @author: Jack Gould
 * @brief: Header File for BuildingExecutive class. Lists member methods. Class govers the programs 'executive' actions: defining elevator operations and parsing the input file for commands.
 * @date: 02-19-2020
 */
#ifndef BUILDING_EXECUTIVE_H
#define BUILDING_EXECUTIVE_H

#include <string>
#include "Queue.h"
#include "Stack.h"

class BuildingExecutive
{
  public:

   /* Constructor
    * @pre
    * @param std::string fname - name of the file to be opened for parsing
    * @post - A new BuildingExecutive is created, reading in from the file to create the command List
    * @throws - PreconditionViolationException if the file could not be opened or found
    */
    BuildingExecutive(std::string fname);

   /* 
    * @pre - the file was opened successfully, contents read into commmandList
    * @post - begins operation of passed in commands
    */
    void run();

   /* Destructor
    * @pre
    * @post - The BuildingExecutive object is deleted - all filled Lists are emptied
    */
    ~BuildingExecutive();
  private:

   /* Helper method for executeCommand(std::string command) method
    * @pre - called inside the executeCommand() method to pick command
    * @param std::string str - the full string - in this case, the full command
    * @param std::string start - a string to test the beginning of the full string for
    * @return bool - Returns true if the passed in string str begins with the other passed in string start. False otherwise
    * @throws PreconditionViolationException if command could not be completed
    */
    bool strStartsWith(std::string str, std::string start);

   /* Helper method for executeCommand(std::string command) method
    * @pre - called inside the executeCommand() method to pick command
    * @param std::string str - the full string - in this case, the full command
    * @param std::string start - the start of the string, to strip from the output. 
    * @return std::string - Returns the string without the start - effectively grabs the argument of those commands with parameters
    * @throws PreconditionViolationException if the size of starting string is not less than full string. Should be impossible in current implementation
    */
    std::string strEndsWith(std::string str, std::string start);

   /* 
    * @pre - called inside the run() function
    * @param std::string command - the command to be executed currently
    * @post - parses the passed in string command and executes its function. 
    * @throws PreconditionViolationException if command could not be completed
    */
    void executeCommand(std::string command, int commandNum);

    /*PRIVATE MEMBER VARIABLES
     * Three important lists for building function.
     */
    Queue<std::string> waitLine; //Queue contains the names of those in the elevator waitLine
    Queue<std::string> commandList; //Queue contains the list of commands passed in at runTime. Popped and executed one at a time.
    Stack<std::string> elevator; //Stack contains the people currently inside the elevator

    /*WAIT command helper variable
     * this int needs to be in scope of both run() and executeCommand() functions
     * It helps control output while the program is executing. 
     * When multiple wait commands are detected in a row from the input file, one line is printed with the amount of waits.
     * This is rather than printing output for each command, as with other commands.
     */
    int waitCount;
};
#endif
