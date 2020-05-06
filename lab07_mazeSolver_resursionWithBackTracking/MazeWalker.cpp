/*
 * File Name: MazeWalker.cpp
 * @assignment EECS 268 Lab07 
 * @file: MazeReader.cpp
 * @author: Jack Gould
 * @brief: Implementation file for Maze Walker class. Construction is dependent upon successfull reading of a well formatted input file(throws exception otherwise). Uses helper functions to attempt to solve maze and display results. #includes MazeWalker class for recursive solving.
 * @date: 04-08-2020
 */
#include "MazeWalker.h"


MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols)
{
  m_rows = rows;
  m_cols = cols;
  m_startRow = startRow;
  m_startCol = startCol;
  m_maze = mazePtr;
  m_visited = new int*[m_rows];
  for(int i=0;i<m_rows;++i)
  {
    m_visited[i] = new int[m_cols]; //Creates the visited array using the same dimensions as the maze itself
  }
  for(int i=0;i<m_rows;++i)
  {
    for(int j=0;j<m_cols;++j)
    {
      m_visited[i][j] = 0; //Fills the visited array with 0s
    }
  }
}

MazeWalker::~MazeWalker()
{
  for(int i=0;i<m_rows;++i)
  {
    delete[] m_visited[i];
  }
  delete[] m_visited;
}

bool MazeWalker::isValid(int r, int c)
{
  if((r>=0 && r<m_rows && c>=0 && c<m_cols))
  {
    if((m_maze[r][c] == 'P' || m_maze[r][c] == 'E') && m_visited[r][c] == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool MazeWalker::walkMaze()
{
  if(recursiveWalker(m_startRow, m_startCol) == true) //begins the recursive maze solver at starting position
  {

    return true;
  }
  else
  {
    return false;
  }
}

bool MazeWalker::recursiveWalker(int r, int c)
{
  if(isValid(r, c) == true)
  {
    if(m_maze[r][c] == 'E')
    {
      ++m_stepCounter;
      m_visited[r][c] = m_stepCounter;
      return true;
    }
    ++m_stepCounter;
    m_visited[r][c] = m_stepCounter;
    if((recursiveWalker(r-1,c) == true))
    {
      return true;
    }
    else if(recursiveWalker(r,c+1) == true)
    {
      return true;
    }
    else if(recursiveWalker(r+1,c) == true)
    {
      return true;
    }
    else if(recursiveWalker(r,c-1) == true)
    {
      return true;
    }
    else
    {
      --m_stepCounter; //BACKTRACKING - decrements step counter
      m_visited[r][c] = (-1); // BACKTRACKING -  I decided to display dead end routes in the final visited array as sequences of (-1)
      return false;
    }
  }
  return false;
}


const int* const* MazeWalker::getVisited() const
{
  return m_visited;
}

int MazeWalker::getVisitedRows() const
{
  return m_rows;
}

int MazeWalker::getVisitedCols() const
{
  return m_cols;
}

const char* const* MazeWalker::getMaze() const
{
  return m_maze;
}


bool MazeWalker::isGoalReached(int r, int c) const
{
  if(m_maze[r][c] == 'E')
  {
    return true;
  }
  else
  {
    return false;
  }
}

