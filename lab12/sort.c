#include "sort.h"

/*	
	The goal here is to sort the array, by any method you like, 
	either ascending or descending.
	
*/

void sort ( int * a, int  length)	
{	
  for (int i=1; i< length; i+=2) {
    // 			this just swaps pairs of elements
    if (a[i-1]>a[i]) swap(a+i-1, a+i);
  }  
}
/*	Post-condition should be:
 * 	where  0 <= i < j < length,
 * 	a[i] <= a[j]
*/