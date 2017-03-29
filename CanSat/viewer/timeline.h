#ifndef __TIMELINE__
#define __TIMELINE__

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
using namespace std;


class TimeLine {

    float width, height;
    float position_x, position_y;
    bool pressed, cursor_above;
    float px, py, pmoment;

    static ALLEGRO_FONT * font;

public:
    float moment;
    float range;
    bool timeRun;


    TimeLine();

    static void loadFont() {
        font = al_load_ttf_font("FreeMono.ttf", 25, 15);        
    }
    void draw(ALLEGRO_DISPLAY * display) const;

    void mousePressed(float x, float y);
    void mouseReleased();
	void mouseMoved(float x, float y);

	bool isPressed() { return pressed; }
};

#endif /* __TIMELINE__ */

