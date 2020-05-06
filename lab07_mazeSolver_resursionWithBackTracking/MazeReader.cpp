/*
 * File Name: MazeReader.cpp
 * @assignment EECS 268 Lab07 
 * @file: MazeReader.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Maze Reader class. Construction is dependent upon successfull reading of a well formatted input file(throws exception otherwise). Uses helper functions to attempt to solve maze and display results. #includes MazeWalker class for recursive solving.
 * @date: 04-08-2020
 */

#include <iostream>
#include "MazeWalker.h"
#include "MazeCreationException.h"
#include "MazeReader.h"


MazeReader::MazeReader(std::string file)
{
  inFile.open(file);
  if (inFile.is_open())
  {
    inFile >> m_numRows >> m_numCols >> m_startRow >> m_startCol;
    if(m_numRows>=1 && m_numCols>=1)
    {
      maze = new char*[m_numRows]; // Allocate maze along 1 dimension 
        for(int i=0;i<m_numRows;++i) // Loop to allocate maze along a 2nd dimension 
        {
          maze[i] = new char[m_numCols];
        }
        try
        {
        readMaze();
        }
        catch(std::exception& e)
        {
          std::cout << e.what();
        }
    }
    else
    {
      throw(MazeCreationException("Invalid file, number of rows or columns is below 1\n"));
    }
  }
  else
  {
    throw(MazeCreationException("Failed to open file.\n"));
  }
}


MazeReader::~MazeReader()
{
  for(int i=0;i<m_numRows;++i)
  {
    delete[] maze[i];
  }
  delete[] maze;
}

const char* const* MazeReader::getMaze() const
{
  return maze;
}

int MazeReader::getCols() const
{
  return m_numCols;
}

int MazeReader::getRows() const
{
  return m_numRows;
}

int MazeReader::getStartCol() const
{
  return m_startCol;
}

int MazeReader::getStartRow() const
{
  return m_startRow;
}

void MazeReader::readMaze()	
{
  for(int i=0;i<m_numRows;++i)
  {
    for(int j=0;j<m_numCols;++j)
    {
      inFile >> maze[i][j]; //Fills maze with characters from file
    }
  }
  if(maze[m_startRow][m_startCol] == 'P')
  {
    MazeWalker walker(maze, m_startRow, m_startCol, m_numRows, m_numCols); //File is valid, creates a MazeWalker
    std::cout << "\nStarting Position: " << m_startRow << "," << m_startCol << '\n';
    std::cout << "Size: " << m_numRows << "," << m_numCols << '\n';
    if (walker.walkMaze() == true)
    {
      const int* const* visited = walker.getVisited();
      for (int i=0;i<m_numRows;++i)
      {
        for(int j=0;j<m_numCols;++j)
        {
          if(j == (m_numCols-1))
          {
            std::cout << visited[i][j] << '\n';
          }
          else
          {
            std::cout << visited[i][j] << '\t';
          }
        }
      }
      std::cout << "We escaped!\n";
    }
    else
    {
      std::cout << "No way out!\n"; 
    }
  }
  else
  {
    throw(MazeCreationException("InvalidStartingPosition"));
  }
}
