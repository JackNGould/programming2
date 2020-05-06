lab05: main.o Executive.o Browser.o 
	g++ -std=c++11 -g -Wall main.o Browser.o Executive.o -o lab05

main.o: main.cpp 
	g++ -std=c++11 -g -Wall -c main.cpp

Browser.o: Browser.cpp Browser.h 
	g++ -std=c++11 -g -Wall -c Browser.cpp 

Executive.o: Executive.cpp Executive.h 
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab05
