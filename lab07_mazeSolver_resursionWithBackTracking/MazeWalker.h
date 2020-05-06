/*
 * File Name: MazeWalker.h
 * Author: Jack Gould
 * Assignment: EECS_268 Lab06
 * Description: Header file for MazeWalker class.
 */
#ifndef MAZE_WALKER
#define MAZE_WALKER

class MazeWalker
{
  public:
    
    
    // BELOW ARE REQUIRED METHODS FOR MAZEWALKER BUT YOU WILL NEED MORE!
    // FOR EXAMPLE, YOU'LL NEED METHOD(S) TO RECUSIVELY TRAVERSE THE MAZE!
  	/**
  	*	@pre The mazePtr pointer is to a valid maze.
  	*	@post A maze walker is created ready to traverse the maze from the start position is the specified order.
  	*/
  	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols);
  
  	/**
  	*
  	*	@pre The visited array still exists and has the same dimensions (rows X cols)
  	*	@post The visited array is deallocated
  	*/
  	~MazeWalker();
  
  	/**
  	*	@pre The maze is a valid maze.
  	*	@post The maze is traversed until the end is reached or all moves are exhausted. 
  	*	@return true if an exit was reached, false otherwise
  	*/
  	bool walkMaze();
  
    
  
  
  	/**
  	*	@return A const pointer to the visited array. (A pointer that cannot change the array)
  	*/
  	const int* const* getVisited() const;
  
  	/**
  	*	@return number of rows in maze
  	*/
  	int getVisitedRows() const;
  
  	/**
  	*	@return number of cols in maze
  	*/
  	int getVisitedCols() const;
  
  	/**
  	*	@return A const pointer to the maze. (A pointer that cannot change the array)
  	*/
  	const char* const* getMaze() const;
  private:  
    /**
  	*	@pre 
  	*	@post
  	*	@return Returns a boolean indicating whether the solution is found
  	*/
    bool recursiveWalker(int r, int c);

  	/**
  	*	@returns If the current position is the exit, true is returned. False is returned otherwise.
  	*/		
  	bool isGoalReached(int r, int c) const;
    
  	/**
  	*	@returns If the coordinates in question(r,c) indicate a spot in the maze that can be navigated to, true is returned. False is returned otherwise.
  	*/		
    bool isValid(int r, int c);

    /**
     * private variables
     */
  	const char* const* m_maze;
  	int** m_visited;
  	int m_rows, m_cols;
  	int m_startRow, m_startCol;
    int m_stepCounter = 0;

};

#endif
