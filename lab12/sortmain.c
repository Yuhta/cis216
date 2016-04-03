#include "sort.h"
#include <time.h>

#define	LENGTH	15
		// suit yourself

int main(){
  int a[LENGTH];
  // COMMENT THIS OUT TO ALWAYS GET THE SAME VALUES
  srand(time(NULL));		// set seed for rand with unix time,
				//otherwise same sequence each run
  printf("First random number is %d\n", rand() );
  fillarray (a, LENGTH);		// fill the arrray randomly
  printarray(a, LENGTH);		// show initial array
  sort (a, LENGTH);			// sort it
  printarray(a, LENGTH);		// show final array
return 0;}