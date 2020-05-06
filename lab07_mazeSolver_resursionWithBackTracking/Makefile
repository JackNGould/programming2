lab07: main.o MazeCreationException.h MazeReader.o MazeWalker.o
	g++ -std=c++11 -g -Wall main.o MazeReader.o MazeWalker.o -o lab07

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp


MazeWalker.o: MazeWalker.cpp MazeWalker.h
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

MazeReader.o: MazeReader.cpp MazeReader.h
	g++ -std=c++11 -g -Wall -c MazeReader.cpp

clean:
	rm *.o lab07
