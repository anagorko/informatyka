#ifndef __TIMELINE__
#define __TIMELINE__

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
using namespace std;

#include "../spectrogram.h"
#include "../datastore/datastore.h"

class TimeLine {

    float width, height;
    float position_x, position_y;
    bool pressed, cursor_above;
    float px, py;
    float range;

	int moment, left_m, right_m, pmoment;
	string tag;

    static ALLEGRO_FONT * font;

public:    
    	TimeLine();

    	static void loadFont() {
        	font = al_load_ttf_font("Inconsolata-Regular.ttf", 12, 0);        
    	}
    	void draw(ALLEGRO_DISPLAY * display) const;

    	void mousePressed(float x, float y, bool);
    	void mouseReleased();
	void mouseMoved(float x, float y, int z);

	void click(int _moment) { 
		moment = _moment; 
		tag = "";
	}
	void shiftClick(int m) {
		if (left_m >= 0 && right_m >= 0) {
			left_m = m; right_m = -1;
		} else if (left_m < 0 && right_m < 0) {
			left_m = m;
		} else if (left_m < 0) {
			left_m = m;
		} else {
			right_m = m;
		}
		if (left_m > right_m) {
			int tmp = left_m;
			left_m = right_m;
			right_m = tmp;
		}
		tag = "";

		cout << "shift click " << left_m << " " << right_m << endl;
	}
	void tagClick(string _tag) {
		tag = _tag;
	}
	void incMoment() {
		moment++;
	}

	int getMoment() const { return moment; }

	Spectrogram getSpectrogram(Datastore &data) {
cout<<"TAG "<<tag<<endl;
		if (tag != "") {
			return data.readTag(tag);			
		} else if (left_m < 0 || right_m < 0) {
			return data.readClosest(moment);
		} else {
			return data.readInterval(left_m, right_m);
		}
	}
	string getDescription() { return "Timeline::getDescription() TODO"; }

	bool isPressed() { return pressed; }
};

#endif /* __TIMELINE__ */
