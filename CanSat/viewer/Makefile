all: cansat_viewer
	# Done
cansat_viewer: button.o cansat_viewer.o graph.o timeline.o serial.o cansatviewerwindow.o datastore.o
	g++ button.o cansat_viewer.o graph.o timeline.o serial.o cansatviewerwindow.o datastore.o -o cansat_viewer  -I/usr/local/include/ -L/usr/local/lib -lsqlite3 -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf
button.o: button.cpp button.h config.h
	g++ -Wall -c button.cpp -I/usr/local/include/
cansat_viewer.o: cansat_viewer.cpp config.h cansatviewerwindow.h 
	g++ -Wall -std=c++11 -c cansat_viewer.cpp -I/usr/local/include/
graph.o: graph.cpp graph.h config.h
	g++ -Wall -std=c++11 -c graph.cpp -I/usr/local/include/
timeline.o: timeline.cpp timeline.h config.h
	g++ -Wall -std=c++11 -c timeline.cpp -I/usr/local/include/
serial.o: ../ground_arduino/serial.cpp ../ground_arduino/serial.h
	g++ -Wall -std=c++11 -c ../ground_arduino/serial.cpp 
cansatviewerwindow.o: cansatviewerwindow.cpp cansatviewerwindow.h
	g++ -Wall -std=c++11 -c cansatviewerwindow.cpp
datastore.o: ../datastore/datastore.h ../datastore/datastore.cpp
	g++ -Wall -std=c++11 -c ../datastore/datastore.cpp
clean:
	rm *.o
	rm cansat_viewer

