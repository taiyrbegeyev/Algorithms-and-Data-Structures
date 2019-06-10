CC = g++
CFLAGS = -Wall

all: heapSort
	./heapSort

heapSort: heapSort.o
	$(CC) $(CFLAGS) -o heapSort  heapSort.o

heapSort.o: heapSort.cpp 
	$(CC) $(CFLAGS) -c heapSort.cpp

clean:
	rm -f *.o heapSort