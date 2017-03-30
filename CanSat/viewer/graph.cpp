#include <allegro5/allegro_primitives.h>
#include "graph.h"

void Graph::draw(Spectrogram s, ALLEGRO_DISPLAY * display) const {

    al_draw_rectangle(position_x, position_y, position_x + width, position_y + height, al_map_rgb(255,255,255), frame_thickness);

    float x1 = position_x + frame_thickness;
    
    
    for(int i=0;i< Spectrogram::resolution;i++){
        switch(typeShow){
            case 0:
                float y1 = (position_y + height - frame_thickness) - (s.lfl[i] * (height - 2 * frame_thickness))/1023;
                float x2 = x1 + column_thickness;
                float y2 = position_y + height - frame_thickness;
                al_draw_filled_rectangle(x1, y1, x2, y2,al_map_rgb(23,255,100));
                x1 = x2;
                break;
        
        }
    }

}

Graph::Graph() {
    width = 700;
    height = 500;
    position_x = 40;
    position_y = 30;
    frame_thickness = 3;
    column_thickness = (width - 2 * frame_thickness)/Spectrogram::resolution;
    typeShow = 0;
}


