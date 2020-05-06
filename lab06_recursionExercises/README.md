# LAB 06 
 This program introduces recursion. Several exercises are implemented.
 * Makefile creates a single executable, and copies it 3 times.
 * Which of the 4 exercises run depends on the executable name used to start the program.

## New Topics:
  * Recursion
  * argv[0] usage to create polymorphic program dependent on executable name

## Input:
Program execution depends on executable name. Exceptions thrown on bad input.
### Executable names
The following 4 executables are generated when the makefile is run.
   * If compiling manually, copy and rename your executable 3 times. 
```
~/lab04: cp parens perm && cp parens fib && cp parens parensV2
```
#### Executable name: ./parens
    * Program run: parenthesis checker
    * additional arguments: sequence of parenthesis in quotes to balance check.
##### Example runs: 
```
      ./parens "()()()"
      The Sequence "()()()" is Balanced
      
      ./parens "())("
      The Sequence "())(" is NOT Balanced
```
#### Executable name: ./perm
    * Program run: permutaion generator
    * additional arguments: string to permute.
      * assumes all unique characters. If there are repeat characters, repeate permutations will exist.
##### Example Run
```
      ./perm dog
      1) dog
      2) dgo
      3) odg
      4) ogd
      5) god
      6) gdo
```
#### Executable name: ./fib
    * Program run: fibonacci program
    * additional arguments: -i for ith mode -v for verify mode
      * -i: 
        * additional argument: integer representing index of the fibonacci sequence to print.  
      * -v:
        * additional argument: integer to search the fibonacci sequence for
##### Example Runs:
```
      ./fib -i 2
      1
      ./fib -i 36
      14930352
      ./fib -v 75025
      75025 is in the fibonacci sequence. Its index is 25
      ./fib -v 7
      7 is NOT in the fibonacci sequence.
```
#### Executable name: ./parensV2
    * Program run: parenthesis checker version 2
    * additional arguments: string in quotes to balance check for: {}[]()
      * strips string of unneccessary input
##### Example Runs:
```
      ./parensV2 "(TestString)stuff[ToFill]{}thisWit(h)"
      The sequence "(TestString)stuff[ToFill]{}thisWit(h)" is Balanced
      
      ./parensV2 "[(TestString)stuff[ToFill]{}thisWit(h)]"
      The sequence "[(TestString)stuff[ToFill]{}thisWit(h)]" is Balanced

      ./parensV2 "((TestString)stuff[ToFill]{}thisWit(h)"
      The Sequence "((TestString)stuff[ToFill]{}thisWit(h)" is NOT Balanced
```

