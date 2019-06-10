GCC = g++
CFLAGS = -Wall
OBJ = ActivitySelectionProblem.o

all: ActivitySelectionProblem
	./ActivitySelectionProblem

ActivitySelectionProblem: $(OBJ)
	$(GCC) $(CFLAGS) -o ActivitySelectionProblem $(OBJ)

ActivitySelectionProblem.o: ActivitySelectionProblem.cpp  

clean: 
	rm -f ActivitySelectionProblem *.o