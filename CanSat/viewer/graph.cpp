#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "graph.h"
#include "../spectrogram.h"
#include <string>
#include <sstream>
void Graph::draw(ALLEGRO_DISPLAY * display) const {

    al_draw_rectangle(position_x, position_y, position_x + width, position_y + height, al_map_rgb(255,255,255), frame_thickness);
    
    float x1 = position_x + frame_thickness;

    for(int i=0;i< Spectrogram::resolution;i++){

        
        for(int j=0;j<V.size();j++){
            if(live == false && j==0) continue;
            float y1;
            float value;
            float r = 3;
            switch(typeShow){
                case 0://absolute
                    value = V[j].lfl[i];
                    y1 = (position_y + height + frame_thickness) - (value * (height - 2 * frame_thickness))/range;

                    if(y1 < position_y + frame_thickness) y1 = (position_y + height - frame_thickness) - (height - 2 * frame_thickness);
                   
                    al_draw_filled_circle(x1, y1, r, al_map_rgb(23,255,100));
                    break;  
                case 1://diffrent
                    value = V[j].lfl[i] - basis.lfl[i];
                    y1 = (position_y + height / 2 - frame_thickness) - (value * (height / 2 - 2 * frame_thickness))/range;
                    
                    if ( y1 < position_y + frame_thickness) y1 = (position_y + height / 2 - frame_thickness) - (height / 2 - 2 * frame_thickness);
                    if ( y1 > position_y + height) y1 = position_y + height;
                    
                    al_draw_filled_circle(x1, y1, r, al_map_rgb(23,255,100));
                    break;
                case 2://percent TODO
                    value = V[j].lfl[i] - basis.lfl[i];
                    y1 = (position_y + height / 2 - frame_thickness) - (value * (height / 2 - 2 * frame_thickness))/range;

                    if ( y1 < position_y + frame_thickness) y1 = (position_y + height / 2 - frame_thickness) - (height / 2 - 2 * frame_thickness);
                    if ( y1 > position_y + height) y1 = position_y + height;
                    
                    al_draw_filled_circle(x1, y1, r, al_map_rgb(23,255,100));
                    break;
            }
             
        }
        x1 += column_thickness;
    }
    float stick_y1 = position_y;
    float stick_y2 = position_y + height;
    al_draw_line(position_x + width + 10, stick_y1, position_x + width + 10, stick_y2, al_map_rgb(255, 255, 255), 2);  


    stringstream ss;
    int font_height = al_get_font_line_height(font);
    float value=0;
    float stickLen = (stick_y2 - stick_y1)/((typeShow==0)? 1 : 2);
    
    for(int i=0;i<5;i++){
        switch(typeShow){
            case 0:
                ss.str("");
                ss << (int)value;
                al_draw_text(font, al_map_rgb(255,255,255),position_x + width + 2 * frame_thickness + 10, stick_y2 - (stickLen * value) / range - font_height /2, 0, ss.str().c_str());
                value += 1.0/4.0 * range;
                break;
            case 1:
                ss.str("");
                ss << (int)value;
                al_draw_text(font, al_map_rgb(255,255,255),position_x + width + 2 * frame_thickness + 10, stick_y1 + stickLen - (stickLen * value) / range - font_height /2, 0, ss.str().c_str());
                ss.str("");
                ss << "-" << (int)value;
                if(i!=0)
                al_draw_text(font, al_map_rgb(255,255,255),position_x + width + 2 * frame_thickness + 10, stick_y1 + stickLen + (stickLen * value) / range - font_height /2, 0, ss.str().c_str());

                value += 1.0/4.0 * range;
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
    cursorAbove = false;
    range = 1023;
    Spectrogram s;
    V.push_back(s);
    live = true;
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
void Graph::changeSpec(int d, Spectrogram s) {
    if(d >= V.size()) cout<<" próbuję dostać się do nieistniejącego spectrogramu\n";
    V[d] = s; 
}

ALLEGRO_FONT * Graph::font;


