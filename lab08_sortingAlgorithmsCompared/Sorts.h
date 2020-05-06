/*
 * @project Sorting Algorithms
 * @file: Sorts.h
 * @author: Jack Gould
 * @brief: Header file for templated Sorts class. Lists member methods. Class implements various iterative and recursive sorts. All methods static for use without object instantiation.
 * @date: 04-13-2020
 */
#ifndef SORTS_H
#define SORTS_H


template <typename T>
class Sorts
{
     public:
       /** 
       * @pre none
       * @post Simple iterative sort that will repeatedly swap two adjacent values if out of order. Needs multiple passes, but is designed to exit once a full pass is made without any swaps occuring
       * @param T arr[] : array to pass for in for merge Sorting
       * @param int size: size of array to be sorted
       **/
       static void bubbleSort(T arr[], int size);

       /** 
       * @pre none
       * @post iterative sort with a sorted and unsorted section that will repeatedly find the minimum value from unsorted section and move it to the sorted section until whole array is sorted
       * @param T arr[] : array to pass for in for merge Sorting
       * @param int size: size of array to be sorted
       **/
       static void selectionSort(T arr[], int size);

       /** 
       * @pre none
       * @post iterative sort with a sorted and unsorted section that will move one value at a time into the correct position in the sorted section
       * @param T arr[] : array to pass for in for merge Sorting
       * @param int size: size of array to be sorted
       **/
       static void insertionSort(T arr[], int size);

       /** 
       * @pre none
       * @post recursively calls mergeSort to split the array down to its lowest unit, and rebuild the array in correct order using the merge function
       * @param T arr[] : array to pass for in for merge Sorting
       * @param int size: size of array to be sorted
       **/
       static void mergeSort(T arr[], int size);

       /**
       * @pre none
       * @post calls quickSortRec with median flag set to false
       * @param T arr[] : array to pass for in for quickSorting with pivot value automatically assigned to the last value
       * @param int size: size of array to be sorted
       **/
       static void quickSort(T arr[], int size);

       /** 
       * @pre none
       * @post calls quickSortRec with median flag set to true
       * @param T arr[] : array to pass for in for quickSorting after pivot has been set to median of first, middle, and last array values. 
       * @param int size: size of array to be sorted
       **/
       static void quickSortWithMedian(T arr[], int size);

       /** 
       * @pre size >= 0
       * @post None: Simple function that recursively checks if the array is sorted. 
       * @param T arr[] : array to check if sorted
       * @param int size: size of array to be sorted
       * @return boolean value = true if the array passed in is fully sorted in ascending order. Accepts equal values as long as they are located next to each other.
       **/
       static bool isSorted(T arr[], int size);

     private:
       /** 
       * @pre array values passed in to be swapped.
       * @post The two values of type <T> will be swapped (Array values)
       * @param T* xp/yp: the two values to be swapped. Will be passed in by giving a specific array index
       **/
       static void mySwap(T *xp, T *yp);

       /** 
       * @pre array of type T exists. Two halved arrays were created by mergeSort and passed in.  
       * @post used by mergeSort to combine two sorted arrays back into a single sorted array 
       * @param T arr[]: An array of values passed in
       * @param T* a1/a2: two halves of a single array created and passed in by mergeSort
       * @param int size1/size2: size of each array half. Need both in case the length is odd and thus the halves are sized differently by one
       **/
       static void merge(T* a1, T* a2, int size1, int size2, T arr[]);

       /** 
       * @pre array of type T exists. 
       * @post recursively sorts the array by partitioning w/ pivot, quick sorting all values left of pivot, and quick sorting all values right of pivot
       * @param T arr[]: An array of values passed in
       * @param int first: an integer index of the first value in the array to be considered
       * @param int last: an integer index of the last value in the array to be considered
       * @param bool median: Passes median to int partition to inform that method how to choose a pivot value
       **/
       static void quickSortRec(T arr[], int first, int last, bool median);
       
       /** 
       * @pre array of type T exists. Will only be called by quickSortRec if quickSortRec was called by quickSortWithMedian
       * @post The median of the first, middle, and last value is moved to the last position in the array.
       * @param T arr[]: An array of values passed in
       * @param int first: an integer index of the first value in the array to be considered
       * @param int last: an integer index of the last value in the array to be considered
       **/
       static void setMedianPivot(T arr[], int first, int last);

       /** 
       * @pre array of type T exists
       * @post The last value in the array is the pivot value, and is moved to its correct position. Everything below it is less than pivot and above it is greater than pivot
       * @param T arr[]: An array of values passed in
       * @param int first: an integer index of the first value in the array to be considered
       * @param int last: an integer index of the last value in the array to be considered
       * @param bool median: a boolean value. If true, will call setMedianPivot before setting the pivot value. If false, sets pivot value to last value immediately.
       * @return int: returns an integer that represents the array index that the pivot value has been moved to. The pivot value will then be in its correct position. 
       **/
       static int partition(T arr[], int first, int last, bool median);

};
#include "Sorts.cpp"
#endif
