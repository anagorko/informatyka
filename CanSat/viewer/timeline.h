#ifndef __TIMELINE__
#define __TIMELINE__


class TimeLine {

    float width, height;
    float position_x, position_y;
public:
    float moment;
    float range;

    TimeLine();
    void draw(ALLEGRO_DISPLAY * display) const;
    void mousePressed(float x, float y);
};

#endif /* __TIMELINE__ */

