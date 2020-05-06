/*
 * @project: elevator - templated stacks and queues
 * @file: PreconditionViolationException.h
 * @author: Jack Gould
 * @brief: Header and implementation file for PreconditionViolationException class. Constructor is this class' only function, so the definition is included in this file. This class simply injerits from std::runtime_error
 * @date: 02-19-2020
 */
#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H

#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
  public:
    /**
    *@post Creates an exception with the message
    */
    PreconditionViolationException(const char* message) : std::runtime_error(message) { }
};
#endif

