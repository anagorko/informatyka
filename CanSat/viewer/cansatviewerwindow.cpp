#include "cansatviewerwindow.h"

CanSatViewerWindow::CanSatViewerWindow() {
	timeline.setMoment(0);
	for (int i = 0; i < Spectrogram::resolution; i++) {
		S.lfl[i] = sin((float) (i)/100.0) * 1000;
	}		
}

int CanSatViewerWindow::init() {
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

	spectrograf.setBasis(getSpectrogram(timeline.getMoment()));

 	btnExit = new Button(1100, 30, "Exit");
	buttons.push_back(btnExit);
	btnPlay = new Button(900, 30, "play");
	buttons.push_back(btnPlay);
	btnStop = new Button(1000, 30, "stop");
	buttons.push_back(btnStop);
	btnStop -> changeStatus();

	btnChlor = new Button(900, 100, "chlor");
	buttons.push_back(btnChlor);

	btnAbsolute = new Button(100, 550, "Absolute");
	buttons.push_back(btnAbsolute);
	btnAbsolute -> changeStatus();

    btnDiffrent = new Button(300, 550, "diffrent");
    buttons.push_back(btnDiffrent);
    btnPercent = new Button(500, 550, "percent");
    buttons.push_back(btnPercent);
    btnSet = new Button(650, 550, "set");
    buttons.push_back(btnSet);
    btnAdd = new Button(700, 550, "add");
    buttons.push_back(btnAdd);

	return 0;
}

CanSatViewerWindow::~CanSatViewerWindow() {
	for (auto b: buttons) { delete b; }
}

void CanSatViewerWindow::draw() {
	al_clear_to_color(al_map_rgb(0,0,0));
	for(auto b: buttons){
	    	b -> draw(display);
	}

	spectrograf.draw(S, display);
	timeline.draw(display);
}

void CanSatViewerWindow::parseData(string line) {
	cout << "Parsing; " <<line;

	Spectrogram result;

	stringstream s; s << line;

	int m;
	s >> m;
	result.setMoment(m);

	for (int i = 0; i < 256; i++) {
		char c; s >> c; if (c != ';') { cout << "Parse error." << endl; return; }
		int t; s >> t;
		result.lfl[i] = t;
	}

	//cout << "Parse correct. " << endl;

	S = result;
}

void CanSatViewerWindow::serialRead(int fd) {
        unsigned char buf[80];
        int rdlen;

        rdlen = read(fd, buf, sizeof(buf) - 1);
        if (rdlen > 0) {
            	buf[rdlen] = 0;

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

void CanSatViewerWindow::loop(int fd) {
 	while(!wyjdz)
 	{
 		ALLEGRO_EVENT ev;
 	       	al_wait_for_event(event_queue, &ev);
	
 	       	if(ev.type == ALLEGRO_EVENT_TIMER) {
 	        	//
 	        	// minęła 1/60 (1/FPS) część sekundy
 	        	//
 	        	przerysuj = true;
 	        	if (!btnSet -> isActivated()){
 	        		if (timeline.timeRun) timeline.setMoment(timeline.getMoment()+1);
				}
				//cout << timeline.getMoment()<<endl;
			spectrograf.clearSet();
			spectrograf.addSpec(getSpectrogram(timeline.getMoment()));

			//serialRead(fd);
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
 		        timeline.mousePressed(ev.mouse.x, ev.mouse.y);
		} else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
 		  	for(auto b: buttons){
 		          	b -> mouseReleased();
 		        }
 	        	timeline.mouseReleased();
 		} else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
 	       		for(auto b: buttons){
 	       			b -> mouseMoved(ev.mouse.x, ev.mouse.y);
 	       		}
 	       		timeline.mouseMoved(ev.mouse.x, ev.mouse.y, ev.mouse.dz);
 	       		spectrograf.mouseMoved(ev.mouse.x, ev.mouse.y, ev.mouse.dz);
 		}

		if (btnExit -> wasPressed()) { wyjdz = true; }
		if (btnStop -> wasPressed()) { 
			timeline.timeRun = false; 
			if (btnPlay -> isActivated()) btnPlay -> changeStatus();
		}
		if (btnPlay -> wasPressed()) { 
			timeline.timeRun = true; 
			if (btnStop -> isActivated()) btnStop -> changeStatus();
		}

		if (btnAbsolute -> wasPressed()) {
			if (btnAbsolute -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnPercent -> isActivated()) btnPercent -> changeStatus();
				if (btnDiffrent -> isActivated()) btnDiffrent -> changeStatus();
			} else btnAbsolute -> changeStatus();
			spectrograf.setShow(0);
		}
		if (btnDiffrent -> wasPressed()) {
			if (btnDiffrent -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnPercent -> isActivated()) btnPercent -> changeStatus();
				if (btnAbsolute -> isActivated()) btnAbsolute -> changeStatus();
			} else btnDiffrent -> changeStatus();
			spectrograf.setShow(1);
		}
		if (btnPercent -> wasPressed()) {
			if (btnPercent -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnAbsolute -> isActivated()) btnAbsolute -> changeStatus();
				if (btnDiffrent -> isActivated()) btnDiffrent -> changeStatus();
			} else btnPercent -> changeStatus();
			spectrograf.setShow(2);
		}
		if (btnSet -> wasPressed()) {
			if(btnPlay -> isActivated()) {
				timeline.timeRun = false;
				btnPlay -> changeStatus();
				btnStop -> changeStatus();
			}
		}
		if (btnAdd -> wasPressed()) {
			if(btnSet -> isActivated()){
				spectrograf.addSpec(getSpectrogram(timeline.getMoment()));
			}
		}


	 	if(przerysuj && al_is_event_queue_empty(event_queue)) {
 			przerysuj = false;
	
 		        draw();
	
 		        al_flip_display();
 		}
	}    
}

