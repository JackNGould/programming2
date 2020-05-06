# LAB 02
This program involves the building of a basic data structure. A Stack is built that (for now) only accepts chars. Templating to follow
This lab implements a mode which allows the user of the program to check if a sequence of curly braces is balanced using the stack.

## New Topics:
* Node based custom Stack implementation

## Input:
2 modes. Test mode (-t) and parser mode(-p)
### Test mode: -t
* No user input in this mode.
* Program runs a battery of pre-designed tests on the StackOfChars class
* Attempts to focus on corner cases.
* Displays results to screen.

All tests currently in a passing state.

### Parser mode: -p
* Will prompt user to pass in a string of braces {} 
* Will use a stackOfChars to check if the sequence is balanced of not

## Example Runs
### Example 1
```
╰─ ./lab02 -p

Enter your sequence: {}{}}

Number of chars is odd, balance impossible.

Sequence is NOT balanced

```
### Example 2
```
╰─ ./lab02 -p

Enter your sequence: {}{}}{{}

Char count is even, checking for balance starting from the back...

Un-closed brace found, balance impossible.

Sequence is NOT balanced

```
### Example 3
```
╰─ ./lab02 -p

Enter your sequence: {{}{{{}}{}}}

Char count is even, checking for balance starting from the back...

All braces closed, balance guaranteed.

Sequence IS balanced

```
### Example 4
```
╰─ ./lab02 -p

Enter your sequence: }{{}}}

Char count is even, checking for balance starting from the back...

Sequence is missing 2 or more opening braces. Balance impossible.

Sequence is NOT balanced

```
