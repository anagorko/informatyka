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
    bool cursorAbove, live;

    float range;

    static ALLEGRO_FONT * font;

public:
    Graph();

    void mouseMoved(float x, float y, int z);

    void draw(ALLEGRO_DISPLAY * display) const;

    void addSpec(Spectrogram s) { V.push_back(s); }
    int countSpec() { return V.size(); }
    void changeSpec(int d, Spectrogram s);
    void changeLive() { live = (live == true)? false : true; }
    bool isLive() { return live; }
    void setBasis(Spectrogram s) { basis = s; }
    void setShow(int d) { typeShow = d; };
    void clearSet() { V.clear(); }
    static void loadFont() {
        font = al_load_ttf_font("FreeMono.ttf", 23, 15);        
    }
};

#endif /* __GRAPH__ */

