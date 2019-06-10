GCC = g++
CFLAGS = -Wall
OBJ = testHashTable.o hashTable.o 

all: hashTable
	./hashTable

hashTable: $(OBJ)
	$(GCC) $(CFLAGS) -o hashTable $(OBJ)

hashTable.o: testHashTable.cpp hashTable.cpp hashTable.h  

clean: 
	rm -f hashTable *.o