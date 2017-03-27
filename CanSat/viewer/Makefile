all: cansat_viewer
	# Done
cansat_viewer: button.o cansat_viewer.o graph.o
	g++ button.o cansat_viewer.o graph.o -o cansat_viewer  -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf
button.o: button.cpp button.h config.h
	g++ -Wall -c button.cpp
cansat_viewer.o: cansat_viewer.cpp config.h cansatviewerwindow.h
	g++ -Wall -c cansat_viewer.cpp
graph.o: graph.cpp graph.h config.h
	g++ -Wall -c graph.cpp
