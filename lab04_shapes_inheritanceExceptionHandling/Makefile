lab04: main.o Executive.o Circle.o Rectangle.o Triangle.o ShapeContainer.o 
	g++ -std=c++11 -g -Wall main.o Executive.o Circle.o Rectangle.o Triangle.o ShapeContainer.o -o lab04

main.o: main.cpp Shape.h Node.h Node.cpp Queue.h Queue.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Circle.o: Circle.cpp Circle.h
	g++ -std=c++11 -g -Wall -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -std=c++11 -g -Wall -c Rectangle.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ -std=c++11 -g -Wall -c Triangle.cpp

ShapeContainer.o: ShapeContainer.cpp ShapeContainer.h
	g++ -std=c++11 -g -Wall -c ShapeContainer.cpp

clean:
	rm *.o lab04

