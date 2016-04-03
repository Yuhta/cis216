CC := gcc
CFLAGS := -std=c99 -Wall -Wextra

sort: sortmain.o swap.o sort.o arrayutils.o
sortmain.o sort.o arrayutils.o swap.o: sort.h

clean:			# this is optional, how to clean up when everything is perfect
	rm *.o		#  you don't need to keep the object files, for instance
