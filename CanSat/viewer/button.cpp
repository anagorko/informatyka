#include <iostream>
using namespace std;

#include <allegro5/allegro_primitives.h>
#include "button.h"
#include "timeline.h"

void Button::mouseReleased() {
	pressed = false;
}

bool Button::isInside(float x, float y) {
	return x > position_x && x < position_x + width &&  y > position_y && y < position_y + height;
}

void Button::mousePressed(float x, float y ) {
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

Button::Button(int _x, int _y, string s) {
    	position_x = _x;
    	position_y = _y;
    	inscription = s;
    	with_text = true;
    	cursor_above = false;

    	width = al_get_text_width(font, inscription.c_str());
    	height = al_get_font_line_height(font);

    	pressed = false;
}

void Button::draw(ALLEGRO_DISPLAY * display){
    	float color_red = 50;
    	float color_green = 50;
    	float color_blue = 50;
    
	if(cursor_above) {
        	color_red = (int)(color_red + 50) % 256;
        	color_green = (int)(color_green + 50) % 256;
        	color_blue = (int)(color_blue + 50) % 256;
        
		if(pressed) {
            		color_red = (int)(color_red + 50) % 256;
            		color_green = (int)(color_green + 50) % 256;
            		color_blue = (int)(color_blue + 50) % 256;
        	}
    	}
    
	al_draw_filled_rounded_rectangle(position_x,position_y,position_x + width, position_y + height, 5 , 5, 		al_map_rgb(color_red,color_green,color_blue));

    	if(with_text){
        	al_draw_text(font, al_map_rgb(255,255,255),position_x ,position_y, 0, inscription.c_str());
    	}
}

ALLEGRO_FONT * Button::font;

