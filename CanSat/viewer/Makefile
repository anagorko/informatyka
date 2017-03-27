all: cansat_viewer
	# Done
cansat_viewer: button.o cansat_viewer.o graph.o timeline.o
	g++ button.o cansat_viewer.o graph.o timeline.o -o cansat_viewer  -I/usr/local/include/ -L/usr/local/lib -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf
button.o: button.cpp button.h config.h
	g++ -Wall -c button.cpp -I/usr/local/include/
cansat_viewer.o: cansat_viewer.cpp config.h cansatviewerwindow.h 
	g++ -Wall -c cansat_viewer.cpp -I/usr/local/include/
graph.o: graph.cpp graph.h config.h
	g++ -Wall -c graph.cpp -I/usr/local/include/
timeline.o: timeline.cpp timeline.h config.h
	g++ -Wall -c timeline.cpp -I/usr/local/include/
