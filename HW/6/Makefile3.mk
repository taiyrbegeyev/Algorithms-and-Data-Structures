CC = g++
CFLAGS = -Wall
OBJ = SortWords.o

all: SortWords
	./SortWords

CountingSort: $(OBJ)
	$(CC) $(CFLAGS) -o SortWords $(OBJ)
CountingSort.o: SortWords.cpp
clean:
	rm -f SortWords *.o