GCC = g++
CFLAGS = -Wall
OBJ = PuzzleBoard.o

all: numberMaze
	./numberMaze

numberMaze: $(OBJ)
	$(GCC) $(CFLAGS) -o numberMaze $(OBJ)

PuzzleBoard.o: PuzzleBoard.cpp PuzzleBoard.h

clean: 
	rm -f numberMaze *.o