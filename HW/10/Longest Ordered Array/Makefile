GCC = g++
CFLAGS = -Wall
OBJ = LIS.o

all: LIS
	./LIS

LIS: $(OBJ)
	$(GCC) $(CFLAGS) -o LIS $(OBJ)

LIS.o: LIS.cpp  

clean: 
	rm -f LIS *.o