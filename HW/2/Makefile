CC = g++
CFLAG = -Wall
OBJ = mergeSort.o
all: mergeSort 
	 ./mergeSort
mergeSort: $(OBJ) 
		   $(CC) $(CFLAG) -o mergeSort $(OBJ)

mergeSort.o: mergeSort.cpp
clean: 
	 rm -f mergeSort *.o