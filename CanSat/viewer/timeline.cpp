#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "timeline.h"
#include "config.h"
#include <iostream>
#include <sstream>
using namespace std;

void TimeLine::draw(ALLEGRO_DISPLAY * display) const {
	ALLEGRO_COLOR bg;
	if (cursor_above) {
		if (pressed) {
			bg = al_map_rgba(0x20,0x20,0x20,0x80);
		} else {
			bg = al_map_rgba(0x10,0x10,0x10,0x80);
		}
	} else {
		bg = al_map_rgba(0x00,0x00,0x00,0x80);
	}

        al_draw_filled_rectangle(position_x,position_y,position_x + width, position_y + height, bg);
	al_draw_rectangle(position_x,position_y,position_x+width,position_y+height,al_map_rgb(0x00,0x00,0x30),1);

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
    al_draw_line(x1, y1, x2, y2, al_map_rgba(0x00, 0x00, 0x30, 0x80), 3);
    al_draw_text(font, al_map_rgb(255,255,255),x1 - pix_lenght / 2, y2 + text_distance , 0, ss.str().c_str());

    distance += width / (count_separators * 2);
    
    for(int i=0;i<count_separators;i++){
        //po prawej stronie    
        al_draw_line(x1 + distance, y1, x2 + distance, y2, al_map_rgba(0x00,0x00,0x30,0x80), 1);

        ss.str("");
        ss << (int)(moment / 60 + time_distance * (i+1) / 60 );
        pix_lenght = al_get_text_width(font, ss.str().c_str());
        al_draw_text(font, al_map_rgb(255,255,255),x1 + distance- pix_lenght / 2, y2 + text_distance , 0, ss.str().c_str());
        //po lewej stronie
        al_draw_line(x1 - distance, y1, x2 - distance, y2, al_map_rgba(0x00,0x00,0x30,0x80), 1);

          
        ss.str("");
        ss << (int)(moment / 60 - (time_distance * (i+1)) / 60 );
        pix_lenght = al_get_text_width(font, ss.str().c_str());
        al_draw_text(font, al_map_rgb(255,255,255),x1 - distance- pix_lenght / 2, y2 + text_distance , 0, ss.str().c_str());  

        distance += width / (count_separators * 2);    
    }
 
	ss.str("");
    	ss << "range : " << range;
    	al_draw_text(font, al_map_rgb(0x00,0x00,0x00),position_x + 20, position_y, 0, ss.str().c_str());

	if (left_m >= 0 && right_m >= 0) {
		int left_x = position_x + width/2 + ((float) left_m - moment) / range * width / 2;
		int right_x = position_x + width/2 + ((float) right_m - moment) / range * width / 2;

		al_draw_filled_rectangle(left_x, position_y, right_x, position_y + height, al_map_rgba(0xff,0x00,0x00,0x80));
	} else if (left_m >= 0 || right_m >= 0) {
		int ps = (left_m >= 0) ? left_m : right_m;
		int ps_x = position_x + width/2 + ((float) ps - moment) / range * width / 2;

		al_draw_filled_rectangle(ps_x-1, position_y, ps_x+1, position_y + height, al_map_rgba(0xff,0x00,0x00,0x80));
	}
}

TimeLine::TimeLine() {
    	width = viewer_width - 16;
    	height = viewer_height * ((float)10/(float)100);
    	position_x = (viewer_width - width)/2;
    	position_y = 600;
    	range = 60*2;
    	cursor_above = false;
    	pressed = false;
	pmoment = 0;
    	left_m = -1; right_m = -1;
	tag = "";
}

void TimeLine::mouseMoved(float x, float y, int z){
    if(x > position_x && x < position_x + width
    && y > position_y && y < position_y + height){
        cursor_above = true;
        if (z != 0) { range *= 1.0 + (float) z / 20.0; }
    } else {
        cursor_above = false;
    }
}

void TimeLine::mousePressed(float x, float y, bool shift){
    if( !pressed && x > position_x && x < position_x + width
        && y > position_y && y < position_y + height){
        
        pressed = true;
        px = x;
        py = y;

        float distance = (x - (position_x + width / 2))/(width/2.0);
        pmoment = moment + distance * range;

	if (shift) {
		shiftClick(pmoment);
	} else {
		click(pmoment);
	}
        cout << "dist " << distance << " timeline pressed " << pmoment << " " << range << endl;
    }
}

void TimeLine::mouseReleased(){
    if(pressed){
        pressed = false;
//        moment = pmoment;
    }
}

ALLEGRO_FONT * TimeLine::font;
