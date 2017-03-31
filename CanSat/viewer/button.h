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

	static ALLEGRO_FONT * font;

	bool isInside(float, float);

public:
    	Button(int _x, int _y, string s);

	static void loadFont() {
    		font = al_load_ttf_font("FreeMono.ttf", 20, 12);		
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

