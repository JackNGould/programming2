/*
 * @assignment: EECS 268 Lab 06
 * @file: fibonacci.cpp
 * @author: Jack Gould
 * @brief: Header fill for the fibonacci class. Contains only two functions, one for each possible mode. runI will return the fibonacci number at the provided index, while runV will check the fibonacci sequence for the provided value.
 * @date: 04-10-2020
 */
#ifndef FIBONACCI_H
#define FIBONACCI_H

class fibonacci
{
  public:
    
    /** 
     * @pre: n >= 0 
     * @post nth fibonacci number will be found recursively and returned to calling function. 
     * @param n: integer representing which fibonacci number to find. First fibonacci number is 0 with index of 0.  
     * @return: integer returned is the nth fibonacci number, to be printed once control flow has returned to calling function. 
     **/
    int runI(int n);
    
    /** 
     * @pre: int n >= 0
     * @post: Determines whether the provided integer is in the fibonacci sequence, and prints the results to standard output. Generates fibonacci 
     * @param: int n: An integer to search the fibonacci sequence for
     **/
    void runV(int n);
};

#endif
