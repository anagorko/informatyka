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
	ALLEGRO_BITMAP *background = NULL;

	vector <Button *> buttons;

	Graph graph;
	GraphData gd;
	TimeLine timeline;
	Datastore data;

   	bool przerysuj = true;
   	bool wyjdz = false;
	bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze   
	bool timeRun = false;

    	Button* btnExit;
    	Button* btnStop;
    	Button* btnPlay;

    	Button* btnAbsolute;
    	Button* btnDiffrent;
    	Button* btnPercent;
    	Button* btnSet;
    	Button* btnAdd;
    	Button* btnClear;
    	Button* btnLive;
	Button* btnSetReference;

	Button *btnNextMoment, *btnPrevMoment;
	Button *btnChlor;

public:
	CanSatViewerWindow();
	~CanSatViewerWindow();
	int init();
	void draw();
	void parseData(string line);
	void loop(int fd);
	void serialRead(int fd);
};

#endif /* __CANSATVIEWERWINDOW__ */

