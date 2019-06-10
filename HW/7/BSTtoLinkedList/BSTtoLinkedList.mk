GCC = g++
CFLAGS = -Wall
OBJ = BSTtoLinkedList.o

all: BSTtoLinkedList
	./BSTtoLinkedList

BSTtoLinkedList: $(OBJ)
	$(GCC) $(CFLAGS) -o BSTtoLinkedList $(OBJ)

BSTtoLinkedList.o: BSTtoLinkedList.cpp 

clean: 
	rm -f BSTtoLinkedList *.o