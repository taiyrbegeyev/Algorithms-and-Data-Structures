CC = g++
CFLAGS = -Wall
OBJ = BucketSort.o

all: BucketSort
	./BucketSort

CountingSort: $(OBJ)
	$(CC) $(CFLAGS) -o BucketSort $(OBJ)
CountingSort.o: BucketSort.cpp
clean:
	rm -f BucketSort *.o