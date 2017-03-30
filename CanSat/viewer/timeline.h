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

    float moment;
    float range;

    static ALLEGRO_FONT * font;

public:

    
    bool timeRun;


    TimeLine();

    static void loadFont() {
        font = al_load_ttf_font("FreeMono.ttf", 25, 15);        
    }
    void draw(ALLEGRO_DISPLAY * display) const;

    void mousePressed(float x, float y);
    void mouseReleased();
	void mouseMoved(float x, float y, int z);

    float getMoment() { return moment; }
    void setMoment(float a) { moment = a; }

    //void joystickMoved(int axis);
	bool isPressed() { return pressed; }
};

#endif /* __TIMELINE__ */

