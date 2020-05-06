/*
 * @project Sorting Algorithms
 * @file: SortTimer.cpp
 * @author: Jack Gould
 * @brief: Implementation file for the SortTimer class. Defines a single static member method. Class can run sorts under a timer. #includes <time.h> for timing, <functional> for the ability to run functions with other functions as parameters, and "Sorts.h" for access to sorting functions. Data being sorted is templated.
 * @date: 04-13-2020
 */
#include <time.h> //for timing a sort
#include "Sorts.h" //to access static sorting functions

template <typename T>
double SortTimer<T>::timeASort(std::function<void(T[],int)> sort, T arr[], int size)
{
  clock_t start;
  double duration;
  start = clock(); //start timer

  sort(arr, size); //call the sort passed in as a function

  duration = (clock()-start) / (double) CLOCKS_PER_SEC; // stop timer

  return duration; //return the time it took to sort
}

