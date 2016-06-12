#include<iostream>
using namespace std;

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>

const int w = 800;
const int h = 600;

double lewa = -1.5;
double prawa = 0.5;
double dol = -1;
double gora = 1;

double q = 0;
double q_prime;
double p = 0;
double p_prime;

int main(int argc, char** argv)
{
    ALLEGRO_DISPLAY       *display = NULL;

    al_init();
    al_init_primitives_addon();

    //al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    //al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    display = al_create_display(w, h);

    al_clear_to_color(al_map_rgb(0,0,0));

	for(int i = 0; i < 1000; i++)
	{

	    for (int i = 0; i < 50000; i++)
		{
			if(rand()%2 == 0)
			{
				p_prime = p*-0.4 - 1;
				q_prime = q*-0.4 + 0.1;
			}
			else
			{
				p_prime = p*0.76 - 0.4*q;
				q_prime = p*0.4 + 0.76*q;
			}

			p = p_prime;
			q = q_prime;

			//cout<<q<<" "<<p<<endl;
	
			if(i > 100)
			{
				al_draw_pixel((p - lewa) * 800/(prawa - lewa), (q - dol)* 600/(gora - dol), al_map_rgb(255,255,255));
			}
	
		}
		
 		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
		
		lewa = lewa * 0.99;
		prawa = prawa * 0.99;
		dol = dol * 0.99;
		gora = gora * 0.99;

	}

   

    int rest;
    cin>>rest;
    al_rest(rest);
    al_destroy_display(display);

    return 0;
}
