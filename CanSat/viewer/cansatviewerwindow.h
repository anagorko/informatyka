#ifndef __CANSATVIEWERWINDOW__
#define __CANSATVIEWERWINDOW__

#include <math.h>
#include <time.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#include "../spectrogram.h"
#include "../datastore/datastore.h"
#include "config.h"
#include "button.h"
#include "graph.h"
#include "timeline.h"

class CanSatViewerWindow
{
 	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	vector <Button *> buttons;

	Graph spectrograf;
	TimeLine timeline;
   	bool przerysuj = true;
   	bool wyjdz = false;
	bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze   

	time_t rawtime;
        struct tm * timeinfo;


    	Button* btnExit;
    	Button* btnStop;
    	Button* btnPlay;

	Datastore data;

	stringstream ss;
   	Spectrogram S;

	Spectrogram getSpectrogram(int m) {
		cout << "read " << m << endl;
		return data.readClosest(m);
	}

public:
	CanSatViewerWindow();
	~CanSatViewerWindow();

	int init();

	void draw();
	void parseData(string line);
	void serialRead(int fd);
	void loop(int fd);
};

#endif /* __CANSATVIEWERWINDOW__ */

