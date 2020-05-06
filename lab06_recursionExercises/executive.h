/*
 * @assignment EECS 268 Lab05 
 * @file: Executive.h
 * @author: Jack Gould
 * @brief: Header File for Executive class. Lists member methods. Class governs the programs 'executive' actions of parsing the input file for instructions, running those instructions, and displaying the results.
 * @date: 04-01-2020
 */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <cstring>

class executive
{

	public:
       /** CONSTRUCTOR
    * @pre - none
    * @post Executive object is created, member variables initialized.
    * @param std::string fileName: fileName to be opened and parsed for commands
    * @throws std::runtime_error if file cannot be opened
    */
		executive(int argc, char** argv);

       /** DESTRUCTOR
    * @pre - none
    * @post Executive object is destroyed, lists cleared
    */
    ~executive();



	private:


       /** private helper function
    * @pre - called inside executeCommand function...to assist in executing commands
    *   - used to check the end of the executable name that launched program to determine mode.
    * @param char* str: need to check if this string is identical to or ends with the other parameter 'end'
    * @param char* end: string that needs to be verified as the ending string of 'str'
    * @return bool is true if string 'str' ends with the string 'end' False otherwise
    */
    bool cStrEndsWith(char* str, char* end);


};
#endif



