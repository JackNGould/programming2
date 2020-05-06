# Programming II - C++

This repository holds a number of C++ coding projects completed both independently and as required for my Programming 2 course. Projects were completed as learning exercises in good C++ coding practices.

Primary topics: 
* Data structures(Node and array based lists/stacks/queues, binary trees and search trees, heaps)
* Exception handling 
* Templating
* Sorting algorithms - efficiencies
* Recursion
* Memory management - Passing by pointer vs reference, stack vs heap allocation. Valgrind 
* Object oriented coding

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them

C++ compiler - Code should compile under just about any compiler(c++ std 11), but Makefiles were built assuming GCC (GNU Compiler Collection)
* [GNU Compiler Collection - GCC](https://gcc.gnu.org/ "Title")

### Installing

Clone this repository into a directory

```
~: cd Downloads
~/Downloads: git clone https://github.com/JackNGould/programming2.git
```

Each lab still needs to be compiled separately. 'make' and 'make clean' commands used

## Running the tests

Once the repo is cloned, move into a specific lab folder to work with the relevant program.
```
~/Downloads: cd programming2
~/Downloads/programming2: cd lab01_gameDataParser
```

* Each lab contains a unique README.md with detailed information about the program
* Github's website auto opens README.md files if one exists when moving to a new working directory
* You are currently reading this repo's (programming2) top-level README.md
* The README.md for each lab can be easily viewed by navigating to each labs folder.  
* Alternatively, they can also be viewed at the command line

```
~/Downloads/programming2/lab01_gameDataParser: cat README.md
```
### Compiling
To test or use a lab, first make sure that a c++ compiler is installed.
* To use the provided makefiles, g++ command needs to be available
  * GCC - GNU Compiler Collection used in development. Download below
 
* With GCC installed, simply type 'make' at a terminal in the appropriate directory to generate any executable(s)
* When finished, use 'make clean' to remove all object files and executables, leaving the non-compiled code
```
~/Downloads/programming2/lab02_basicStackTester: make 
~/Downloads/programming2/lab02_basicStackTester: ./lab02 -p
...output...
~/Downloads/programming2/lab02_basicStackTester: make clean
```
* Using a different compiler may require manual compilation.
* Combining all *.cpp *.h files into an executable should work for almost all labs
* A manual compilation of lab 06 requires specific instructions to function as intended. See lab 06 README for details
 

## Built With
* [Vim](https://www.vim.org/download.php) - Text editor used
* [GNU Compiler Collection - GCC](https://gcc.gnu.org/) - C++ compiler used. 
* [Valgrind](https://valgrind.org/) - Used for memory leak detection
* [GNU Debugger - gdb](https://www.gnu.org/savannah-checkouts/gnu/gdb/index.html) - For quick debugging done in terminal. 
* [DDD Debugger](https://www.gnu.org/software/ddd/) - For occasional debugging with graphical tool. Runs several debuggers under the hood, including gdb. 

## Authors

* **Jack Gould** - *Initial work* - [JackNGould](https://github.com/JackNGould)

## Contributors

* **University of Kansas Engineering Department** - Lab instructions, sample code, the enriching of my mind.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* My Professor - Dr. J G
