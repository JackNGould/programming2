lab01: main.o dataManager.o game.o
	g++ -std=c++11 -g -Wall main.o dataManager.o game.o -o lab01

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

dataManager.o: dataManager.cpp dataManager.h
	g++ -std=c++11 -g -Wall -c dataManager.cpp

game.o: game.cpp game.h
	g++ -std=c++11 -g -Wall -c game.cpp

clean:
	rm *.o lab01
