# Makefile for RBT
GCC = g++
CFLAGS = -Wall
OBJ = testRBT.o RBT.o 

all: RBT
	./RBT

RBT: $(OBJ)
	$(GCC) $(CFLAGS) -o RBT $(OBJ)

RBT.o: testRBT.cpp RBT.cpp RBT.h  

clean: 
	rm -f RBT *.o