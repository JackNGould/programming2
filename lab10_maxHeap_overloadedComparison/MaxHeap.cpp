/*
 * @project: Max Heap - Hospital patient simulation
 * @file: MaxHeap.cpp
 * @author: Jack Gould
 * @brief: Implementation File for templated MaxHeap class. Defines member methods. Objects that fill these maxHeaps must be comparable (likely with overloaded comparison operators, as in this lab). Class inherits from MaxHeapInterface.
 * @date: 04-14-2020
 */

#include <cmath>

template <typename ItemType>
void MaxHeap<ItemType>::swap(ItemType &x, ItemType &y)
{
  ItemType temp = x;
  x = y;
  y = temp;
}

template <typename ItemType>
MaxHeap<ItemType>::MaxHeap()
{
  m_array = nullptr;
  m_heapSize = 0;
  m_height = 0;
  m_arraySize = 0;
}

template <typename ItemType>
MaxHeap<ItemType>::~MaxHeap()
{
  clear();
}

template <typename ItemType>
bool MaxHeap<ItemType>::isEmpty() const
{
  if(m_heapSize == 0)
  {
    return true;
  }
  return false;
}

template <typename ItemType>
int MaxHeap<ItemType>::getNumberOfNodes() const
{
  return m_heapSize;
}

template <typename ItemType>
int MaxHeap<ItemType>::getHeight() const
{
  return m_height;
}

template <typename ItemType>
ItemType MaxHeap<ItemType>::peekTop() const
{
  if(m_heapSize == 0)
  {
    throw(std::runtime_error("\npeekTop called on an empty Heap!\n"));
  }

  else
  {
    return m_array[0];
  }
}

template <typename ItemType>
bool MaxHeap<ItemType>::needNewRow() const
{
  if(m_heapSize == m_arraySize)
  {
    return true;
  }
  return false;
}

template <typename ItemType>
void MaxHeap<ItemType>::increaseArraySize()
{
  if(m_array == nullptr)
  {
    m_array = new ItemType[1];
    ++m_height;
    m_arraySize = 1;
  }
  else
  {
    ItemType* arr;
    arr = new ItemType[2*m_arraySize+1];
    for(int i=0;i<m_arraySize;++i)
    {
      arr[i] = m_array[i];
    }
    delete [] m_array;
    m_array = arr;
    ++m_height;
    m_arraySize = (2*m_arraySize+1);
  }
}

template <typename ItemType>
void MaxHeap<ItemType>::decreaseArraySize()
{
  if(m_height > 1)
  {
    ItemType* arr;
    arr = new ItemType[(m_arraySize-1)/2];
    for(int i=0;i<((m_arraySize-1)/2);++i)
    {
      arr[i] = m_array[i];
    }
    delete [] m_array;
    m_array = arr;
    --m_height;
    m_arraySize = ((m_arraySize-1)/2);
  }
  else if(m_height == 1)
  {
    delete [] m_array;
    --m_height;
    m_arraySize = 0;

  }  
}

template <typename ItemType>
void MaxHeap<ItemType>::add(ItemType data)
{
  if(needNewRow() == true)
  {
    increaseArraySize();
    m_array[m_heapSize] = data;
    ++m_heapSize;
    if(m_heapSize > 1)
    {
      upHeap(m_heapSize-1);
    }
    return;
  }
  m_array[m_heapSize] = data;
  ++m_heapSize;
  if(m_heapSize > 1)
  {
    upHeap(m_heapSize-1);
  }
}


template <typename ItemType>
void MaxHeap<ItemType>::remove()
{
  if(m_heapSize == 0)
  {
    throw(std::runtime_error("\nremove attempted on an empty heap!\n"));
  }
  else
  {
    m_array[0] = m_array[m_heapSize-1];
    if(m_heapSize == pow(2, (m_height-1))) //checks if removing a value will leave a fully empty row
    {
      decreaseArraySize();
    }
    --m_heapSize;
    if(m_heapSize > 1)
    {
      downHeap(0);
    }
  }
}


template <typename ItemType>
void MaxHeap<ItemType>::clear()
{
  for(int i=0;i<m_heapSize;++i)
  {
    remove();
  }
}



template <typename ItemType>
int MaxHeap<ItemType>::getParentIndex(int index) const
{
  if(index <= 0)
  {
    throw(std::runtime_error("getParent was called on the root node, no parent node"));
  }
  else
  {
    return((index-1)/2);
  }
}



template <typename ItemType>
void MaxHeap<ItemType>::downHeap(int index)
{
  if((2*index+1) >= m_heapSize) // no children
  {
    return;
  }
  else if((2*index+2) >= m_heapSize) // one child
  {
    if(m_array[2*index+1] > m_array[index])
    {
      swap(m_array[index], m_array[2*index+1]);
    }
    return;
  }
  
  else
  {
    int maxIndex;
    if(m_array[2*index+1] > m_array[2*index+2])
    {
      maxIndex=2*index+1;
    }
    else
    {
      maxIndex=2*index+2;
    }
    if(m_array[maxIndex] > m_array[index])
    {
      swap(m_array[index], m_array[maxIndex]);
      downHeap(maxIndex);
    }
  }
}

template <typename ItemType>
void MaxHeap<ItemType>::upHeap(int index)
{
  if (index == 0)
  {
    return;
  }
  if(m_array[index] > m_array[getParentIndex(index)])
  {
    swap(m_array[index], m_array[getParentIndex(index)]);
    upHeap(getParentIndex(index));
  }
}

