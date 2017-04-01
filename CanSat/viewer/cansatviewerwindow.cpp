#include "cansatviewerwindow.h"
#include "moment.h"

void CanSatViewerWindow::draw() {
	al_clear_to_color(al_map_rgb(0xC0,0xC0,0xFF));
	al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background),
		viewer_width-6-1260/8,viewer_height-8-645/8,1260/8, 645/8,0);


	for(auto b: buttons){
	    	b -> draw(display);
	}

	spectrograf.draw(display);
	timeline.draw(display);

	Moment m(gd.getData().getMoment());

        al_draw_text(Button::font, al_map_rgb(0x00,0x00,0x00), 20, 400, 0, m.fullRepresentation().c_str());
	al_draw_text(Button::font, al_map_rgb(0x00,0x00,0x00), 300, 400, 0, "Temp 23 C    Press 1023 hPa      Tag: Chlor");

	cout << gd.getData().getMoment() << " " << m.fullRepresentation() << endl;
}


CanSatViewerWindow::CanSatViewerWindow() {
	timeline.setMoment(0);
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

	background = al_load_bitmap("sailsteam_logo.jpg");	
	cout << background<<endl;

	al_register_event_source(event_queue, al_get_display_event_source(display));  
	al_register_event_source(event_queue, al_get_timer_event_source(timer));  
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0,0,0));
  
	al_flip_display();  
	al_start_timer(timer);

	getSpectrogram(timeline.getMoment());
	spectrograf.setBasis(gd.getData());

 	btnExit = new Button(1094, 700, "Exit",100);
	buttons.push_back(btnExit);
	btnPlay = new Button(8, viewer_height-230, "Play",92);
	buttons.push_back(btnPlay);
	btnStop = new Button(108,viewer_height-230, "Stop",92);
	buttons.push_back(btnStop);
	btnStop -> changeStatus();
    	btnLive = new Button(208,viewer_height-230, "Live",92);
    	buttons.push_back(btnLive);
    	btnLive -> changeStatus();
	btnSetReference = new Button(308,viewer_height-230,"Set ref",92);
	buttons.push_back(btnSetReference);	
	buttons.push_back(new Button(408,viewer_height-230,">|",92));
	buttons.push_back(new Button(508,viewer_height-230,"|<",92));
	buttons.push_back(new Button(608,viewer_height-230,"Avg 5s",92));
	buttons.push_back(new Button(708,viewer_height-230,"Avg 15s",92));
	buttons.push_back(new Button(808,viewer_height-230,"Avg 60s",92));

	buttons.push_back(new Button(1094,8,"Cl",100, al_map_rgb(0x80,0x20,0x20)));
	buttons.push_back(new Button(1094,38,"NO2",100));
	buttons.push_back(new Button(1094,68,"Winyl",100));
	buttons.push_back(new Button(1094,98,"...",100));

    	btnSet = new Button(1094, 248, "Set",100);
    	buttons.push_back(btnSet);
    	btnAdd = new Button(1094, 278, "Save",100);
    	buttons.push_back(btnAdd);
    	btnClear = new Button(1094, 308, "Clear",100);
    	buttons.push_back(btnClear);

	btnAbsolute = new Button(750, 400, "Abs", 92);
	buttons.push_back(btnAbsolute);
	btnAbsolute -> changeStatus();
    	btnDiffrent = new Button(850, 400, "Diff", 92);
    	buttons.push_back(btnDiffrent);
    	btnPercent = new Button(950, 400, "Perc", 92);
    	buttons.push_back(btnPercent);

	return 0;
}

CanSatViewerWindow::~CanSatViewerWindow() {
	for (auto b: buttons) { delete b; }
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

	gd.setData(result);
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
 	        	
 	        	if (timeline.timeRun) timeline.setMoment(timeline.getMoment()+1);
			getSpectrogram(timeline.getMoment());

			if (spectrograf.countData() > 0) {
				spectrograf.changeData(0, gd.getData());
			} else {
				gd.setReference(gd.getData());
				spectrograf.addGraphData(gd);
			}

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
			if (btnSet -> isActivated()) btnSet -> changeStatus();
		}

		if (btnAbsolute -> wasPressed()) {
			if (btnAbsolute -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnPercent -> isActivated()) btnPercent -> changeStatus();
				if (btnDiffrent -> isActivated()) btnDiffrent -> changeStatus();
			} else btnAbsolute -> changeStatus();
			spectrograf.setShow(GraphData::modeA);
		}
		if (btnDiffrent -> wasPressed()) {
			if (btnDiffrent -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnPercent -> isActivated()) btnPercent -> changeStatus();
				if (btnAbsolute -> isActivated()) btnAbsolute -> changeStatus();
			} else btnDiffrent -> changeStatus();
			spectrograf.setShow(GraphData::modeD);
		}
		if (btnPercent -> wasPressed()) {
			if (btnPercent -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnAbsolute -> isActivated()) btnAbsolute -> changeStatus();
				if (btnDiffrent -> isActivated()) btnDiffrent -> changeStatus();
			} else btnPercent -> changeStatus();
			spectrograf.setShow(GraphData::modeP);
		}
		if (btnSet -> wasPressed()) {
			spectrograf.clearSet();
		}
		if (btnAdd -> wasPressed()) {
			if(btnSet -> isActivated()){
				getSpectrogram(timeline.getMoment());
				spectrograf.addGraphData(gd);
			}
			btnAdd -> changeStatus();
		}
		if (btnClear -> wasPressed()) {
			spectrograf.clearSet();
			btnClear -> changeStatus();
		}
		if (btnLive -> wasPressed()) {
			spectrograf.changeLive();
		}

		if (btnSetReference -> wasPressed()) {
			gd.setReference(gd.getData());
		}

	 	if(przerysuj && al_is_event_queue_empty(event_queue)) {
 			przerysuj = false;
	
 		        draw();
	
 		        al_flip_display();
 		}
	}    
}

