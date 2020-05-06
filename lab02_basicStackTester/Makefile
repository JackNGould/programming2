lab02: main.o Node.o StackOfChars.o StackTester.o Parser.o
	g++ -std=c++11 -g -Wall main.o Node.o StackTester.o StackOfChars.o Parser.o -o lab02

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp

StackOfChars.o: StackOfChars.cpp StackOfChars.h
	g++ -std=c++11 -g -Wall -c StackOfChars.cpp

StackTester.o: StackTester.cpp StackTester.h
	g++ -std=c++11 -g -Wall -c StackTester.cpp

Parser.o: Parser.cpp Parser.h
	g++ -std=c++11 -g -Wall -c Parser.cpp

clean:
	rm *.o lab02
