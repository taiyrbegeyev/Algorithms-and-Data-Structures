CC = g++
CFLAG = -Wall
OBJ = ModifiedQuickSort.o

all: ModifiedQuickSort
	./ModifiedQuickSort

ModifiedQuickSort: $(OBJ)
	$(CC) $(CFLAG) -o ModifiedQuickSort $(OBJ)
ModifiedQuickSort.o: ModifiedQuickSort.cpp
clean:
	rm *.o ModifiedQuickSort
