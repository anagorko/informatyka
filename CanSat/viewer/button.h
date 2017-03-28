#ifndef __BUTTON__
#define __BUTTON__

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
using namespace std;

#include "spectrogram.h"

class Button{
    float position_x, position_y;
    float width, height;
    string inscription;
    float px, py;//last pressed position
    bool pressed;

	static ALLEGRO_FONT * font;

public:
    Button(int _x, int _y, string s);

	static void loadFont() {
    	font = al_load_ttf_font("FreeMono.ttf", 30, 12);		
	}

    void draw(ALLEGRO_DISPLAY * display);

    void mousePressed(int x, int y);
    void mouseReleased();
	void mouseMoved(int x, int y);

	bool isPressed() { return pressed; }
};

#endif /* __BUTTON__ */

