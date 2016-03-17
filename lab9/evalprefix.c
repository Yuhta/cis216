/*# Start of file evalprefix.c */
/*  write a function to evaluate a prefix arithmetic expression
	int preval(FILE *)
    You may call 
        int gettoken(FILE *)
	(passing it the same file argument)	
    Example input:
        ++42 3 - 5 1
	+-1++1000	#invalid, not enough numbers
*/
/*# Output format must be:		*/
/*# "Evaluates to 95"		*/
#include <stdio.h>       /* for printf in C programs */
#include <stdlib.h>	 /* for exit() in C programs */



#define	LEN 30
char  testing[] = "+42+55-6 8" ;

/*   gettoken for arithmetic expression. 
 * 	Only recognize + - * / ( ) and digits.
  * 	Any other character ignored, such as space, must be used to separate consecutive numbers
 * 	EXIT on end of line or string
 *   Return value:
 * 	1. non-negative integer  OR
 * 	2. negative of single character token
 * 	   uses fgetc, ungetc file functions, for stdin, or fmemopen for strings in memory
*/
#define   isdigit(ch)  ch >= '0' && ch <= '9'

int gettoken (FILE * f) {
    int sum = 0;
  while(1) {
    char ch = fgetc(f);		// first unprocessed char
    if (isdigit(ch))
    {	sum = ch&0xF;		// start of number
	ch = fgetc(f);
        while (isdigit(ch))
	  {  sum = sum*10 + (ch&0xF);
	     ch = fgetc(f);
	  }
	ungetc (ch, f);      // finished number, do not consume non-numeral
	return sum;
    }
    else if (ch=='+'||ch=='-'||ch=='*'||ch=='/')
      return -ch;		// found an operator
    else if (ch==0 || ch=='\n')	// no more characters
    {	puts("--no more input--"); 
	exit(0);	
    }
  } 	// end while. Ignoring space or other chars.
}

int preval(FILE *f);
FILE *fmemopen(void*,size_t,const char*); // needed for c99

int main() {
//  FILE * membuf = fmemopen(testing, LEN,"r");  // will be used by mipsmark
    puts("Enter a prefix arithmetic expression:");
   printf ("Evaluates to %d\n", preval(stdin));
  return 0;
}

/* Any changes above this line will be discarded by
# mipsmark. Put your answer between dashed lines. */
/*-------------- start cut ----------------------- */

/*  Student's Name:				*/

int
preval (FILE * f)
{
  int op = gettoken (f); // get first token
  if (op >= 0) return op; // if it's a number, return the number
  int x = preval (f); // evaluate first operant
  int y = preval (f); // evaluate second operant
  switch (-op) // do the calculation
    {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    }
  printf ("Invalid operator: %c\n", -op); // print error message
  exit (0); // exit with code 0
  return 0;
}

/*--------------  end cut  -----------------------
# Any changes below this line will be discarded by
# mipsmark. Put your answer between dashed lines.
/*# End of file evalprefix.c		*/
