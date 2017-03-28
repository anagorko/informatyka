#ifndef __CANSATVIEWERWINDOW__
#define __CANSATVIEWERWINDOW__

#include <math.h>
#include "button.h"

#include <sstream>
using namespace std;

class CanSatViewerWindow
{
 	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	vector <Button *> buttons;

	Graph spectrograf;
	TimeLine timeline;
   	bool przerysuj = true;
   	bool wyjdz = false;
   	Spectrogram S;
	bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze   

	Spectrogram getSpectrogram(int m) {
		return S;
	}

    Button* btnExit;

public:
	CanSatViewerWindow() {
		timeline.moment = 0;
		for (int i = 0; i < Spectrogram::resolution; i++) {
			S.lfl[i] = sin((float) (i)/100.0) * 1000;
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

 		btnExit = new Button(1100, 30, "Exit");
	    buttons.push_back(btnExit);
	    buttons.push_back(new Button(900, 30, "play"));
	    buttons.push_back(new Button(1000, 30, "stop"));

		return 0;
	}

	~CanSatViewerWindow() {
		for (auto b: buttons) { delete b; }
	}

	void draw() {
	    al_clear_to_color(al_map_rgb(0,0,0));
	    for(auto b: buttons){
	    	b -> draw(display);
	    }

	    S = getSpectrogram(timeline.moment);

	    spectrograf.draw(S, display);
	    timeline.draw(display);
	}

	stringstream ss;

	void parseData(string line) {
		cout << "Parsing: " << line << endl;

		Spectrogram result;

		stringstream s; s << line;

		s >> result.moment;

		for (int i = 0; i < 256; i++) {
			char c; s >> c; if (c != ';') { cout << "Parse error." << endl; return; }
			int t; s >> t;
			result.lfl[i] = t;
		}

		cout << "Parse correct. " << endl;

		S = result;
	}

	void serialRead(int fd) {
        unsigned char buf[80];
        int rdlen;

        rdlen = read(fd, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            buf[rdlen] = 0;
//            printf("Read %d: \"%s\"\n", rdlen, buf);

			for (int i = 0; i < rdlen; i++) {
				ss << buf[i];

				if (buf[i] == '\n') {
					string line;
					getline(ss,line);
					parseData(line);
				}
			}
        } else if (rdlen < 0) {
            printf("Error from read: %d: %s\n", rdlen, strerror(errno));
        }
	}

	void loop(int fd) {
 	   while(!wyjdz)
 	   {
 	       ALLEGRO_EVENT ev;
 	       al_wait_for_event(event_queue, &ev);
	
 	       if(ev.type == ALLEGRO_EVENT_TIMER) {
 	           //
 	           // minęła 1/60 (1/FPS) część sekundy
 	           //
 	           przerysuj = true;

 	           timeline.moment++;

			   serialRead(fd);
 	       } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
 	           key[ev.keyboard.keycode] = true;

 	           if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
 	               wyjdz = true;
 	           }

 	       } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
 	           key[ev.keyboard.keycode] = false;
 	           
 	       } else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
 	           for(auto b: buttons){
 	               b -> mousePressed(ev.mouse.x, ev.mouse.y);
 	           }
 	       } else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
 	           for(auto b: buttons){
 	           		b -> mouseReleased();
 	           }	
 	       } else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES){
 	       		for(auto b: buttons){
 	       			b -> mouseMoved(ev.mouse.x, ev.mouse.y);
 	       		}
 	       }

		   if (btnExit -> isPressed()) { wyjdz = true; }

 	       if(przerysuj && al_is_event_queue_empty(event_queue)) {
 	           przerysuj = false;
	
 	           draw();
	
 	           al_flip_display();
 	        }    
 	   }
	}
};

#endif /* __CANSATVIEWERWINDOW__ */

