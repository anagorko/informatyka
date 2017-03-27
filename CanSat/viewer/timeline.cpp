#include <allegro5/allegro_primitives.h>
#include "timeline.h"
#include "config.h"

void TimeLine::draw(ALLEGRO_DISPLAY * display) const {

    //al_draw_rectangle(position_x, position_y, position_x + width, position_y + height, al_map_rgb(255,255,255), 5);
    float x1 = position_x;
    float y1 = position_y;
    float x2 = position_x;
    float y2 = position_y + height;
    for(int i=0;i<5;i++){
        al_draw_line(x1, y1, x2, y2, al_map_rgb(22, 130, 70), 5);
        x1 += width/4;
        x2 += width/4;
    }

  
}

TimeLine::TimeLine() {
    width = viewer_width * ((float)90/(float)100);
    height = viewer_height * ((float)10/(float)100);
    position_x = (viewer_width - width)/2;
    position_y = 600;
    moment =0;
}
