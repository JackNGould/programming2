# LAB 03 
For this program I built a custom Queue class, and templated it along with the old stack class to allow for filling these data structures with custom objects. 

## New Topics:
* Node based Queue implementaion.
* Templating. - Stack and Queue templated
* Exception handling.

## Input:
Input file is passed in at runtime. Several sample input files are provided.
* File Format:
  * Each command on separate line.
  * Lines that don't represent a valid command are ignored.
  * Command values are checked at runtime, unsafe values will be handled
* Commands:
  * WAIT <name> - Somebody gets in line for elevator. 'name' identifies them
  * PICK_UP <num> - 'num' # of people are picked up and get on the elevator.
  * DROP_OFF <num> - 'num' # of people get off the elevator before it returns to ground floor 
  * INSPECTION - Elevator status displayed to screen. 
    * Is the elevator empty?
    * If elevator is not empty, who is next off?
    * If there is a line for the elevator, who is next on?

## Output
Output will be delivered to the terminal for each line of the input file

## Execution:
* 4 sample files are provided
* These or any other input file can be used by placing them in the same directory as the program executable.
* Simply pass the file name in as the parameter at the command line
```
/home/user>./lab03 sample1.txt
/home/user>./lab03 sample2.txt
/home/user>./lab03 sample3.txt
/home/user>./lab03 sample4.txt
```

