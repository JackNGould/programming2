/*
 * @project: shapes - inheritance and exception handling
 * @file: executive.h
 * @author: Jack Gould
 * @brief: Header File for Executive class. Lists member methods. Class governs the programs 'executive' actions of parsing the input file for commands, attempting to run them, and displaying the results.
 * @date: 02-26-2020
 */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Queue.h"
#include "ShapeContainer.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <sstream>

class Executive
{
  public:

   /* Constructor
    * @pre
    * @param std::string fname - name of the file to be opened for parsing
    * @post - A new Executive is created, reading in from the file to create the command List
    * @throws - PreconditionViolationException if the file could not be opened or found
    */
    Executive(std::string fname);

   /*
    * @pre - the file was opened successfully, contents read into commmandList
    * @post - begins operation of passed in commands
    */
    void run();

   /* Destructor
    * @pre
    * @post - The Executive object is deleted - all filled Lists are emptied
    */
    ~Executive();
  private:

    /* Helper method for run() method
     * @pre - called inside the run() method ONLY for the first line of the input file
     * @param std::string str - full string to attempt to get an integer out of
     * @return int - returns the first integer that is detected in the string str. Returns (-1) if none found
     */
    int getFirstInt(std::string str);

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
    * @param int lineNum - the line number of the input file that caused problems
    * @post - parses the passed in string command and executes its function.
    * @throws PreconditionViolationException if command could not be completed
    */
    void executeCommand(std::string command, int lineNum);

   /*
    * @pre - called by the executeCommand() function
    * @param std::stringstream& ss - stringstream that is the remainder of the command line after the "ADD" part
    *   Contains the info of the shape to be added
    * @post - shape specified in the stringstream is added to the container
    * @throws PreconditionViolationException if command could not be completed explaining why
    */
    void addShape(std::stringstream& ss);
    
    /*PRIVATE HELPER VARIABLES
     * These variables need to exist in the scope of multiple member functions.
     * m_fName - Stored after use in constructor for later reference to filename when displaying output.
     * commandsFound/commentCounter/cError/exit - Need to exist in scope of both run() and executeCommand(). Values are each updateable once per command
     * containerSize/boxOfShapes/commandList - other stuff that needs to exist for each Executive object
     */
    std::string m_fName; //string stores the name of the input file.
    int commandsFound; //int counts the number of lines successfully interpreted as a command
    int commentCounter; //integer counts lines of the input file that are simply ignored as comment lines
    int cError; //integer counts the commands that are successfully parsed, and returned with errors
    bool exit = false;
    int containerSize = 0; //integer storing size of the shape container. First item in passed in file
    ShapeContainer* boxOfShapes;
    Queue<std::string> commandList; //Queue contains the list of commands passed in at runTime

};
#endif
