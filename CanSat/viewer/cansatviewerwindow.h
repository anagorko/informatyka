#ifndef __CANSATVIEWERWINDOW__
#define __CANSATVIEWERWINDOW__

#include <math.h>

class CanSatViewerWindow
{
 	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	vector <Button> buttons;
	Graph spectrograf;
   	bool przerysuj = true;
   	bool wyjdz = false;
   	Spectrogram S;
	bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze   

public:
	CanSatViewerWindow() {
		for (int i = 0; i < Spectrogram::resolution; i++) {
			S.lfl[i] = sin((float) i/100.0) * 1000;
		}
	}

	int init() {
	    timer = al_create_timer(1.0 / FPS);
	    if(!timer) {
	        cerr << "Błąd podczas inicjalizacji zegara." << endl;
	        return -1;
	    }
 
	    display = al_create_display(viewer_width, viewer_height);
	    if(!display) {
	        cerr << "Błąd podczas inicjalizacji ekranu." << endl;
	        al_destroy_timer(timer);
	        return -1;
	    }

	    event_queue = al_create_event_queue();
	    if(!event_queue) {
	        cerr << "Błąd podczas inicjalizacji kolejki zdarzeń." << endl;
	        al_destroy_display(display);
	        al_destroy_timer(timer);
	        return -1;
	    }

	    al_register_event_source(event_queue, al_get_display_event_source(display));  
	    al_register_event_source(event_queue, al_get_timer_event_source(timer));  
	    al_register_event_source(event_queue, al_get_keyboard_event_source());
	    al_register_event_source(event_queue, al_get_mouse_event_source());
	    al_clear_to_color(al_map_rgb(0,0,0));
  
	    al_flip_display();  
	    al_start_timer(timer);

	    Button space(1000, 300, "space");
	    buttons.push_back(space);
	}

	void draw() {
	    al_clear_to_color(al_map_rgb(0,0,0));
	    buttons[0].draw(display);
	    spectrograf.draw(S, display);
	}

	void loop() {
 	   while(!wyjdz)
 	   {
 	       ALLEGRO_EVENT ev;
 	       al_wait_for_event(event_queue, &ev);
	
 	       if(ev.type == ALLEGRO_EVENT_TIMER) {
 	           //
 	           // minęła 1/60 (1/FPS) część sekundy
 	           //
 	           przerysuj = true;


 	       } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
 	           key[ev.keyboard.keycode] = true;
 	       } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
 	           key[ev.keyboard.keycode] = false;
 	           
 	           if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
 	               wyjdz = true;
 	           }
 	       } else if(ev.keyboard.keycode == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
 	           for(int i=0;i<buttons.size();i++){
 	               buttons[i].mousePressed(ev.mouse.x, ev.mouse.y);
 	           }
 	       } else if(ev.keyboard.keycode == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
 	           for(int i=0;i<buttons.size();i++){
 	               buttons[i].mouseReleased();
 	           }
 	       }
  		   // TODO: obsługa zdarzenia - przesunięcia wskaźnika myszki

 	       if(przerysuj && al_is_event_queue_empty(event_queue)) {
 	           przerysuj = false;
	
 	           draw();
	
 	           al_flip_display();
 	        }    
 	   }
	}
};

#endif /* __CANSATVIEWERWINDOW__ */

