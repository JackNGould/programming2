# LAB 08
 In this program I implement a variety of sorting algorithms, and compare their speed at sorting large arrays.
 * Program takes args at command line to determine which sort to run with what data.
 * Times the sort and writes the results to an output file specified in args.

## New Topics:
  * Sorting algorithms
  * Time.h - to time sorts
  * functional library - functions as parameters of functions

## Input:
### Command line arguments
ARGS USAGE
```
./lab08 <sortType> <lowerBound> <upperBound> <step> <outputFile> <assert>
```
    * sortType - valid sorts are bubble, selection, insertion, merge, quick, quickWithMedian. 
    * lowerBound - integer representing lower bound of array sizes to generate for sort speed testing
    * upperBound - integer representing upper bound of array sizes to generate for sort speed testing
    * step - integer representing the step size between the two bounds. Must evenly travese bounds or an exception will be thrown.
    * outputFile - name of output file to write sort data to. column 1 is array size, column 2 is time taken to sort.
    * assert - write 'assert' as last argument to run in assert mode, which will also recursively check each array after sorting to confirm that it is indeed sorted correctly.
      * assert check occurs after timing, does not impact time results.
      * Leave blank to run without assert testing. Will improve speed for large arrays

### Example usage:
```
    ./lab08 selection 1000 10000 100 selectionTime.txt
    ./lab08 merge 1000 10000 100 mergeTime.txt
    ./lab08 bubble 100 1000 10 bubbleTime.txt assert
```

## My Results
A PDF file, entitled lab08Writeup.pdf is included in this labs directory. It displays a graph matching a large sample run for each of the 6 sorts. 
  * Each sort was run with a lower bound of 10000, an upper bound of 100000, and a step of 1000
    * Consequently, each sort was run a total of 91 times.(10000,11000,12000...98000,99000,100000)
  * Assert was NOT run. Assert simply checks the array after sorting it to see if it was sorted correctly.
    * With many large arrays to sort, this needlessly wastes a lot of time.
### Execution
WARNING - Sorting 91 arrays of nontrivial size will take some time, particularly for the iterative sorts(bubble, selection, and insertion).
* To Generate a large time data file for each sort:
```
./lab08 bubble 10000 100000 1000 bubbleTime.txt
./lab08 selection 10000 100000 1000 selectionTime.txt
./lab08 insertion 10000 100000 1000 insertionTime.txt
./lab08 merge 10000 100000 1000 mergeTime.txt
./lab08 quick 10000 100000 1000 quickTime.txt
./lab08 quickWithMedian 10000 100000 1000 quickWithMedian.txt
```

