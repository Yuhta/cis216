#include "sort.h"

/*	
	The goal here is to sort the array, by any method you like, 
	either ascending or descending.
	
*/

void sort ( int * a, int  length)	
{	
  for (int i = 0; i < length - 1; i++)
    for (int j = i + 1; j < length; j++)
      if (a[i] > a[j]) swap (a + i, a + j);
}
/*	Post-condition should be:
 * 	where  0 <= i < j < length,
 * 	a[i] <= a[j]
*/
