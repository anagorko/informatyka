#ifndef __GRAPH__
#define __GRAPH__

#include "../spectrogram.h"
#include <vector>

class Graph {

    float width, height;
    float position_x, position_y;

    float frame_thickness;
    float column_thickness;
    vector <Spectrogram> V;
    int typeShow;
public:
    Graph();
    void draw(Spectrogram s, ALLEGRO_DISPLAY * display) const;
    void addSpec(Spectrogram s) { V.push_back(s); }
    void setShow(int d) { typeShow = d; };
};

#endif /* __GRAPH__ */

