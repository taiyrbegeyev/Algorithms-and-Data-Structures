CC = g++
CFLAGS = -Wall
OBJ = CountingSort.o

all: CountingSort
	./CountingSort

CountingSort: $(OBJ)
	$(CC) $(CFLAGS) -o CountingSort $(OBJ)
CountingSort.o: CountingSort.cpp
clean:
	rm -f CountingSort *.o