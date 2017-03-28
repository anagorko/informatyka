#ifndef __TIMELINE__
#define __TIMELINE__


class TimeLine {

    float width, height;
    float position_x, position_y;
    bool pressed, cursor_above;
    float px, py;
public:
    float moment;
    float range;

    TimeLine();
    void draw(ALLEGRO_DISPLAY * display) const;

    void mousePressed(float x, float y);
    void mouseReleased();
	void mouseMoved(float x, float y);

	bool isPressed() { return pressed; }
};

#endif /* __TIMELINE__ */

