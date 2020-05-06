/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: BST.cpp
 * @author: Jack Gould
 * @brief: Implementation file for templated Binary Search Tree. Defines member methods. Heavy use of recursion
 * @date: 04-17-2020
 */
#include <iostream>

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST()
{
  rootPtr = nullptr;
  nodeCount = 0;
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST(const BST& rhs)
{
  rootPtr = recursiveCopy(rhs.rootPtr);
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>& BST<ItemType, KeyType>::operator=(const BST& rhs)
{
  rootPtr = recursiveCopy(rhs.rootPtr);
  return *this;
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::~BST()
{
  clear();
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::clear()
{
  nukeTree(rootPtr);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::add(ItemType entry)
{
  if(rootPtr == nullptr)
    {
      rootPtr = new BNode<ItemType>(entry);
      nodeCount++;
    }
  else
  {
    bool isCopy = false;
    isDuplicate(entry, rootPtr, isCopy);
    if(isCopy == true)
    {
      throw(jackException("\nDuplicate detected. The provided American Name AND pokedex number must not already exist in the pokedex.\n"));
    }
    else
    {
      recursiveInOrderAdd(entry, rootPtr);
      nodeCount++;
      return;
    }
  }
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::isDuplicate(ItemType newEntry, BNode<ItemType>* subTree, bool& isCopy)
{
  if(subTree == nullptr)
  {
    return;
  }
  isDuplicate(newEntry, subTree->getLeft(), isCopy);
  isDuplicate(newEntry, subTree->getRight(), isCopy);
  if(newEntry == subTree->getEntry())
  {
    isCopy = true;
  }
  return;

}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recursiveInOrderAdd(ItemType newEntry, BNode<ItemType>* subTree)
{
  if(newEntry>(subTree->getEntry()))
  {
    if(subTree->getRight() == nullptr)
    {
      BNode<ItemType>* temp = new BNode<ItemType>(newEntry);
      subTree->setRight(temp);
    }
    else
    {
      recursiveInOrderAdd(newEntry, subTree->getRight());
    }
  }
  else
  {
    if(subTree->getLeft() == nullptr)
    {
      BNode<ItemType>* temp = new BNode<ItemType>(newEntry);
      subTree->setLeft(temp);
    }
    else
    {
      recursiveInOrderAdd(newEntry, subTree->getLeft());
    }
  }
}

template<typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::isEmpty() const
{
    return (rootPtr == nullptr);
}

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::search(KeyType key) const
{
  ItemType result = contains(key, rootPtr); //calls contains method which recursively searches the tree for the given key
  return (result);
}

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::contains(KeyType key, BNode<ItemType>* subTree) const
{
  if(subTree->getEntry() == key)
  {
    return (subTree->getEntry());
  }
  else if(subTree->getLeft() == nullptr && subTree->getRight() == nullptr)
  {
    throw(jackException("\nThe provided name was not found in the pokedex.\n"));
  }
  else if(subTree->getEntry() > key)
  {
    if(subTree->getLeft() == nullptr)
    {
      throw(jackException("\nThe provided name was not found in the pokedex.\n"));
    }
    return(contains(key, subTree->getLeft()));
  }
  else
  {
    if(subTree->getRight() == nullptr)
    {
      throw(jackException("\nThe provided name was not found in the pokedex.\n"));
    }
    return(contains(key, subTree->getRight()));
  }
}

/* ----- OLD METHODS ---- USED IN LAB08 FOR TESTING/DEBUGGING
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::print() const
{
  printInOrder(rootPtr);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::printInOrder(BNode<ItemType>* subTree) const
{
  if(subTree != nullptr)
  {
    printInOrder(subTree->getLeft());
    KeyType name = ((subTree->getEntry()).getAmerican());
    std::cout << "\n" << name << '\n';
    printInOrder(subTree->getRight());
  }
  else
  {
    return;
  }
}
*/


template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::nukeTree(BNode<ItemType>* subTree)
{
  if(subTree != nullptr)
  {
    nukeTree(subTree->getLeft());
    nukeTree(subTree->getRight());
    delete subTree;
  }
}

template <typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>::deleteNode(BNode<ItemType>* deleteThisNode)
{
  if(deleteThisNode->getLeft() == nullptr && deleteThisNode->getRight() == nullptr)
  {
    delete deleteThisNode;
    deleteThisNode = nullptr;
    return deleteThisNode;
  }

  else if((deleteThisNode->getLeft() == nullptr && deleteThisNode->getRight() != nullptr) || (deleteThisNode->getLeft() != nullptr && deleteThisNode->getRight() == nullptr))
  {
    BNode<ItemType>* onlyChild;
    if(deleteThisNode->getLeft() != nullptr)
    {
      onlyChild = deleteThisNode->getLeft();
    }
    else
    {
      onlyChild = deleteThisNode->getRight();
    }
    delete deleteThisNode;
    deleteThisNode = nullptr;

    return onlyChild;
  }

  else
  {
    ItemType nextNode;

    //grabs the minimum of the (node to delete's) right subtree, which should be the successor node. Will delete that node and transfer its contents up to the spot of the node to delete
    BNode<ItemType>* temp = grabSuccessorNode(deleteThisNode->getRight(), nextNode);
    deleteThisNode->setRight(temp);
    deleteThisNode->setEntry(nextNode);
    return deleteThisNode;
  }
}

template <typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>::grabSuccessorNode(BNode<ItemType>* deleteThisNode, ItemType& nextNode)
{
  if(deleteThisNode->getLeft() == nullptr)
  {
    nextNode = deleteThisNode->getEntry();
    return(deleteNode(deleteThisNode));
  }
  else
  {
    deleteThisNode->setLeft(grabSuccessorNode(deleteThisNode->getLeft(), nextNode));
    return deleteThisNode;
  }
}

template <typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>::removeRecursive(KeyType key, BNode<ItemType>* subTree, bool& removed)
{
  if(subTree == nullptr)
  {
    removed = false;
    throw(jackException("\nProvided key not found in the search Tree.\n"));
  }
  else if(subTree->getEntry() == key)
  {
    subTree = deleteNode(subTree);
    removed = true;
    return (subTree);
  }
  else if(subTree->getEntry() > key)
  {
    BNode<ItemType>* temp = removeRecursive(key, subTree->getLeft(), removed);
    subTree->setLeft(temp);
    return subTree;
  }   
  else
  {
    BNode<ItemType>* temp = removeRecursive(key, subTree->getRight(), removed);
    subTree->setRight(temp);
    return subTree;
  }
}




template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::remove(KeyType key)
{
  bool removed = false;
  rootPtr = removeRecursive(key, rootPtr, removed);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPreOrder(std::function<void(ItemType)> visit) const
{
  recursivePreOrder(visit, rootPtr);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitInOrder(std::function<void(ItemType)> visit) const
{
  recursiveInOrder(visit, rootPtr);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPostOrder(std::function<void(ItemType)> visit) const
{
  recursivePostOrder(visit, rootPtr);
}


template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recursivePreOrder(std::function<void(ItemType)> visit, BNode<ItemType>* subTree) const
{
  if(subTree != nullptr)
  {
    ItemType temp = subTree->getEntry();
    visit(temp);
    recursivePreOrder(visit, subTree->getLeft());
    recursivePreOrder(visit, subTree->getRight());
  }
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recursiveInOrder(std::function<void(ItemType)> visit, BNode<ItemType>* subTree) const
{
  if(subTree != nullptr)
  {
    recursiveInOrder(visit, subTree->getLeft());
    ItemType temp = subTree->getEntry();
    visit(temp);
    recursiveInOrder(visit, subTree->getRight());
  }

}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recursivePostOrder(std::function<void(ItemType)> visit, BNode<ItemType>* subTree) const
{
  if(subTree != nullptr)
  {
    recursivePostOrder(visit, subTree->getLeft());
    recursivePostOrder(visit, subTree->getRight());
    ItemType temp = subTree->getEntry();
    visit(temp);
  }

}

template <typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>::recursiveCopy(BNode<ItemType>* curTree)
{
  BNode<ItemType>* newNode = nullptr;
  if(curTree != nullptr)
  {
    newNode = new BNode<ItemType>(curTree->getEntry());
    newNode->setLeft(recursiveCopy(curTree->getLeft()));
    newNode->setRight(recursiveCopy(curTree->getRight()));
  }
  return newNode;
}
