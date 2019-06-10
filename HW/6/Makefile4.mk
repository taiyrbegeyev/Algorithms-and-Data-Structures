CC = g++
CFLAGS = -Wall
OBJ = RadixSort.o

all: RadixSort
	./RadixSort

CountingSort: $(OBJ)
	$(CC) $(CFLAGS) -o RadixSort $(OBJ)
CountingSort.o: RadixSort.cpp
clean:
	rm -f RadixSort *.o