/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: BSTinterface.h
 * @author: Jack Gould
 * @brief: Header file for an interface. Lists the pure virtual methods that must be implemented by any subclass. Subclasses: BST
 * @date: 04-17-2020
 */
#ifndef BST_INTERFACE_H
#define BST_INTERFACE_H

#include <functional>

template <typename ItemType, typename KeyType>
class BSTinterface
{
    public:

    /* Destructor
     * @pre
     * @post This Binary Search tree is deleted. Calls clear(), which calls nukeTree(BNode<ItemType>* rootPtr);
     */
    virtual ~BSTinterface(){}

    /*
     * @pre
     * @param ItemType entry - the item to be added to the Binary Search Tree
     * @post creates new BNode containing the passed in entry. If first node, will create it directly, otherwise, will pass the entry to recursiveInOrderAdd for placement
     * @throws Throws a jackException if the entry passed in is already in the tree; 
     */
    virtual void add(ItemType entry) = 0;

    /*
     * @pre
     * @param KeyType key - A key to search the pokedex for. KeyType can be any type that the given class ItemType is prepared to handle via comparison operators
     * @post Attempts to call the recursive method contains(KeyType key, BNode<ItemType>* subTree) passing in the key and rootPtr, which searches the entire tree for the key
     * @return ItemType - Returns the entire object stored in the tree if the key is found, otherwise, throws exception.
     * Note - this method does not throw any exceptions, simply calls the private helper method, which will throw the exception if necessary
     */
    virtual ItemType search(KeyType key) const = 0;

    /*
     * @pre - Destructor was called
     * @post - Calls the recursive function nukeTree(BNode<ItemType>* subTree), passing in rootPtr as the parameter, which will delete the tree
     */
    virtual void clear() = 0;
    //More methods to come in next lab

    virtual void remove(KeyType key) = 0; //throws std::runtime_error if not in tree

    virtual void visitPreOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in pre order

    virtual void visitInOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in in order

    virtual void visitPostOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in post order
};

#endif
