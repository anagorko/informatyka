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
   	Spectrogram S;
	bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze   

	time_t rawtime;
        struct tm * timeinfo;


	Spectrogram getSpectrogram(int m) {
		return S;
	}

    	Button* btnExit;
    	Button* btnStop;
    	Button* btnPlay;

	stringstream ss;

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

