#include <allegro5/allegro_primitives.h>
#include "timeline.h"
#include "config.h"
#include <iostream>
using namespace std;

void TimeLine::draw(ALLEGRO_DISPLAY * display) const {

    //float color_red = 0;
    //float color_green = 0;
    //float color_blue = 0;
    if(cursor_above){
        float color_red = 10;
        float color_green = 10;
        float color_blue = 10;
        if(pressed){
            color_red = (int)(color_red + 10) % 256;
            color_green = (int)(color_green + 10) % 256;
            color_blue = (int)(color_blue + 10) % 256;
        }
        al_draw_filled_rounded_rectangle(position_x,position_y,position_x + width, position_y + height, 5 , 5, al_map_rgb(color_red,color_green,color_blue));
    }

    float x1 = position_x + width / 2;
    float y1 = position_y;
    float x2 = position_x + width / 2;
    float y2 = position_y + height;

    int count_separators = 2;
    float distance = 0;
    
    al_draw_line(x1, y1, x2, y2, al_map_rgb(200, 0, 0), 1);
    distance += width / (count_separators * 2);
    
    for(int i=0;i<count_separators;i++){
        al_draw_line(x1 + distance, y1, x2 + distance, y2, al_map_rgb(22, 130, 70), 2);
        al_draw_line(x1 - distance, y1, x2 - distance, y2, al_map_rgb(22, 130, 70), 3);
        distance += width / (count_separators * 2);        
    }

  
}

TimeLine::TimeLine() {
    width = viewer_width * ((float)90/(float)100);
    height = viewer_height * ((float)10/(float)100);
    position_x = (viewer_width - width)/2;
    position_y = 600;
    moment = 0;
    range = 10;
    cursor_above = false;
    pressed = false;
}
void TimeLine::mouseMoved(float x, float y){
    if(x > position_x && x < position_x + width
    && y > position_y && y < position_y + height){
        cursor_above = true;
    } else {
        cursor_above = false;
    }
}
void TimeLine::mousePressed(float x, float y){
    if( x > position_x && x < position_x + width
    &&  y > position_y && y < position_y + height){
        
        pressed = true;
        px = x;
        py = y;

        cout << "timeline" << " pressed" << endl;
    }
}
void TimeLine::mouseReleased(){
    if(pressed){
        pressed = false;
    }
}
