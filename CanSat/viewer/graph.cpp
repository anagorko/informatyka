#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "graph.h"
#include "../spectrogram.h"
#include <string>
#include <sstream>
void Graph::draw(Spectrogram s, ALLEGRO_DISPLAY * display) const {

    al_draw_rectangle(position_x, position_y, position_x + width, position_y + height, al_map_rgb(255,255,255), frame_thickness);

    float x1 = position_x + frame_thickness;
    
    
    for(int i=0;i< Spectrogram::resolution;i++){

        float y1;
        float x2;
        float y2;
        float value;
        for(int j=0;j<V.size();j++){
            switch(typeShow){
                case 0://absolute
                    value = V[j].lfl[i];
                    y1 = (position_y + height - frame_thickness) - (value * (height - 2 * frame_thickness))/range;
                    x2 = x1 + column_thickness;
                    y2 = position_y + height - frame_thickness;
                    if(y1 < position_y) y1 = (position_y + height - frame_thickness) - (height - 2 * frame_thickness) ; 
                   
                    al_draw_filled_rectangle(x1, y1, x2, y2,al_map_rgb(23,255,100));
                    x1 = x2;
                    break;  
                case 1://diffrent
                    value = V[j].lfl[i] - basis.lfl[i];
                    y1 = (position_y + height / 2 - frame_thickness) - (value * (height / 2 - 2 * frame_thickness))/range;
                    x2 = x1 + column_thickness;
                    y2 = position_y + height / 2 - frame_thickness;
                    
                    if ( y1 < position_y) y1 = (position_y + height / 2 - frame_thickness) - (height / 2 - 2 * frame_thickness);
                    if ( y1 > position_y + height) y1 = position_y + height;
                    
                    al_draw_filled_rectangle(x1, y1, x2, y2,al_map_rgb(23,255,100));
                    x1 = x2;
                    break;
                case 2://percent TODO
                    value = V[j].lfl[i] - basis.lfl[i];
                    y1 = (position_y + height / 2 - frame_thickness) - (value * (height / 2 - 2 * frame_thickness))/range;
                    x2 = x1 + column_thickness;
                    y2 = position_y + height / 2 - frame_thickness;

                    if ( y1 < position_y) y1 = (position_y + height / 2 - frame_thickness) - (height / 2 - 2 * frame_thickness);
                    if ( y1 > position_y + height) y1 = position_y + height;
                    
                    al_draw_filled_rectangle(x1, y1, x2, y2,al_map_rgb(23,255,100));
                    x1 = x2;
                    break;
            }
        }

        float stick_y1 = position_y;
        float stick_y2 = position_y + height;
        al_draw_line(position_x + width + 10, stick_y1, position_x + width + 10, stick_y2, al_map_rgb(255, 255, 255), 2);  

        stringstream ss;
        ss.str("");
        ss << (int)range;
        al_draw_text(font, al_map_rgb(255,100,100),position_x + width + 2 * frame_thickness + 10, stick_y1 - 20, 0, ss.str().c_str());

        ss.str("");
        ss << "0";
        al_draw_text(font, al_map_rgb(255,100,100),position_x + width + 2 * frame_thickness + 10, stick_y2 - 20, 0, ss.str().c_str());

        ss.str("");
        ss << (int)(range/2);
        al_draw_text(font, al_map_rgb(255,100,100),position_x + width + 2 * frame_thickness + 10, stick_y1 + ( stick_y2 - stick_y1) /2, 0, ss.str().c_str());

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
    cursorAbove = false;
    range = 1023;
}
void Graph::mouseMoved(float x, float y, int z){
    if(x > position_x && x < position_x + width
    && y > position_y && y < position_y + height){
        cursorAbove = true;
        //cout<<"mouse wheel = " << z<<endl;
        range += 1.0 * z;
    } else {
        cursorAbove = false;
    }
}

ALLEGRO_FONT * Graph::font;


