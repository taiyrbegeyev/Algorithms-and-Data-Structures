GCC = g++
CFLAGS = -Wall
OBJ = testLinkedListtoBST.o

all: testLinkedListtoBST
	./testLinkedListtoBST

testLinkedListtoBST: $(OBJ)
	$(GCC) $(CFLAGS) -o testLinkedListtoBST $(OBJ)

testLinkedListtoBST.o: testLinkedListtoBST.cpp 

clean: 
	rm -f testLinkedListtoBST *.o