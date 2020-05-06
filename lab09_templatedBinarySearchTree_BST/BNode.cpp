/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: BNode.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Binary Node class. Defines member methods. These nodes fill the search tree 
 * ***This allows each node to contain a highly variable amount of data. In this lab, each node will contain an object of type 'pokemon', defined in a separate file.
 * @date: 04-17-2020
 */

template <typename ItemType>
BNode<ItemType>::BNode(ItemType value)
{
  m_value = value;
  m_left = nullptr;
  m_right = nullptr;
}


template <typename ItemType>
BNode<ItemType>::~BNode()
{
}



template <typename ItemType>
void BNode<ItemType>::setEntry(ItemType entry)
{
  m_value = entry;
}

template <typename ItemType>
void BNode<ItemType>::setLeft(BNode<ItemType>* left)
{
  m_left = left;
}

template <typename ItemType>
void BNode<ItemType>::setRight(BNode<ItemType>* right)
{
  m_right = right;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>::getLeft() const
{
  return m_left;
}

template <typename ItemType>
ItemType BNode<ItemType>::getEntry() const
{
  return m_value;
}

template <typename ItemType>
BNode<ItemType>* BNode<ItemType>::getRight() const
{
  return m_right;
}

