# you are to complete this Makefile, then use it with make, when you want to test
	# goal is the executable file sort, it must come first

sort : sortmain.o 			# list all the .o files here
	gcc -o sort  			# and here
	
	# executable will be namend sort, run by typing:  ./sort
	
swap.o : swap.s			# (re)compile sources if necessary
	gcc -c swap.s			# -c means stop at the .o file stage

sortmain.o : sortmain.c sort.h
	gcc -std=c99 -c sortmain.c
	
#  and 2 more (at least)

clean:			# this is optional, how to clean up when everything is perfect
	rm *.o		#  you don't need to keep the object files, for instance
		# invoke this by typing:  make clean