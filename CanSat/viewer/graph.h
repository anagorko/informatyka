#ifndef __GRAPH__
#define __GRAPH__

#include "spectrum.h"

class Graph {

    float width, height;
    float position_x, position_y;

    float frame_thickness;
    float column_thickness;
public:
    Graph();
    void draw(Spectrum s, ALLEGRO_DISPLAY * display) const;
};

#endif /* __GRAPH__ */

