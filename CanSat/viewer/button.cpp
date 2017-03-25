#include <allegro5/allegro_primitives.h>

#include "button.h"


void Button::calculate_released() {
    if(pressed){
        pressed = false;
    }
}
void Button::calculate_pressed(int cursor_x, int cursor_y ) {
    if(cursor_x > position_x && cursor_x < position_x + width
        &&  cursor_y > position_y && cursor_y < position_y + height){
        pressed = true;
        px = cursor_x;
        py = cursor_y;
    }

}

Spectrum::Spectrum(){
    for(int i=0;i<lfl_size;i++) lfl[i] = rand()%1023;
    lfl[100] = 1023;
    moment = 0;
}

Button::Button(int _x, int _y, string s) {
    position_x = _x;
    position_y = _y;
    inscription = s;
    //cout<<"elo"<<endl;
    if(inscription == "space"){
        width = 150;
        height = 50;
    }
    pressed = false;
}
void Button::draw(ALLEGRO_DISPLAY * display){
    al_draw_filled_rounded_rectangle(position_x,position_y,position_x + width, position_y + height, 5 , 5, al_map_rgb(255,0,0));
    al_draw_text(font, al_map_rgb(255,255,255),position_x + width/5 ,position_y, 0, inscription.c_str());

}

ALLEGRO_FONT * Button::font;

