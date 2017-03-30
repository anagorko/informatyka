#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "timeline.h"
#include "config.h"
#include <iostream>
#include <sstream>
using namespace std;

void TimeLine::draw(ALLEGRO_DISPLAY * display) const {

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

    float text_distance = 5;

    int count_separators = 2;
    float time_distance = range / count_separators;
    float distance = 0;
    stringstream ss;
    ss << (int)(moment/60);

    float pix_lenght = al_get_text_width(font, ss.str().c_str());
    al_draw_line(x1, y1, x2, y2, al_map_rgb(200, 0, 0), 1);
    al_draw_text(font, al_map_rgb(255,255,255),x1 - pix_lenght / 2, y2 + text_distance , 0, ss.str().c_str());

    distance += width / (count_separators * 2);
    
    for(int i=0;i<count_separators;i++){
        //po prawej stronie    
        al_draw_line(x1 + distance, y1, x2 + distance, y2, al_map_rgb(22, 130, 70), 2);

        ss.str("");
        ss << (int)(moment / 60 + time_distance * (i+1) / 60 );
        pix_lenght = al_get_text_width(font, ss.str().c_str());
        al_draw_text(font, al_map_rgb(255,255,255),x1 + distance- pix_lenght / 2, y2 + text_distance , 0, ss.str().c_str());
        //po lewej stronie
        al_draw_line(x1 - distance, y1, x2 - distance, y2, al_map_rgb(22, 130, 70), 3);

          
        ss.str("");
        ss << (int)(moment / 60 - (time_distance * (i+1)) / 60 );
        pix_lenght = al_get_text_width(font, ss.str().c_str());
        al_draw_text(font, al_map_rgb(255,255,255),x1 - distance- pix_lenght / 2, y2 + text_distance , 0, ss.str().c_str());  

        distance += width / (count_separators * 2);    
    }

  
}

TimeLine::TimeLine() {
    width = viewer_width * ((float)90/(float)100);
    height = viewer_height * ((float)10/(float)100);
    position_x = (viewer_width - width)/2;
    position_y = 600;
    moment = 0;
    pmoment = 0;
    range = 60*2;
    cursor_above = false;
    pressed = false;
    timeRun = true;
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
    if( !pressed && x > position_x && x < position_x + width
    &&  y > position_y && y < position_y + height){
        
        pressed = true;
        px = x;
        py = y;
        /*
        width/2 --------- range
        distance --------- X
        */
        float distance = (position_x + width / 2) - x;
        pmoment = moment - ( distance * range / (width/2));

        cout << "timeline" << " pressed"<< endl;
    }
}
void TimeLine::mouseReleased(){
    if(pressed){
        pressed = false;
        moment = pmoment;
    }
}

ALLEGRO_FONT * TimeLine::font;