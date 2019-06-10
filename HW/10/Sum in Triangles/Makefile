GCC = g++
CFLAGS = -Wall
OBJ = sum.o

all: sum
	./sum

sum: $(OBJ)
	$(GCC) $(CFLAGS) -o sum $(OBJ)

sum.o: sum.cpp  

clean: 
	rm -f sum *.o   