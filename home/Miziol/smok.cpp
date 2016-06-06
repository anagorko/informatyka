#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

using namespace std;

const int sizeX = 600, sizeY = 600;

int main()
{
	int n;

	double x = 1.00, y = 1.00;

	al_init();

	al_set_new_display_flags(ALLEGRO_WINDOWED);	

	ALLEGRO_BITMAP *screen;
	ALLEGRO_DISPLAY *display;

	display = al_create_display (sizeX, sizeY);
	screen = al_create_bitmap (sizeX, sizeY);
	
	//al_set_target_backbuffer(screen);
	al_clear_to_color(al_map_rgb(0,0,0));	
	
	for(int i = 0; i < 1000000000000; i++)
	{
		n = rand()%2;

		if (n == 0)
		{
			x = -0.4*x - 1;
			y = -0.4*y + 0.1;
		}
		if (n == 1)
		{
			x = 0.76*x - 0.4*y;
			y = 0.4*x + 0.76*y;
		}

		cout << x << " " << y << endl;

		int xr = ((x + (sizeX/200)) * 100), yr = ((y + (sizeY/200)) * 100);

		al_draw_pixel (xr % sizeX, yr % sizeY, al_map_rgb(255,255,255));

		if(i % 5000 == 0) al_flip_display();
	}

	return 0;
}
