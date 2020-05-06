/*
 * @assignment EECS 268 Lab05 
 * @file: LinkedList.cpp
 * @author: Jack Gould
 * @brief: Implementation file for LinkedList class. Defines member methods. Templated, singly-linked, Node based implementation. Inherits from ListInterface.
 * @date: 04-01-2020
 */
template<typename T>
LinkedList<T>::LinkedList()
{
  m_length = 0;
  m_front = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  this->clear();
}

template<typename T>
void LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
  this->clear();
  Node<T>* traverseNew = nullptr;
  Node<T>* traverseRHS = rhs.m_front;
  while(traverseRHS != nullptr)
  {
    Node<T>* temp = new Node<T>(traverseRHS->getEntry());
    if(m_front == nullptr)
    {
      m_front = temp;
      traverseNew = temp;
    }
    else
    {
      traverseNew->setNext(temp);
      traverseNew = temp;
    }
    traverseRHS = traverseRHS->getNext();
  }
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& original)
{
  Node<T>* traverseNew = nullptr;
  Node<T>* traverseOrig = original.m_front;
  while(traverseOrig != nullptr)
  {
    Node<T>* temp = new Node<T>(traverseOrig->getEntry());
    if(m_front == nullptr)
    {
      m_front = temp;
      traverseNew = temp;
    }
    else
    {
      traverseNew->setNext(temp);
      traverseNew = temp;
    }
    traverseOrig = traverseOrig->getNext();
  }
}

template <typename T>
void LinkedList<T>::insert(int index, T entry)
{
  if(index <= (m_length+1) && index>0)
  {
    if(index == 1)
    {
      push(entry);
    }
    else if(index == (m_length+1))
    {
      append(entry);
    }
    else
    {
      Node<T>* previousNode = traverseList(index-1);
      insertAfter(previousNode, entry);
    }
  }
  else
  {
    throw(std::runtime_error("Attempted insert to List. Index invalid."));
  }
}

template<typename T>
void LinkedList<T>::remove(int index)
{
  if(index <= m_length && index > 0)
  {
    if(index == 1)
    {
      Node<T>* temp = m_front;
      m_front = m_front->getNext();
      delete temp;
      --m_length;
    }
    else if(index <= m_length)
    {
      Node<T>* keepThisOne = traverseList(index-1);
      Node<T>* deleteThisOne = traverseList(index);
      keepThisOne->setNext(deleteThisOne->getNext());
      delete (deleteThisOne);
      --m_length;
    }
  }
  else
  {
    throw(std::runtime_error("Attempted remove from list. Invalid index."));
  }
}

template<typename T>
T LinkedList<T>::getEntry(int index)
{
  if(index <= m_length && index > 0)
  {
    Node<T>* temp = traverseList(index);
    T tempEntry = temp->getEntry();
    return tempEntry;
  }
  else
  {
    throw(std::runtime_error("getEntry called with bad index or called on empty list"));
  }
}

template<typename T>
int LinkedList<T>::getLength()
{
  return m_length;
}

template<typename T>
void LinkedList<T>::clear()
{
  while(m_front != nullptr)
  {
    Node<T>* temp = m_front;
    m_front = m_front->getNext();
    delete temp;
  }
  m_length = 0;
}

template<typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
  if(index <= m_length && index > 0)
  {
    Node<T>* temp = traverseList(index);
    temp->setEntry(entry);
  }
  else
  {
    throw(std::runtime_error("Attempted setEntry on an out of range node"));
  }
}

template <typename T>
void LinkedList<T>::insertAfter(Node<T>* prevNode, T newEntry)
{
  Node<T>* newNode = new Node<T>(newEntry);
  newNode->setNext(prevNode->getNext());
  prevNode->setNext(newNode);
  ++m_length;
}

template <typename T>
Node<T>* LinkedList<T>::traverseList(int index) const
{
  Node<T>* temp = m_front;
  for(int i=1;i<index;++i)
  {
    temp=temp->getNext();
  }
  return temp;
}

//private helper method
template <typename T>
void LinkedList<T>::append(T newEntry)
{
  Node<T>* newNode = new Node<T>(newEntry);
  Node<T>* temp = m_front;
  while(temp->getNext() != nullptr)
  {
    temp = temp->getNext();
  }
  temp->setNext(newNode);
  ++m_length;
}

//private helper method
template <typename T>
void LinkedList<T>::push(T newEntry)
{
  Node<T>* temp = m_front;
  m_front = new Node<T>(newEntry);
  m_front->setNext(temp);
  ++m_length;
}
