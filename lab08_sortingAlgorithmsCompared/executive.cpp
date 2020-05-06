/*
 * @project: Sorting Algorithms
 * @file: executive.cpp
 * @author: Jack Gould
 * @brief: Implementation File for Executive class. Defines member methods. Class governs the programs 'executive' actions of timing the selected sort and writing the results to the designated output file.
 * @date: 04-14-2020
 */

#include "executive.h"

executive::executive(std::string sortType, int lBound, int uBound, int step, std::string outputFile, bool runAssert)
{
  m_outputFile = outputFile;
  m_sortType = sortType;
  m_lBound = lBound;
  m_uBound = uBound;
  m_step = step;
  m_runAssert = runAssert;
}

executive::~executive()
{

}

void executive::runSorts()
{
  std::ofstream outFile;
  outFile.open(m_outputFile);
  if(outFile.is_open())
  {
    outFile << m_sortType << "Sort" << std::endl;
    for(int i=m_lBound;i<=m_uBound;i=i+m_step)
    {
      srand(time(NULL));
      int arr[i];
      for(int j=0;j<i;++j)
      {
        arr[j] = rand();
      }
      double time = 0.0;
      if(m_sortType.compare("bubble") == 0)
      {
        time = SortTimer<int>::timeASort(Sorts<int>::bubbleSort, arr, i);
        outFile << i << "," << time << std::endl;
        if(m_runAssert==true)
        {
          assert(Sorts<int>::isSorted(arr, i) == true);
        }
      }
      else if(m_sortType.compare("selection") == 0)
      {
        time = SortTimer<int>::timeASort(Sorts<int>::selectionSort, arr, i);
        outFile << i << "," << time << std::endl;
        if(m_runAssert==true)
        {
          assert(Sorts<int>::isSorted(arr, i) == true);
        }
      }
      else if(m_sortType.compare("insertion") == 0)
      {
        time = SortTimer<int>::timeASort(Sorts<int>::insertionSort, arr, i);
        outFile << i << "," << time << std::endl;
        if(m_runAssert==true)
        {
          assert(Sorts<int>::isSorted(arr, i) == true);
        }
      }
      else if(m_sortType.compare("merge") == 0)
      {
        time = SortTimer<int>::timeASort(Sorts<int>::mergeSort, arr, i);
        outFile << i << "," << time << std::endl;
        if(m_runAssert==true)
        {
          assert(Sorts<int>::isSorted(arr, i) == true);
        }
      }
      else if(m_sortType.compare("quick") == 0)
      {
        time = SortTimer<int>::timeASort(Sorts<int>::quickSort, arr, i);
        outFile << i << "," << time << std::endl;
        if(m_runAssert==true)
        {
          assert(Sorts<int>::isSorted(arr, i) == true);
        }
      }
      else if(m_sortType.compare("quickWithMedian") == 0)
      {
        time = SortTimer<int>::timeASort(Sorts<int>::quickSortWithMedian, arr, i);
        outFile << i << "," << time << std::endl;
        if(m_runAssert==true)
        {
          assert(Sorts<int>::isSorted(arr, i) == true);
        }
      }
    }
  }
  else
  {
    std::cout << "File could not be opened, please make sure designated output file exists.\n";
  }
}

