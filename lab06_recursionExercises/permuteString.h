/*
 * @assignment: EECS_268 Lab5.2
 * @author: permuteString.h
 * @author: Jack Gould
 * @brief: Header file for the permuteString class, which will print all possible permutations of a passed in string.
 *    Assumes string contains all unique characters. If this is not the case, duplicates will occur.
 * @date: 04-10-2020
 */
#ifndef PERMUTE_STRING_H
#define PERMUTE_STRING_H

#include <string>

class permuteString
{
  public:
    /** 
     * @pre focus >= 0  
     * @post All permutations will be printed to standard output. Assumes the string will contain all unique characters. If this is not the case, duplicate(s) will appear.
     * @param str: a string that will be permuted in all possible ways by the function
     * @param focus: an integer value that is used to determine what values need to be swapped. Begins as 0 and will advance to the length of the string as each branch of the permutation tree is explored recursively.
     * @param end: an integer that functions as the index of the last value in the string. It is equal to one less than the length of the string due to indexing that begins at 0
     **/
    void printPermutations(std::string str, int focus, int end);
  private:
    /** 
     * @pre : none   
     * @post :The two chars passed in by reference will have their values swapped. 
     * @param &x: one of two characters to be swapped
     * @param &y: second of two characters to be swapped
     **/
    void swap(char &x, char &y);
    /** 
     * @pre : an integer that is incremented from 0 as each new permutation is generated, such that the printed list of permutations will be numbered   
     **/
    int permutationCounter = 0;
};

#endif
