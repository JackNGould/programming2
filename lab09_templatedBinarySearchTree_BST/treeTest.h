/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: treeTest.h
 * @author: Jack Gould
 * @brief: Header file for treeTest class. Lists member methods. Class runs tests on the Binary Search Tree(BST) to ensure proper functioning of constructors, destructors, etc.
 * @date: 04-17-2020
 */
#ifndef TREETEST_H
#define TREETEST_H

#include <iostream>
#include <string>
#include "BST.h"
#include "pokemon.h"
#include "jackException.h"
#include <fstream>


class treeTest
{
  public:
    
    /* Constructor
     * @pre
     * @param std::string fName - Name of file to be opened and added to the input Queue line by line
     * @post A new treeTest object is created that attempts to read input from the provided file name
     */
    treeTest();

    /* Destructor
     * @pre
     * @post 
     */
    ~treeTest();

    /* 
     * @pre - called when the user selects this test
     * @param BST<pokemon, std::string> bst - original pokedex passed in by value.
     * @post - the treeTest object runs, displaying menu. 
     *  -Prompts user for an addition to the tree in separate prompts. 
     *  -Prints remaining tree to the screen in in-order
     */
    void testAdds(BST<pokemon, std::string> bst); // Passed by value


    /* 
     * @pre - called when the user selects this test
     * @param BST<pokemon, std::string> bst - original pokedex passed in by value.
     * @post - the treeTest object runs, displaying menu. 
     *  -Prompts user for american name of pokemon to remove from the pokedex
     *  -Prints remaining tree to the screen in in-order
     */
    void testRemoves(BST<pokemon, std::string> bst); // NOTE: Passed by value!!!

//Pass in the original pokedex
//Prompts the user for a word to remove
//Prints the remaining tree to the screen in in-order

    /* 
     * @pre - called when the user selects this test
     * @param BST<pokemon, std::string> bst - original pokedex passed in by value.
     * @post - the treeTest object runs, displaying menu. 
     *  -Prompts user for an output file name
     *  -Writes the contents of the pokedex to the output file in in-order
     */
    void testWriteToFile(BST<pokemon, std::string> bst); // NOTE: Passed by value!!!


//Pass in the original pokedex
//Prompt the user for an output file name
//Writes the contents of the pokedex to the file in in-order


    /* 
     * @pre - In testAdds or testRemoves, this function is bound (using std::bind, defined in <functional>) as the parameter to the BST function visitInOrder(std::function<void(ItemType)> visit)
     *  -The same line calls visitInOrder with the bound argument, thereby running this function for all entries in the tree
     * @param entry to be printed
     * @post - Pokemon node is printed. 
     *  -due to preconditions, entire tree will be printed in In-Order whenever this function is called.
     */
    void printNode(pokemon entry);
    
    /* 
     * @pre - In testWriteToFile, this function is bound (using std::bind, defined in <functional>) as the parameter to the BST function visitInOrder(std::function<void(ItemType)> visit)
     *  -The same line calls visitInOrder with the bound argument, thereby running this function for all entries in the tree
     * @param entry to be written to the output file
     * @post - Pokemon node is written to the output file
     *  -due to preconditions, entire tree will be written to the output file in In-Order whenever this function is called.
     */
    void testWriteEntry(pokemon entry);



  private:

    //PRIVATE MEMBER VARIABLES
    std::string file;
    std::ofstream outFile;


};
#endif

