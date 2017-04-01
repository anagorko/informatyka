#ifndef __BUTTON__
#define __BUTTON__

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
using namespace std;

#include "../spectrogram.h"

class Button{
    	float position_x, position_y;
    	float width, height;
    	string inscription;
    	float px, py;//last pressed position
    	bool pressed, released, cursor_above, with_text;
        bool activated;
        bool pressable, displayed;

	ALLEGRO_COLOR bg;

	bool isInside(float, float);

public:
	static ALLEGRO_FONT * font;

    	Button(int _x, int _y, string s);
	Button(int,int,string,int);
	Button(int,int,string,int, ALLEGRO_COLOR);
	Button(int,int,string,ALLEGRO_COLOR);

	static void loadFont() {
    		font = al_load_ttf_font("Inconsolata-Regular.ttf", 20, 12);		
	}

    	void draw(ALLEGRO_DISPLAY * display);

    	void mousePressed(float x, float y);
    	void mouseReleased();
	void mouseMoved(float x, float y);

	bool isPressed() { return pressed; }
    bool wasPressed();
    bool isActivated() { return activated; }
    void changeStatus() { activated = (isActivated())? false : true; }
};

#endif /* __BUTTON__ */

