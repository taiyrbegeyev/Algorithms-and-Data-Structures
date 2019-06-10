CC = g++
CFLAG = -Wall
OBJ = quickSort.o

all: quickSort
	./quickSort

quickSort: $(OBJ)
	$(CC) $(CFLAG) -o quickSort  $(OBJ)
quickSort.o: quickSort.cpp
clean:
	rm *.o quickSort
