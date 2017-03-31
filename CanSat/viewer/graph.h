#ifndef __GRAPH__
#define __GRAPH__

#include "../spectrogram.h"
#include <vector>

class Graph {

    float width, height;
    float position_x, position_y;

    float frame_thickness;
    float column_thickness;
    Spectrogram basis;
    vector <Spectrogram> V;
    int typeShow;
public:
    Graph();
    void draw(Spectrogram s, ALLEGRO_DISPLAY * display) const;
    void addSpec(Spectrogram s) { V.push_back(s); }
    void setBasis(Spectrogram s) { basis = s; }
    void setShow(int d) { typeShow = d; };
    void clearSet() { V.clear(); }
};

#endif /* __GRAPH__ */

