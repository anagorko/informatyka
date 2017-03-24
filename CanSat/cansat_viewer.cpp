//
// Szablon gry w Allegro 5. (C) Kółko Informatyczne Szkoły Żagle
//

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <vector>

#include <iostream>
using namespace std;

#define lfl_size 256

//
// Konfiguracja gry
//

//ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT * font = NULL;


const int screen_w = 1366;   // szerokość ekranu (screen width)
const int screen_h = 768;   // wysokość ekranu (screen height)

 
//
// Struktury danych
//
class Button{
    float position_x, position_y;
    float width, height;
    string inscription;
    float px, py;//last pressed position
    bool pressed;
public:

    Button(int _x, int _y, string s);
    void calculate_pressed(int cursor_x, int cursor_y);
    void calculate_released();//TODO WHAT TO DO?
    void draw(ALLEGRO_DISPLAY * display);
};
vector <Button> buttons;


struct Spectrum {
    int lfl[lfl_size];
    int moment;
    Spectrum();
};

class Graph {

    float width, height;
    float position_x, position_y;

    float frame_thickness;
    float column_thickness;
public:
    Graph();
    void draw(Spectrum s, ALLEGRO_DISPLAY * display) const;
}spectrograf;

//
// implementacja struktur
//
void Button::calculate_released() {
    if(pressed){
        pressed = false;
    }
}
void Button::calculate_pressed(int cursor_x, int cursor_y ) {
    if(cursor_x > position_x && cursor_x < position_x + width
        &&  cursor_y > position_y && cursor_y < position_y + height){
        pressed = true;
        px = cursor_x;
        py = cursor_y;
    }

}

Spectrum::Spectrum(){
    for(int i=0;i<lfl_size;i++) lfl[i] = rand()%1023;
    lfl[100] = 1023;
    moment = 0;
}

Button::Button(int _x, int _y, string s) {
    position_x = _x;
    position_y = _y;
    inscription = s;
    //cout<<"elo"<<endl;
    if(inscription == "space"){
        width = 150;
        height = 50;
    }
    pressed = false;
}
void Button::draw(ALLEGRO_DISPLAY * display){
    al_draw_filled_rounded_rectangle(position_x,position_y,position_x + width, position_y + height, 5 , 5, al_map_rgb(255,0,0));
    al_draw_text(font, al_map_rgb(255,255,255),position_x + width/5 ,position_y, 0, inscription.c_str());

}


void Graph::draw(Spectrum s, ALLEGRO_DISPLAY * display) const {

    al_draw_rectangle(position_x, position_y, position_x + width, position_y + height, al_map_rgb(255,255,255), frame_thickness);

    float x1 = position_x + frame_thickness;
    
    
    for(int i=0;i<lfl_size;i++){
        float y1 = (position_y + height - frame_thickness) - (s.lfl[i] * (height - 2 * frame_thickness))/1023;
        float x2 = x1 + column_thickness;
        float y2 = position_y + height - frame_thickness;
        al_draw_filled_rectangle(x1, y1, x2, y2,al_map_rgb(23,255,100));
        //cout<<x1 <<" "<<y1 << " "<<x2<<" "<<y2<<endl;
        x1 = x2;
    }

}

Graph::Graph() {
    width = 700;
    height = 500;
    position_x = 40;
    position_y = 30;
    frame_thickness = 5;
    column_thickness = (width - 2 * frame_thickness)/lfl_size;
}

//
// Zmienne
//

//
// Rysowanie planszy
//

void rysuj_plansze(Spectrum S, ALLEGRO_DISPLAY * display)
{
    al_clear_to_color(al_map_rgb(0,0,0));
    buttons[0].draw(display);
    spectrograf.draw(S, display);

}

//
// Mechanika gry
//

void aktualizuj_plansze()
{
}

//
// Reakcja na akcje graczy
//

void co_robia_gracze()
{
}

/****************************************
 * Kod poniżej jest w miarę generyczny  *
 ****************************************/
 
const float FPS = 1;       // Frames Per Second
bool key[ALLEGRO_KEY_MAX];  // wciśnięte klawisze

int init(ALLEGRO_DISPLAY * display)
{
    if(!al_init()) {
        cerr << "Błąd podczas inicjalizacji allegro." << endl;
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
  
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        cerr << "Błąd podczas inicjalizacji zegara." << endl;
        return -1;
    }
 
    display = al_create_display(screen_w, screen_h);
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
    al_init_font_addon();
    al_init_ttf_addon();

    font = al_load_ttf_font("FreeMono.ttf", 30, 12);
  
    al_register_event_source(event_queue, al_get_display_event_source(display));  
    al_register_event_source(event_queue, al_get_timer_event_source(timer));  
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));
  
    al_flip_display();  
    al_start_timer(timer);

    Button space(1000, 300, "space");
    buttons.push_back(space);

    return 0;
}

int main(int argc, char ** argv)
{
    ALLEGRO_DISPLAY * display = NULL;
    if (init(display) != 0) {
        cerr << "Inicjalizacja nie powiodła się." << endl;
        return -1;
    }

 
    bool przerysuj = true;
    bool wyjdz = false;
    Spectrum S;
    


    //
    // Event loop - główna pętla programu
    //
        
    while(!wyjdz)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {
            //
            // minęła 1/60 (1/FPS) część sekundy
            //
            przerysuj = true;

            co_robia_gracze();

            aktualizuj_plansze();

        } else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            key[ev.keyboard.keycode] = true;
        } else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            key[ev.keyboard.keycode] = false;
            
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                wyjdz = true;
            }
        } else if(ev.keyboard.keycode == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            for(int i=0;i<buttons.size();i++){
                buttons[i].calculate_pressed(ev.mouse.x, ev.mouse.y);
            }
        } else if(ev.keyboard.keycode == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
            for(int i=0;i<buttons.size();i++){
                buttons[i].calculate_released();
            }
        }

        if(przerysuj && al_is_event_queue_empty(event_queue)) {
            przerysuj = false;

            rysuj_plansze(S, display);

            al_flip_display();
         }    
    }

    return 0;
}
