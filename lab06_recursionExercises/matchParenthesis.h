/*
 * @assignment: EECS_268 Lab05 Exercise1
 * @file: matchParenthesis.h
 * @author: Jack Gould
 * @brief: Header file for matchParenthesis class. It recursively evaluates character arrays for matching sets of parenthesis 
 * @date: 04-10-2020
 */
#ifndef MATCH_PARENTHESIS_H
#define MATCH_PARENTHESIS_H

class matchParenthesis
{
  public:
    /** 
     * @pre length >= 0 
     * @post no operations performed on array, boolean returned
     * @param str: a char array containing parenthesis which will be evaluated to determine if it is balanced
     * @param length: an integer value representing the number of characters in the array described above
     * @return boolean value indicating whether or not the provided parenthesis sequence is balanced
     **/
    bool check(char* str, int length);
};

#endif
