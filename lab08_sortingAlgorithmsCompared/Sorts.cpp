/*
 * @project Sorting Algorithms
 * @file: Sorts.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Sorts class. Defines member methods. Class implements various iterative and recursive sorts. All methods static for use without object instantiation.
 * @date: 04-13-2020
 */

template <typename T>
void Sorts<T>::mySwap(T *xp, T *yp)
{
  T temp = *xp;
  *xp = *yp;
  *yp = temp;
}

template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{
  bool swapped;
  for(int i=0;i<size-1;++i)
  {
    swapped = false;
    for(int j=0;j<size-1-i;++j)
    {
      if(arr[j] > arr[j+1])
      {
        mySwap(&arr[j], &arr[j+1]);
        swapped = true;
      }
    }
    if (swapped == false)
    {
      break;
    }
  }
}


template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
  int i, j, minIndex;
  for(i=0;i<size-1;++i)
  {
    minIndex = i;
    for(j=i+1;j<size;++j)
    {
      if(arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    mySwap(&arr[minIndex], &arr[i]);
  }
}


template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
  int m = (first + ((last-first)/2));
  T x = arr[first] - arr[m];
  T y = arr[m] - arr[last];
  T z = arr[first] - arr[last];

  if(x*y>0)
  {
    mySwap(&arr[m], &arr[last]);
  }
  else if(x*z>0)
  {
  }
  else
  {
    mySwap(&arr[first], &arr[last]);
  }
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
  int i, j;
  T key;
  for(i=1;i<size;++i)
  {
    key = arr[i];
    j = i-1;
    while(j>=0 && arr[j]>key)
    {
      arr[j+1] = arr[j];
      --j;
    }
    arr[j+1] = key; //j was incremented down at the end of the while loop
  }
}


/*
 * I tried for many hours to get this function to work using the exact same parameters as sample function. Couldn't do it.
 * Tried using pointer arithmetic to pass in the pointers as the original array but shifted to the correct start value, but had lots of problems.
 * If I made them copies of the original, then I couldn't modify the original array without also passing it in as a parameter.
 * I figure it would be better to simply pass in the full original array here, along with a start and end index, then find the median and split it in two inside this function.
 * But I ended up just adding the original array as a parameter and still splitting in the mergeSort function. 
 */
template <typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2, T arr[])
{
  int i = 0;
  int j = 0;
  int k = 0;
  while (i<size1 && j<size2)
  {
    if(a1[i] <= a2[j])
    {
      arr[k] = a1[i];
      ++i;
      ++k;
    }
    else
    {
      arr[k] = a2[j];
      ++j;
      ++k;
    }
  }
  while(i<size1)
  {
    arr[k] = a1[i];
    ++i;
    ++k;
  }
  while(j<size2)
  {
    arr[k] = a2[j];
    ++j;
    ++k;
  }
}

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
  if(size > 1)
  {
    int m = size/2;
    int a1[m];
    int a2[size-m];
    for(int i=0;i<m;++i)
    {
      a1[i] = arr[i];
    }
    for(int j=0;j<(size-m);++j)
    {
      a2[j] = arr[m+j];
    }
    mergeSort(a1, m);
    mergeSort(a2, (size-m));

    merge(a1, a2, m, (size-m), arr);
  }
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
  quickSortRec(arr, 0, size-1, false);
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
  quickSortRec(arr, 0, size-1, true);
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
  if(first < last)
  {
    int pIndex = partition(arr, first, last, median); //pIndex = partition Index. Function returns index of pivot value after it has been placed in the correct position

    quickSortRec(arr, first, pIndex-1, median);
    quickSortRec(arr,pIndex+1, last, median);
  }
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
  if(size==1 || size<=0)
  {
    return true;
  }
  if(arr[size-2] > arr[size-1])
  {
    return false;
  }
  return isSorted(arr, size-1);
}

template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{
  if(median == true)
  {
    setMedianPivot(arr, first, last);
  }
  int pivot = arr[last];
  int i = (first-1); //starts at (-1) here on purpose
  for(int j = first; j<= last-1;++j)
  {
    if(arr[j] <= pivot)
    {
      ++i; //adds to counter for elements smaller than pivot
      mySwap(&arr[i], &arr[j]);
    }
  }
  mySwap(&arr[i+1], &arr[last]); //puts pivot value in the correct position
  return(i+1); //returns index of pivot 
}
