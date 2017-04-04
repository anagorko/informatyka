#include "cansatviewerwindow.h"
#include "moment.h"

void CanSatViewerWindow::draw() {
	al_clear_to_color(al_map_rgb(0xC0,0xC0,0xFF));
	al_draw_scaled_bitmap(background, 0, 0, al_get_bitmap_width(background), al_get_bitmap_height(background),
		viewer_width-6-1260/8,viewer_height-8-645/8,1260/8, 645/8,0);


	for(auto b: buttons){
	    	b -> draw(display);
	}

	graph.draw(display);
	timeline.draw(display);

        al_draw_text(Button::font, al_map_rgb(0x00,0x00,0x00), 20, 400, 0, moment_to_time(gd.getData().timestamp).c_str());

	stringstream info; int temp = gd.getData().temperature;
	info << "Temp " << (temp/10) << "." << setw(1) << setfill('0') << (temp%10) << " Press " << gd.getData().pressure << " Tag " << gd.getData().tag;
	al_draw_text(Button::font, al_map_rgb(0x00,0x00,0x00), 20, 430, 0, info.str().c_str());
}


CanSatViewerWindow::CanSatViewerWindow() {
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

	al_register_event_source(event_queue, al_get_display_event_source(display));  
	al_register_event_source(event_queue, al_get_timer_event_source(timer));  
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0,0,0));
  
	al_flip_display();  
	al_start_timer(timer);

	data.init("../CanSat.db", false);

	timeline.click(0);
	timeline.tagClick("");

	gd.setData(timeline.getSpectrogram(data));
	gd.setReference(gd.getData());

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
	buttons.push_back(btnSetReference = new Button(308,viewer_height-230,"Set ref",92));
	buttons.push_back(btnPrevMoment = new Button(408,viewer_height-230,"|<",92));
	buttons.push_back(btnNextMoment = new Button(508,viewer_height-230,">|",92));
	buttons.push_back(new Button(608,viewer_height-230,"Avg 5s",92));
	buttons.push_back(new Button(708,viewer_height-230,"Avg 15s",92));
	buttons.push_back(new Button(808,viewer_height-230,"Avg 60s",92));

	buttons.push_back(btnChlor = new Button(1094,8,"Chlor",100, al_map_rgb(0x80,0x20,0x20)));
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

void CanSatViewerWindow::loop(int fd) {
	int time_fraction = 0;

 	while(!wyjdz)
 	{
 		ALLEGRO_EVENT ev;
 	       	al_wait_for_event(event_queue, &ev);
	
 	       	if(ev.type == ALLEGRO_EVENT_TIMER) {
 	        	//
 	        	// minęła 1/60 (1/FPS) część sekundy
 	        	//
 	        	przerysuj = true;
 	        	
 	        	if (timeRun) {
				time_fraction++;
				while (time_fraction>=6){
					timeline.incMoment();
					time_fraction-=6;
				}
			} else {
				time_fraction=0;
			}

			gd.setData(timeline.getSpectrogram(data));

			if (graph.countData() > 0) {
				graph.changeGraphData(0, gd);
			} else {
				gd.setReference(gd.getData());
				graph.addGraphData(gd);
			}
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
 		        timeline.mousePressed(ev.mouse.x, ev.mouse.y, key[ALLEGRO_KEY_LSHIFT]||key[ALLEGRO_KEY_LSHIFT]);
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
 	       		graph.mouseMoved(ev.mouse.x, ev.mouse.y, ev.mouse.dz);
 		}

		if (btnExit -> wasPressed()) { wyjdz = true; }

		if (btnNextMoment->isPressed()) {
			int m = data.nextMoment(timeline.getMoment());
			if (m>=0) {
				timeline.click(m);
			}
		}
		if (btnPrevMoment->isPressed()) {
			int m = data.prevMoment(timeline.getMoment());
			if (m>=0) {
				timeline.click(m);
			}
		}

		if (btnStop -> wasPressed()) { 
			timeRun = false; 
			if (btnPlay -> isActivated()) btnPlay -> changeStatus();
		}
		if (btnPlay -> wasPressed()) { 
			timeRun = true; 
			if (btnStop -> isActivated()) btnStop -> changeStatus();
			if (btnSet -> isActivated()) btnSet -> changeStatus();
		}

		if (btnAbsolute -> wasPressed()) {
			if (btnAbsolute -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnPercent -> isActivated()) btnPercent -> changeStatus();
				if (btnDiffrent -> isActivated()) btnDiffrent -> changeStatus();
			} else btnAbsolute -> changeStatus();
			graph.setShow(GraphData::modeA);
		}
		if (btnDiffrent -> wasPressed()) {
			if (btnDiffrent -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnPercent -> isActivated()) btnPercent -> changeStatus();
				if (btnAbsolute -> isActivated()) btnAbsolute -> changeStatus();
			} else btnDiffrent -> changeStatus();
			graph.setShow(GraphData::modeD);
		}
		if (btnPercent -> wasPressed()) {
			if (btnPercent -> isActivated()){// to znaczy że nie był aktywny przycisk, bo po wciśnięciu zmeniło status na aktywne
				if (btnAbsolute -> isActivated()) btnAbsolute -> changeStatus();
				if (btnDiffrent -> isActivated()) btnDiffrent -> changeStatus();
			} else btnPercent -> changeStatus();
			graph.setShow(GraphData::modeP);
		}
		if (btnSet -> wasPressed()) {
			graph.clearSet();
		}
		if (btnAdd -> wasPressed()) {
			if(btnSet -> isActivated()){
				gd.setData(timeline.getSpectrogram(data));
				graph.addGraphData(gd);
			}
			btnAdd -> changeStatus();
		}
		if (btnClear -> wasPressed()) {
			graph.clearSet();
			btnClear -> changeStatus();
		}
		if (btnLive -> wasPressed()) {
			graph.changeLive();
		}

		if (btnSetReference -> wasPressed()) {
			gd.setReference(gd.getData());
		}

		if (btnChlor->wasPressed()) {
			timeline.tagClick("Metan KALIBRACJA");
			btnChlor->changeStatus();
		}

	 	if(przerysuj && al_is_event_queue_empty(event_queue)) {
 			przerysuj = false;
	
 		        draw();
	
 		        al_flip_display();
 		}
	}    
}

