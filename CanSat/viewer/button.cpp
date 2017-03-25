#include <allegro5/allegro_primitives.h>

#include "button.h"


void Button::mouseReleased() {
    if(pressed){
        pressed = false;
    }
}
void Button::mousePressed(int cursor_x, int cursor_y ) {
    if(cursor_x > position_x && cursor_x < position_x + width
        &&  cursor_y > position_y && cursor_y < position_y + height){
        pressed = true;
        px = cursor_x;
        py = cursor_y;
    }

}
void Button::mouseMoved(int x, int y) {
}

Button::Button(int _x, int _y, string s) {
    position_x = _x;
    position_y = _y;
    inscription = s;

    if(inscription == "space"){
        width = 150;	// TODO: jest w allegro funkcja licząca szerokość napisu w pikselach (dla zadanej czcionki)
        height = 50;
    }
    pressed = false;
}

void Button::draw(ALLEGRO_DISPLAY * display){
	// TODO: inny jest wygląd przycisku naciśniętego, puszczonego i takiego, nad którym jest wskaźnik myszki 

    al_draw_filled_rounded_rectangle(position_x,position_y,position_x + width, position_y + height, 5 , 5, al_map_rgb(255,0,0));
    al_draw_text(font, al_map_rgb(255,255,255),position_x + width/5 ,position_y, 0, inscription.c_str());

}

ALLEGRO_FONT * Button::font;

