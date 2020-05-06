/*
 * @project: gameDataParser
 * @file: dataManager.h
 * @author: Jack Gould
 * @brief: Header File for Executive class. Lists member methods. Initialized by main(). Class governs the programs 'executive' actions of reading the input file, filling an array with game objects, and running the menu.
 * @date: 01-01-2020
 */
#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include "game.h"

class dataManager
{
  public:

   /* Constructor
    * @pre
    * @param std::string fname - name of the file to be opened for parsing
    * @post - A new dataManager is created, reading in from the file to create the array of games.
    * @throws - Exception if the file could not be opened or found
    */
    dataManager(std::string fname);

   /* 
    * @pre - the file was opened successfully, contents read into gameList.
    * @post - displays menu, waits for user interactions. 
    */
    void run();

   /* Destructor
    * @pre
    * @post - The dataManager object is deleted - all filled Lists are emptied
    */
    ~dataManager();


  private:

    //variable stores the number of games in the input file. First line read in. 
    int gameCount;

    //array of games initialized to nullptr
    game* gameList = nullptr;

    //boolean variable for menu operation. When user chooses to exit the program, this will be set to false and the program will exit.
    bool runMenu = true;

    /*
     * @pre: helper function called during execution of run() to clear input buffers
     * @post: 2 lines are run, calling cin.clear() and cin.ignore. Clears input buffers.
     */
    void clearCin();

   /* 
    * @pre - user selected option 1, called from the run() class. 
    * @post - prints every game from the input file, in the order it was given. 
    */
    void  printAll();

   /* 
    * @pre - user selected option 2, called from the run() class. 
    * @param int year - an integer representing the year to search for.
    * @post - prints every game from the provided year, or "No games found" if there were no games from the provided year
    */
    void printFromYear(int year);

   /* 
    * @pre - user selected option 3, called from the run() class. 
    * @param double highest - a double representing the higher number in a ranking range to search for. Must be <= 10.
    * @param double lowest - a double representing the lower number in a ranking range to search for. Must be >= 0.
    * @post - prints every game from the provided (Gibbons) ranking range. 
    */
    void printByRange(double highest, double lowest);


   /* 
    * @pre - user selected option 4, called from the run() class. 
    * @param double delta - a double representing the difference between the people's ranking and Dr. Gibbons' ranking. 
    * @post - prints every game that has a PubRating/IndividualRanking delta that is greater than or equal to the passed in value. 
    */
    void printByDelta(double delta);

   /* 
    * @pre - user selected option 3, called from the run() class. 
    * @param int minimumPlayers - an integer representing the user's desired minimum player count. 
    * @param int minimumPlaytime - an integer representing the user's desired minimum playing time.
    * @post - prints every game from the array that satisfies both the users minPlayers and minPlaytime requests. 
    */
    void findGame(int minimumPlayers, int minimumPlaytime);

};
#endif
