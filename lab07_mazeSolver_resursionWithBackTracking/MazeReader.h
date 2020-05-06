/*
 * File Name: MazeReader.h
 * @assignment EECS 268 Lab07 
 * @file: MazeReader.h
 * @author: Jack Gould
 * @brief: Header file for Maze Reader class. Lists member methods. Construction is dependent upon successfull reading of a well formatted input file(throws exception otherwise). Uses helper functions and #included MazeWalker class to attempt to solve maze and display results.
 * @date: 04-08-2020
 */
#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <fstream>

class MazeReader
{
  public:
    /**
     * @post A MazeReader is created. A 2D char array is allocated with the maze information.
     *	@throws MazeCreationExecption
     *
     */
     MazeReader(std::string file);

     /**
     *	@post The maze is deallocated.
     */
     ~MazeReader();

     /**
     *	@pre the file was formatting and read in correctly
     *	@return Returns pointer to the maze
     */
     const char* const* getMaze() const;

     /**
     *	@pre the file was formatted and read in correctly
     *	@returns the number of columns listed in the file
     */
     int getCols() const;

     /**
     *	@pre the file was formatted and read in correctly
     *	@returns the number of rows listed in the file
     */
     int getRows() const;

     /**
     *	@pre the file was formatted and read in correctly
     *	@returns the starting column
     */
     int getStartCol() const;

     /**
     *	@pre the file was formatted and read in correctly
     *	@returns the starting row
     */
     int getStartRow() const;


  private:
     /**
     *	@pre the file is properly formatted
     *	@post the characters representing the maze are stores
     */
     void readMaze();	

     /**
      * private member variables
      */
     int m_numCols;
     int m_numRows;
     int m_startRow;
     int m_startCol;
     std::ifstream inFile;
     char** maze = nullptr;

};

#endif
