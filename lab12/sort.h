//	Header file for cs 216 array sort project 
#include <stdio.h>		// everyone might want to print...
#include <stdlib.h>
/* prototypes for the functions in various files
    prototypes don't need to name the arguments, 
    I have included some to suggest usage, but you can use whatever you want.
*/
//	In arrayutils.c
void fillarray (int * , int);	// name of an array, length -- fill with random numbers
void printarray(int * , int);	// name of an array, length -- print an array

//	In sort.c
void sort ( int * first, int length);	// array should be sorted (by student)

//	in swap.s, the usual swap 2 values, given their addresses, has been optimized
void swap (int* x, int * y);
