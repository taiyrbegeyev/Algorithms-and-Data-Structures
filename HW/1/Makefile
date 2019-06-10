CC = g++
CFLAG = -Wall
OBJ = selectionSort.o
all: selectionSort 
	 ./selectionSort
selectionSort: $(OBJ) 
			   $(CC) $(CFLAG) -o selectionSort $(OBJ)

selectionSort.o: selectionSort.cpp
clean: 
	 rm -f selectionSort *.o