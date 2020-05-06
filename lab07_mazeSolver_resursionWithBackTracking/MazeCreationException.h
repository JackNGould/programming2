/*
 * @assignment EECS 268 Lab07 
 * @file: MazeCreationException.h
 * @author: Jack Gould
 * @brief: Header+Implementation file for MazeCreationException class. Inherits from std::runtime_error
 * @date: 04-08-2020
 */
#ifndef MAZE_CREATION_EXCEPTION_H
#define MAZE_CREATION_EXCEPTION_H

#include <stdexcept>

class MazeCreationException : public std::runtime_error
{
  public:
    /**
    *@post Creates an exception with the message
    */
    MazeCreationException(const char* message) : std::runtime_error(message) { }
};
#endif


