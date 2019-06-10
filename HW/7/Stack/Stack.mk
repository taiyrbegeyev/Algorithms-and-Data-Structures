# Makefile for Stack
GCC = g++
CFLAGS = -Wall
OBJ = testStack.o Stack.o 

all: Stack
	./Stack

Stack: $(OBJ)
	$(GCC) $(CFLAGS) -o Stack $(OBJ)

Stack.o: testStack.cpp Stack.cpp Stack.h  

clean: 
	rm -f Stack *.o