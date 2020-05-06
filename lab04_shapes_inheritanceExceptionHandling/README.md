# LAB 04
 This program introduces inheritance. I built Circle, Triangle, and Rectangle subclasses that inherit from a 'Shape' parent class

## New Topics:
  * Inheritance
  * More exception handling

## Input:
  File passed in at runtime. 3 examples provided
### Input File Format
   * First Line: size of shape container - static variable which supercedes excessive add shape commands
   * One command per line
   * Program looks for valid command lines
#### Valid commands:
    * ADD <index> <shape code> <shape data>
      * index - index in container to insert into. Ranges from (1 - shapeContainerSize)
      * shape code - CIR for circle, TRI for triangle, REC for rectangle. Caps matter
      * shape data - radius, base and height, length and width for CIR, TRI, REC, respectively
    * DELETE <index> 
      * Deletes shape at given index
    * PRINT <index>
      * Prints shape at given index
    * EXIT
      * Exits program

## Output
  Output will be printed to the terminal for each line of the input file

## Execution
  * 3 example files provided. 
  * Example or custom files can be used by placing them in the same directory as the executable
  * Examples will already be there in case of full download
  * Simply pass the input file name as the executable's parameter
  ```
  /home/user->./lab04 example1.txt
  /home/user->./lab04 example2.txt
  /home/user->./lab04 example3.txt
  ```
