GCC = g++
CFLAGS = -Wall
OBJ = omp.o

all: omp
	./omp

omp: $(OBJ)
	$(GCC) $(CFLAGS) -o omp $(OBJ)

omp.o: omp.cpp  

clean: 
	rm -f omp *.o   