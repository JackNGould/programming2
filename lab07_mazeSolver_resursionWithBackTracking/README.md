# LAB 07
 For this lab, I created a program that reads and solves character mazes using recursion with backtracking

## New Topics:
  * Recursion with **backtracking**

## Input:
  File name passed in at execution time
### Input File Format:
```
    <numRows> <numCols>
    <startingRow> <starting Column>
    <All Maze Characters>
```
  * NOTE: Maze character indexing runs from 0 to length-1
    * EX: If a maze is 5rows x 4columns, then possible starting row is 0-4 and possible starting column is 0-3 
  * Allowed Maze Characters:
    *  P = passage - can be walked through
    *  W = wall - can NOT be walked through
    *  E = exit - where you exit the maze. 
      *  Mazes do not need to have a reachable exit or an exit at all

## Execution and Output
  * Program throws exceptions on mazeReader creation if file doesn't exist, rows or columns are less than 1, or if the starting position is not in a passage.
  * If a mazeReader is created, program will attempt to solve maze using recursion and backtracking. 
  * If the maze is solved, the exit path taken will be displayed, starting at 1, with the highest number on the exit
    * Spots marked with a -1 were traversed to during maze solving as part of an abandoned path.  
  * 4 sample mazes are provided in this lab.
  * Expected output for each sample maze is shown below
### Maze 1: 
maze1.txt:
```
8 6
5 4
EWWWWW
PPPPPP
WWPWWP
PPPWWP
WPWWWW
WPPPPW
WWWWWW
WWWWWW
```
./lab07 maze1.txt
Output
```
╰─ ./lab07 maze1.txt

Starting Position: 5,4
Size: 8,6
12	0	0	0	0	0
11	10	9	-1	-1	-1
0	0	8	0	0	-1
0	6	7	0	0	-1
0	5	0	0	0	0
0	4	3	2	1	0
0	0	0	0	0	0
0	0	0	0	0	0
We escaped!

```
### Maze 2
maze2.txt:
```
20 13
6 9
EWWWWWWWPPPWW
PPPPPPWWPWPPW
WWPWWPWWWWWPW
PPPWWPWWWWPPW
WPWWWWWWWPPWW
WPPPPPWWWPPPW
WWWPWPPPPPWPW
WWWPWWWWWWWPW
WWWPWWWWWWWPW
PPPPWWWWWWWPP
WWWPPPPWWWWWP
WWWWWWPWWWWWP
WPPPPPPWWWWWW
WPWWPWWWPPWWW
WPWWPPPPPWWWW
PPWWWWWWPWWWW
WWWWWWWWPWWWW
WWWPPPPPPWWWW
WWWPWWWPWWWWW
WWWPWWWPPPWWW
```
./lab07 maze2.txt
Output
```
╰─ ./lab07 maze2.txt

Starting Position: 6,9
Size: 20,13
18	0	0	0	0	0	0	0	-1	-1	-1	0	0
17	16	15	-1	-1	-1	0	0	-1	0	-1	-1	0
0	0	14	0	0	-1	0	0	0	0	0	-1	0
0	12	13	0	0	-1	0	0	0	0	-1	-1	0
0	11	0	0	0	0	0	0	0	-1	-1	0	0
0	10	9	8	7	6	0	0	0	-1	-1	-1	0
0	0	0	-1	0	5	4	3	2	1	0	-1	0
0	0	0	-1	0	0	0	0	0	0	0	-1	0
0	0	0	-1	0	0	0	0	0	0	0	-1	0
-1	-1	-1	-1	0	0	0	0	0	0	0	-1	-1
0	0	0	-1	-1	-1	-1	0	0	0	0	0	-1
0	0	0	0	0	0	-1	0	0	0	0	0	-1
0	-1	-1	-1	-1	-1	-1	0	0	0	0	0	0
0	-1	0	0	-1	0	0	0	-1	-1	0	0	0
0	-1	0	0	-1	-1	-1	-1	-1	0	0	0	0
-1	-1	0	0	0	0	0	0	-1	0	0	0	0
0	0	0	0	0	0	0	0	-1	0	0	0	0
0	0	0	-1	-1	-1	-1	-1	-1	0	0	0	0
0	0	0	-1	0	0	0	-1	0	0	0	0	0
0	0	0	-1	0	0	0	-1	-1	-1	0	0	0
We escaped!
```
### Maze 3
maze3.txt:
```
0 0
10 10
WWWWWW
PPPPPP
WWPWWP
PPPWWP
WPWWWW
WPPPPE
```
./lab07 maze3.txt
Output to screen:
```
╰─ ./lab07 maze3.txt
Invalid file, number of rows or columns is below 1

```
### Maze 4
maze4.txt:
```
7 7
0 4
WWWWPWW
PPPPPPW
WWPWWPW
PPPWWPW
WPWWWWW
WPPPPPW
WWWWWWW
```
./lab07 maze4.txt
Output to screen:
```
╰─ ./lab07 maze4.txt

Starting Position: 0,4
Size: 7,7
No way out!
```
