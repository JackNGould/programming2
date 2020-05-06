lab09: main.o pokemon.o executive.o treeTest.o
	g++ -std=c++11 -g -Wall main.o executive.o pokemon.o treeTest.o -o lab09

executive.o: executive.cpp executive.h
	g++ -std=c++11 -g -Wall -c executive.cpp

pokemon.o: pokemon.cpp pokemon.h
	g++ -std=c++11 -g -Wall -c pokemon.cpp

treeTest.o: treeTest.cpp treeTest.h
	g++ -std=c++11 -g -Wall -c treeTest.cpp

main.o: main.cpp jackException.h BST.h BSTinterface.h BNode.h Node.h Queue.h
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o lab09
