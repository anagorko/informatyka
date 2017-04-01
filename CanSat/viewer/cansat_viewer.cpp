//
// CanSat Viewer
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>
#include <iostream>

using namespace std;

#include "config.h"
#include "button.h"
#include "graph.h"
#include "timeline.h"
#include "cansatviewerwindow.h"
#include "../ground_arduino/serial.h"

string portname = "/dev/ttyACM1";
int fd;

int serialInit()
{
    fd = open(portname.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        printf("Error opening %s: %s\n", portname.c_str(), strerror(errno));
        return -1;
    }
    /*baudrate 115200, 8 bits, no parity, 1 stop bit */
    set_interface_attribs(fd, B115200);
	set_mincount(fd, 0);

	return 0;
}

int allegroInit()
{
    if(!al_init()) {
        cerr << "Błąd podczas inicjalizacji allegro." << endl;
        return -1;
    }
  
    if(!al_init_image_addon()) {
        cerr << "Błąd podczas inicjalizacji dodatku 'image'." << endl;
        return -1;
    }

    if (!al_init_primitives_addon()) {
        cerr << "Błąd podczas inicjalizacji dodatku 'primitives'." << endl;
        return -1;
    }
    
    if (!al_install_keyboard()) {
        cerr << "Błąd podczas inicjalizacji klawiatury." << endl;
        return -1;
    }

    if (!al_install_mouse()) {
        cerr << "Błąd podczas inicjalizacji myszy." << endl;
        return -1;
    }
  
    al_init_font_addon();
    al_init_ttf_addon();

	Button::loadFont();
    TimeLine::loadFont();
    Graph::loadFont();
  
    return 0;
}

int main(int argc, char ** argv)
{
    if (allegroInit() != 0) {
        cerr << "Inicjalizacja Allegro nie powiodła się." << endl;
        return -1;
    }

	if (serialInit() != 0) {
        cerr << "Inicjalizacja portu szeregowego nie powiodła się." << endl;
  //      return -1;
	}

	CanSatViewerWindow w;

	w.init();
	w.loop(fd); 

    return 0;
}
