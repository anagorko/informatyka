all: recorder import
	# Done
recorder: recorder.o serial.o
	g++ -g -o recorder recorder.o serial.o
recorder.o: recorder.cpp
	g++ -Wall -c -std=c++11 recorder.cpp
serial.o: serial.cpp serial.h
	g++ -Wall -c -std=c++11 serial.cpp
import: import.o datastore.o
	g++ -g -o import import.o datastore.o -lsqlite3
import.o: import.cpp
	g++ -c -Wall -std=c++11 import.cpp
datastore.o: ../datastore/datastore.cpp ../datastore/datastore.h
	g++ -g -c -Wall -std=c++11 ../datastore/datastore.cpp
clean:
	rm *.o recorder import
