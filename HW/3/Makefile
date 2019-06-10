CC = g++
CFLAG = -Wall
OBJ = fibonacciNumbers.o useFibonacciNumbers.o

all: fibonacciNumbers
	./fibonacciNumbers

fibonacciNumbers: $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o fibonacciNumbers 

fibonacciNumbers.o: fibonacciNumbers.cpp fibonacciNumbers.h
	$(CC) $(CFLAG) -c fibonacciNumbers.cpp

useFibonacciNumbers.o: useFibonacciNumbers.cpp fibonacciNumbers.h
	$(CC) $(CFLAG) -c useFibonacciNumbers.cpp

clean:
	rm -f fibonacciNumbers *.o
