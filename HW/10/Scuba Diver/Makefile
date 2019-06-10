GCC = g++
CFLAGS = -Wall
OBJ = scubaDiver.o

all: scubaDiver
	./scubaDiver

scubaDiver: $(OBJ)
	$(GCC) $(CFLAGS) -o scubaDiver $(OBJ)

scubaDiver.o: scubaDiver.cpp  

clean: 
	rm -f scubaDiver *.o   