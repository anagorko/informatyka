#include <iostream>
using namespace std;

#include <allegro5/allegro_primitives.h>
#include "button.h"
#include "timeline.h"

void Button::mouseReleased() {
    if(pressed){
	   pressed = false;
       released  = true;
       if(activated){
            activated = false;
        } else {
            activated = true;
        }
    }
}

bool Button::isInside(float x, float y) {
	return x > position_x && x < position_x + width &&  y > position_y && y < position_y + height;
}

void Button::mousePressed(float x, float y ) {
        if(!pressable) return;
    	if(isInside(x,y)) {
        	pressed = true;
        	px = x;
        	py = y;

		#ifdef DEBUG
		cout << inscription << " pressed" << endl;
		#endif
    	}
}

void Button::mouseMoved(float x, float y) {
    	cursor_above = isInside(x,y);
}

Button::Button(int _x, int _y, string s, int _w, ALLEGRO_COLOR _bg) {
    	position_x = _x;
    	position_y = _y;
    	inscription = s;
    	with_text = true;
    	cursor_above = false;
	bg = _bg;
    	width = _w;
    	height = al_get_font_line_height(font)+6;

    	pressed = false;
        released = false;
        activated = false;
        pressable = true;
        displayed = true;
}

Button::Button(int _x, int _y, string s) : Button(_x,_y,s,al_get_text_width(font,s.c_str())+10, al_map_rgb(50,50,50)) {
}
Button::Button(int _x, int _y, string s,int _w) : Button(_x,_y,s,_w, al_map_rgb(50,50,50)) {
}
Button::Button(int _x, int _y, string s,ALLEGRO_COLOR _bg) : Button(_x,_y,s,al_get_text_width(font,s.c_str())+10,_bg) {
}

void Button::draw(ALLEGRO_DISPLAY * display){
        unsigned char color_red;
        unsigned char color_green;
        unsigned char color_blue;

	al_unmap_rgb(bg,&color_red,&color_green,&color_blue);
	if(activated){
        	color_red = 255-(255-color_red)/2;
        	color_green = 255-(255-color_green)/2;
        	color_blue = 255-(255-color_blue)/2;
    	}
	if(cursor_above) {
	        color_red = 255-(255-color_red)*4/5;
	        color_green = 255-(255-color_green)*4/5;
	        color_blue = 255-(255-color_blue)*4/5;
        
		if(pressed) {
		        color_red = 255-(255-color_red)*4/5;
		        color_green = 255-(255-color_green)*4/5;
		        color_blue = 255-(255-color_blue)*4/5;
        	}
    	}
    
	al_draw_filled_rounded_rectangle(position_x,position_y,position_x + width, position_y + height, 5 , 5, al_map_rgb(color_red,color_green,color_blue));

    	if(with_text){
        	al_draw_text(font, al_map_rgb(255,255,255),position_x ,position_y+3, 0, inscription.c_str());
    	}
}
bool Button::wasPressed(){
    if(released){
        released = false;
        return true;
    }
    return false;
}

ALLEGRO_FONT * Button::font;

