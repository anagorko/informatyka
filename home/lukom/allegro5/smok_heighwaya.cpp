#include <iostream>
using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>



const int screen_w = 1366;
const int screen_h = 768;

float sc = 500.0f;

ALLEGRO_DISPLAY *display = NULL;

int main(){
	al_init();

	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

	display = al_create_display(screen_w, screen_h);

 	double x=0;
	double y=0;

	int phase = 0;
	int tdisp = -1;


	al_clear_to_color(al_map_rgb(0, 0, 0));

	while(true){

		al_draw_pixel(x*sc + screen_w*6/10, y*sc + screen_h*6/10, al_map_rgb(255, 255, 255));

		phase = rand()%2;

		if(phase == 0){
			x = (-0.4 * x -1);
			y = (-0.4 * y + 0.1);

		//	sc++;
		}else if(phase == 1){
			double _x =x, _y=y;
			x = (0.76 * x -0.4 * y);
			y = (0.4 * _x + 0.76 * _y); 
		//	sc--;
		}
		tdisp = (tdisp + 1) % 100000;
		if(tdisp==0) al_flip_display();
	}

}
