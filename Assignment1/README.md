# Design and Analysis of Algorithms Assignment 1

## Problem Statement

Implement Selection Sort, Bubble Sort, Quick Sort and Merge sort to sort numbers in non-decreasing order. Run these functions large number of times for arrays of different sizes (n) (100k, 150k, 200k up to 1000k).Use random number generator to generate arrays elements.
Generate two files as output of each sorting function
File1: Size of list Vs no of element to element comparisons
File2: Size of list Vs execution time

Generate two plots for comparative empirical analysis of different sorting algorithms (you can use XGRAPH tool for Linux)
Plot1: Size Vs no of comparisons
Plot2: Size Vs execution time
Implementation should consists of three files :

1. Header file (function prototypes)
2. Implementation File (function definitions)
3. Client file (Driver function)
   Assignment folder should contain implementation files, output files and graphs

Note: Use C Language for implementation

## Compiling and Execution

To compile the code, execute the following command in terminal

```bash
$ make
```

This will generate object files for executing the code.

Note : Compiling the code requires `gcc` to be installed locally. Also, the code will be compiled using gcc's Optimization Level 3 (-O3) to give a descent speed up in execution time.

To run the code, type `./a.out` command in terminal.

This will take approximately 3.5 hours to complete. If compiled without `gcc` optimizations, the execution time will increase to 5 - 6 hours.
