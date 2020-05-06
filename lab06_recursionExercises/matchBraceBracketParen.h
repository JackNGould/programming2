/*
 * @assignment: EECS 268 Lab 06
 * @file: matchParenthesis.h
 * @author: Jack Gould
 * @brief: Header file for matchParenthesis class. It recursively evaluates character arrays for matching sets of parenthesis, brackets, and braces
 * @date: 04-10-2020
 */
#ifndef MATCH_BRACE_BRACKET_PARENTHESIS_H
#define MATCH_BRACE_BRACKET_PARENTHESIS_H

class matchBraceBracketParen
{
  public:
    /** 
     * @pre length >= 0 
     * @post no operations performed on array, boolean returned after recursive evaluation for matches
     * @param str: a char array containing parenthesis which will be evaluated to determine if it is balanced
     * @param length: an integer value representing the number of characters in the array described above
     * @return boolean value indicating whether or not the provided parenthesis sequence is balanced
     **/
    bool check(char* str, int length);
  private:
    /** 
     * @pre program design makes it impossible to pass in anything other than a valid opening char 
     * @param c: Must be valid opening character. Possible values are (, [, or { 
     * @return : returns the correct matching closing character for the opening character passed in. 
     **/
    char getCloseChar(char c);
};

#endif
