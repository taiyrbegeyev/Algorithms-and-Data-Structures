# Makefile for Queue
GCC = g++
CFLAGS = -Wall
OBJ = testQueue.o Queue.o 

all: Queue
	./Queue

Queue: $(OBJ)
	$(GCC) $(CFLAGS) -o Queue $(OBJ)

Queue.o: testQueue.cpp Queue.cpp Queue.h  

clean: 
	rm -f Queue *.o