#ifndef __BUTTON__
#define __BUTTON__

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
using namespace std;

#include "spectrum.h"

class Button{
    float position_x, position_y;
    float width, height;
    string inscription;
    float px, py;//last pressed position
    bool pressed;

	static ALLEGRO_FONT * font;

public:
	static void loadFont() {
    	font = al_load_ttf_font("FreeMono.ttf", 30, 12);		
	}

    Button(int _x, int _y, string s);
    void calculate_pressed(int cursor_x, int cursor_y);
    void calculate_released();//TODO WHAT TO DO?
    void draw(ALLEGRO_DISPLAY * display);
};

#endif /* __BUTTON__ */

