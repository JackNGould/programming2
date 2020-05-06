lab10: main.o patient.o executive.o 
	g++ -std=c++11 -g -Wall main.o executive.o patient.o -o lab10

executive.o: executive.cpp executive.h
	g++ -std=c++11 -g -Wall -c executive.cpp

patient.o: patient.cpp patient.h
	g++ -std=c++11 -g -Wall -c patient.cpp

main.o: main.cpp MaxHeap.h MaxHeapInterface.h Queue.h Node.h
	g++ -std=c++11 -g -Wall -c main.cpp

clean:
	rm *.o lab10
