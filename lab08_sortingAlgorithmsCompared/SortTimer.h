/*
 * @project Sorting Algorithms
 * @file: SortTimer.h
 * @author: Jack Gould
 * @brief: Header file for the SortTimer class. Defines a single static member method. Class can run sorts under a timer. #includes <time.h> for timing, <functional> for the ability to run functions with other functions as parameters, and "Sorts.h" for access to sorting functions. Data being sorted is templated.
 * @date: 04-13-2020
 */
#ifndef SORT_TIMER_H
#define SORT_TIMER_H

#include <functional> //so that "Sorts.h" sorting functions can be used as a parameter of the timeASort function

template <typename T>
class SortTimer
{
  public:
       /** 
       * @pre static function so that no object need be instantiated in order to call this method.
       * @post A timer is started, a sort immediately called, then the timer stopped. 
       * @param std::function: passes in one of the public sort methods(bubble,selection,insertion,merge,quick,quickWithMedian) along with their parameters(T arr[], int size).
       * @return double: a double that represents the time in seconds that the specific sort took to sort the array. 
       **/
     static double timeASort(std::function<void(T[], int)> sort, T arr[], int size);
};
#include "SortTimer.cpp"
#endif
