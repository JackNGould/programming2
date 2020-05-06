/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: BNode.h
 * @author: Jack Gould
 * @brief: Header file for templated Binary Node class. Lists member methods. These nodes fill the search tree. Inherits from BNodeInterface
 * ***This allows each node to contain a highly variable amount of data. In this lab, each node will contain an object of type 'pokemon', defined in a separate file.
 * @date: 04-17-2020
 */
#ifndef B_NODE_H
#define B_NODE_H

#include "BNodeInterface.h"

template <typename ItemType>
class BNode: public BNodeInterface<ItemType>
{
  public:
    
    /* Constructor
     * @pre
     * @param ItemType value - the item to be stored in this node
     * @post A new BNode<ItemType> is created with m_value = value
     */
    BNode(ItemType value);

    /* Destructor
     * @pre
     * @post this Node is deleted
     */
    ~BNode();

    /*
     * @pre
     * @return ItemType Returns m_value, the data stored in this node
     */
    ItemType getEntry() const;

    /*
     * @pre
     * @return BNode<ItemType>* Returns m_left, a pointer to this nodes left child
     */
    BNode<ItemType>* getLeft() const;

    /*
     * @pre
     * @return BNode<ItemType>* Returns m_right, a pointer to this nodes right child
     */
    BNode<ItemType>* getRight() const;

    /*
     * @pre
     * @param ItemType entry - the item to be stored in this node
     * @post m_value is set to entry. This node's entry is set to the ItemType parameter passed in
     */
    void setEntry(ItemType entry);

    /*
     * @pre
     * @param BNode<ItemType>* left - Pointer to a BNode<ItemType> to be made this node's left child
     * @post m_left is set to left. This node's left child is set to the pointer parameter passed in
     */
    void setLeft(BNode<ItemType>* left);

    /*
     * @pre
     * @param BNode<ItemType>* right - Pointer to a BNode<ItemType> to be made this node's right child
     * @post m_right is set to right. This node's right child is set to the pointer parameter passed in
     */
    void setRight(BNode<ItemType>* right);

  private:
    ItemType m_value; //data container. Lab08 fills with custom data type 'pokemon'
    BNode<ItemType>* m_left; //pointer to this node's left child
    BNode<ItemType>* m_right; //pointer to this node's right child

};
#include "BNode.cpp"
#endif
