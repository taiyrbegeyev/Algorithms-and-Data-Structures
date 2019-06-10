CC = g++
CFLAG = -Wall
OBJ = ModifiedQuickSortRandomized.o

all: ModifiedQuickSortRandomized
	./ModifiedQuickSortRandomized

ModifiedQuickSortRandomized: $(OBJ)
	$(CC) $(CFLAG) -o ModifiedQuickSortRandomized $(OBJ)
ModifiedQuickSortRandomized.o: ModifiedQuickSortRandomized.cpp
clean:
	rm *.o ModifiedQuickSortRandomized
