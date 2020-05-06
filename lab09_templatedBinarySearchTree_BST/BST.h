/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: BST.h
 * @author: Jack Gould
 * @brief: Header file for templated Binary Search Tree. Lists  member methods. Heavy use of recursion
 * @date: 04-17-2020
 */
#ifndef BST_H
#define BST_H

#include "BSTinterface.h"
#include "BNode.h"
#include "jackException.h"

template <typename ItemType, typename KeyType>
class BST: public BSTinterface<ItemType, KeyType>
{
  public:
    /* Constructor
     * @pre
     * @post A new Binary Search Tree is created with no contents.
     */
    BST(); //Creates empty Binary Search Tree
   
    /* Copy Constructor
     * @pre - existing BST passed in
     * @param const BST& rhs - Original Binary Search tree to be copied 
     * @post A new Binary Search Tree is created with contents identical to the passed in BST
     */
    BST(const BST& rhs);

    /* Assignment Operator Overloading
     * @pre - existing BST passed in
     * @param const BST& rhs - Original Binary Search tree to be copied 
     * @return BST& - Calling object's contents are made identical to the passed in parameter
     */
    BST<ItemType, KeyType>& operator=(const BST& rhs);

    /* Destructor
     * @pre
     * @post This Binary Search tree is deleted. Calls clear(), which calls nukeTree(BNode<ItemType>* rootPtr);
     */
    ~BST(); 

    /*
     * @pre
     * @param ItemType entry - the item to be added to the Binary Search Tree
     * @post creates new BNode containing the passed in entry. If first node, will create it directly, otherwise, will pass the entry to recursiveInOrderAdd for placement
     * @throws Throws a jackException if the entry passed in is already in the tree; 
     */
    void add(ItemType entry);

    /*
     * @pre
     * @param KeyType key - A key to search the pokedex for. KeyType can be any type that the given class ItemType is prepared to handle via comparison operators
     * @post Attempts to call the recursive method contains(KeyType key, BNode<ItemType>* subTree) passing in the key and rootPtr, which searches the entire tree for the key
     * @return ItemType - Returns the entire object stored in the tree if the key is found, otherwise, throws exception.
     * Note - this method does not throw any exceptions, simply calls the private helper method, which will throw the exception if necessary
     */
    ItemType search(KeyType key) const;

    /* 
     * @pre
     * @post calls recursive function printInOrder to print the tree in in-order
     */
    void print() const;

    /*
     * @pre
     * @return bool - Returns true if the BST is empty, false otherwise
     */
    bool isEmpty() const;

    /* 
     * @pre
     * @param KeyType key - the american name of the pokemon to remove
     * @post calls recursive function removeRecursive to print the tree in in-order
     * @throws - jackException if the given key is not found in the pokedex
     */
    void remove(KeyType key); //throws std::runtime_error if not in tree

    /* 
     * @pre
     * @param function void visit - function taking a single ItemType parameter that will operate on the contents of each node
     * @post calls the private recursive function recursivePreOrder passing in visit and rootPtr
     */
    void visitPreOrder(std::function<void(ItemType)> visit) const; //Visits each node in pre order

    void visitInOrder(std::function<void(ItemType)> visit) const; //Visits each node in in order

    void visitPostOrder(std::function<void(ItemType)> visit) const; //Visits each node in post order

  private:
   
    /* 
     * @pre
     * @param BNode<ItemType>* deleteThisNode - a pointer to the node to be deleted by this function
     * @post removes the node deleteThisNode from the BST
     * @return BNode<ItemType>* - Returns a pointer to the new node that is placed in the spot previously occupied by deleteThisNode
     */
    BNode<ItemType>* deleteNode(BNode<ItemType>* deleteThisNode);
    
    /* 
     * @pre
     * @param BNode<ItemType>* deleteThisNode - a pointer to the node to be deleted by this function
     * @param ItemType& nextNode - pointer to the node to be delete
     * @post removes the node deleteThisNode from the BST
     * @return BNode<ItemType>* - Returns a pointer 
     */
    BNode<ItemType>* grabSuccessorNode(BNode<ItemType>* deleteThisNode, ItemType& nextNode);
    
    BNode<ItemType>* removeRecursive(KeyType key, BNode<ItemType>* subTree, bool& removed);
    
    /* 
     * @pre
     * @param function void visit - function taking a single ItemType parameter that will operate on the contents of each node
     * @param BNode<ItemType>* subTree - a pointer to the current subTree being examined by the recursive function. Starts at rootPtr when called
     * @post visits each node of the BST in PreOrder and gets the node's entry, passing it to the function visit for operation
     */
    void recursivePreOrder(std::function<void(ItemType)> visit, BNode<ItemType>* subTree) const;

    /* 
     * @pre
     * @param function void visit - function taking a single ItemType parameter that will operate on the contents of each node
     * @param BNode<ItemType>* subTree - a pointer to the current subTree being examined by the recursive function. Starts at rootPtr when called
     * @post visits each node of the BST in In-Order and gets the node's entry, passing it to the function visit for operation
     */
    void recursiveInOrder(std::function<void(ItemType)> visit, BNode<ItemType>* subTree) const;

    /* 
     * @pre
     * @param function void visit - function taking a single ItemType parameter that will operate on the contents of each node
     * @param BNode<ItemType>* subTree - a pointer to the current subTree being examined by the recursive function. Starts at rootPtr when called
     * @post visits each node of the BST in PostOrder and gets the node's entry, passing it to the function visit for operation
     */
    void recursivePostOrder(std::function<void(ItemType)> visit, BNode<ItemType>* subTree) const;

    /* 
     * @pre
     * @param BNode<ItemType>* curTree - a pointer to the current subTree being examined by the recursive function. Starts at rootPtr when called
     * @post Recursively visits each node of the tree in the parameter in PreOrder and copies its contents to the calling object
     */
    BNode<ItemType>* recursiveCopy(BNode<ItemType>* curTree); 

    BNode<ItemType>* rootPtr; //pointer to the root of the Binary Search Tree

    /*
     * @pre - ItemType newEntry is NOT already in the subTree 
     * @param ItemType newEntry - the item to be added to the Binary Search Tree
     * @param BNode<ItemType>* subTree - A pointer to the current subtree being examined by the recursive function. Starts at rootPtr
     * @post creates new BNode containing the passed in entry. Recursively calls itself to find the correct placement before creating and setting the BNode
     */
    void recursiveInOrderAdd(ItemType newEntry, BNode<ItemType>* subTree);

    /*
     * @pre
     * @param KeyType key - A key to search the pokedex for. KeyType can be any type that the given class ItemType is prepared to handle via comparison operators
     * @param BNode<ItemType>* subTree - Pointer to the current subtree being examined by the recursive function. Starts at rootPtr
     * @return ItemType - Returns the entire object stored in the tree if the key is found, otherwise, throws exception.
     * @throws jackException - if the key passed in was not found in the tree
     */
    ItemType contains(KeyType key, BNode<ItemType>* subTree) const;

    /*
     * @pre - Destructor was called, which called clear(), calling this function
     * @param BNode<ItemType>* subTree - A pointer to the current subtree being examined by the recursive function. Starts at rootPtr
     * @post recursively destroys the tree using a post order traversal(traverse left, then traverse right, then delete the node), ensuring all children are deleted before their parents
     */
    void nukeTree(BNode<ItemType>* subTree);
    
    /*
     * @pre - Destructor was called
     * @post - Calls the recursive function nukeTree(BNode<ItemType>* subTree), passing in rootPtr as the parameter, which will delete the tree
     */
    void clear();

    /* 
     * @pre the public method print() was called, calling this function. 
     * @param BNode<ItemType>* subTree - A pointer to the current subtree being examined by the recursive function. Starts at rootPtr
     * @post Prints the entire Binary Search Tree via an in-order traversal(Traversing left, then printing, then traversing right), ensuring the nodes are printed from minimum to maximum
     */
    void printInOrder(BNode<ItemType>* subTree) const;

    /* Description - This function is called only when attempting to add an entry to the tree.
     * @pre the member variable isCopy must be set to false just prior to running this function.
     * @param ItemType newEntry - the new Entry. Will be compared with every value currently in the tree to make sure it isn't a duplicate. 
     * @param BNode<ItemType>* subTree - A pointer to the current subtree being examined by the recursive function. Starts at rootPtr
     * @return bool - Returns true if the passed in entry is a duplicate of some node already in the tree, and its addition must be disallowed. Returns false otherwise, and allows the addition
     */
    void isDuplicate(ItemType newEntry, BNode<ItemType>* subTree, bool& isCopy);

    int nodeCount; //a counter that tracks the number of nodes in the tree. Doesn't actually need to be here at the moment
   // bool isCopy; //a tracker variable that helps out the isDuplicate method. It is set to false just prior to running isDuplicate. Made to be a parameter to isDuplicate instead of class-scope 

};
#include "BST.cpp"
#endif





