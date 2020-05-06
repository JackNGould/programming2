/*
 * @project: Sorting Algorithms
 * @file: executive.h
 * @author: Jack Gould
 * @brief: Header File for Executive class. Lists member methods. Class governs the programs 'executive' actions of timing the selected sort and writing the results to the designated output file.
 * @date: 04-13-2020
 */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include "Sorts.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "SortTimer.h"
#include <functional>
#include <cassert>

class executive
{
  public:
       /** CONSTRUCTOR
    * @pre - none
    * @post Executive object is created, member variables initialized.
    * @param std::string sortType: sort type to be run
    * @param int lBound: lower bound for sizes of arrays to be sorted
    * @param int uBound: upper bound for sizes of arrays to be sorted
    * @param int step: the size delta between each sorted array within bounds
    * @param std::string outputFile: name of file to write results to
    * @param bool runAssert: boolean representing whether or not to run in assert mode
    * @throws std::runtime_error if file cannot be opened
    */
    executive(std::string sortType, int lBound, int uBound, int step, std::string outputFile, bool runAssert);
    
       /** DESTRUCTOR
    * @pre - none
    * @post Executive object is destroyed.
    */
    ~executive();

    /*
     * @pre - executive object successfully created.
     * @post - runs the sort designated by initialized member variables
     */
    void runSorts();

 private:

    //PRIVATE MEMBER VARIABLES BELOW
    std::string m_sortType, m_outputFile;
    int m_lBound, m_uBound, m_step;
    bool m_runAssert;
};
#endif
