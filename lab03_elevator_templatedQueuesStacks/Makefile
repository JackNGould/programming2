lab03: main.o BuildingExecutive.o 
	g++ -std=c++11 -g -Wall main.o BuildingExecutive.o -o lab03

main.o: main.cpp Stack.h Queue.h Node.h PreconditionViolationException.h 
	g++ -std=c++11 -g -Wall -c main.cpp

BuildingExecutive.o: BuildingExecutive.cpp BuildingExecutive.h
	g++ -std=c++11 -g -Wall -c BuildingExecutive.cpp

clean:
	rm *.o lab03
