/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: jackException.h
 * @author: Jack Gould
 * @brief: Header and Implementation file for jackException. Lists and defines a single function(constructor). Simply inherits from std::runtime_error
 * @date: 04-17-2020
 */
#ifndef JACK_EXCEPTION_H
#define JACK_EXCEPTION_H

#include <stdexcept>

class jackException : public std::runtime_error
{
  public:
    /**
    *@post Creates an exception with the message
    */
    jackException(const char* message) : std::runtime_error(message) { }
};
#endif

