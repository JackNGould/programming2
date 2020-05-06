/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: BNodeInterface.h
 * @author: Jack Gould
 * @brief: Header file for an interface. Lists the pure virtual methods that must be implemented by any subclass. Subclasses: BNode
 * @date: 04-17-2020
 */
#ifndef B_NODE_INTERFACE_H
#define B_NODE_INTERFACE_H



template <typename ItemType>
class BNodeInterface
{
    public:
    
    /* Destructor
     * @pre
     * @post this Node is deleted
     */
    virtual ~BNodeInterface() {};

    /*
     * @pre
     * @return ItemType Returns m_value, the data stored in this node
     */
    virtual ItemType getEntry() const = 0;

    /*
     * @pre
     * @return BNode<ItemType>* Returns m_left, a pointer to this nodes left child
     */
    virtual BNodeInterface<ItemType>* getLeft() const = 0;

    /*
     * @pre
     * @return BNode<ItemType>* Returns m_right, a pointer to this nodes right child
     */
    virtual BNodeInterface<ItemType>* getRight() const = 0;

    /*
     * @pre
     * @param ItemType entry - the item to be stored in this node
     * @post m_value is set to entry. This node's entry is set to the ItemType parameter passed in
     */
    virtual void setEntry(ItemType entry) = 0;
  
/*NOTE
 * The final two methods were commented out below.
 * I tried for a LONG time to get them to work as described, but the parameter of type BNodeInterface<ItemType>* caused problems
 * If I defined this method as typed here, then I get compiler error for cannot convert from BNodeInterface* To BNode* in its implementation.
 * But If I try to rename the function in the derived class 'void setLeft(BNode<ItemType>* left)' then it fails to compile because these pure virtual methods were not defined. 
 * In the end, the only solution I could see was to either 
 *      1) #include BNode.h in this file so I could rename these functions with BNode* as the parameter without error
 *          - this just seems silly to include the derived class in the base class
 *      2) remove these pure virtual functions and leave them to be defined in the derived class
 * I get that A BNode IS a BNodeInterface according to the rules of inheritance, but I guess I'm missing something
 */

    /*
     * @pre
     * @param BNode<ItemType>* left - Pointer to a BNode<ItemType> to be made this node's left child
     * @post m_left is set to left. This node's left child is set to the pointer parameter passed in
     */
//    virtual void setLeft(BNodeInterface<ItemType>* left) = 0;
    
    /*
     * @pre
     * @param BNode<ItemType>* right - Pointer to a BNode<ItemType> to be made this node's right child
     * @post m_right is set to right. This node's right child is set to the pointer parameter passed in
     */
//    virtual void setRight(BNodeInterface<ItemType>* right) = 0;
    
};

#endif
