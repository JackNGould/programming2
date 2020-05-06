/*
 * @project: Binary Search Tree filled with custom objects.
 * @file: executive.h
 * @author: Jack Gould
 * @brief: Header File for executive class. Lists member methods. Class governs the program's 'executive' actions of filling a BST from the inputFile data, and generating a menu of options for the user. Controls program flow.
 * @date: 04-17-2020
 */
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Queue.h"
#include "BST.h"
#include "pokemon.h"
#include <sstream>
#include <fstream>
#include "treeTest.h"

class executive
{
  public:
    
    /* Constructor
     * @pre
     * @param std::string fName - Name of file to be opened and added to the input Queue line by line
     * @post A new executive object is created that attempts to read input from the provided file name
     */
    executive(std::string fName);

    /* Destructor
     * @pre
     * @post 
     */
    ~executive();

    /* 
     * @pre - the executive object is created and successfully opens the file
     * @post - the executive object runs, starting the main program and displaying the menu
     */
    void run();

    void writeToFile(pokemon entry);

  private:
    Queue<std::string> inputLineList; //Queue, each Node holds a line of the input file. In this case, the info of one pokemon object
    BST<pokemon, std::string> myBST; //A Binary Search Tree created upon initialization of executive object. Starts empty 
    BST<pokemon, std::string> copyBST; //A Binary Search Tree created upon initialization of executive object. Starts empty and is only filled by copying the original.
    std::string outFileName; //string to store the name of the output file
    bool copyCreated = false; //boolean to track whether a deep copy has been created or not. Allows this action one time only during runtime
    treeTest tester;

    std::ofstream outFile; //output file stream 

    void savePokedexPrompts(int& pokedex, int& traversal, std::string& outFile);
    
    /* 
     * @pre - called inside member function run(). Assumes properly formatted file, but is capable of handling duplicates
     * @post - The Binary Search Tree myBST is filled with objects from the inputLineList
     * @throws jackException if an entry could not be added because it is already in the Tree
     */
    void fillTree();
};
#endif

