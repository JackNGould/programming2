lab08: main.o executive.o Sorts.h SortTimer.h
	g++ -std=c++11 -g -Wall main.o executive.o -o lab08

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

clean:
	rm *.o lab08
