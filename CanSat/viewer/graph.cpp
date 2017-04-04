#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "graph.h"
#include "config.h"
#include "../spectrogram.h"
#include <string>
#include <sstream>
#include <iomanip>

void Graph::fixMinMax(float &min, float &max, float integ) const {
	float a = Spectrogram::resolution * (max-min);
	integ = integ-Spectrogram::resolution*min;

	cout << "integ "<<integ<<" a "<<a<<endl;

	if (integ > a/2.0) {
		max += (integ-a/2.0) / Spectrogram::resolution;
	} else {
		min += (integ-a/2.0) / Spectrogram::resolution;
	}

	if (max-min < 10.0) {
		max += 5.0;
		min += -5.0;
	}
}

void Graph::draw(ALLEGRO_DISPLAY * display) {

	al_draw_filled_rectangle(position_x,position_y,position_x+width,position_y+height, colorBackground);
	al_draw_rectangle(position_x, position_y, position_x + width, position_y + height, colorBoundary,
			  frame_thickness);
    
    	float x1 = position_x + frame_thickness;

        for(auto &gd: v){
		gd.setMode(typeShow);
	}

	drawScale();

	float max = maxValue(), min = minValue();

	float integ=0;
	for (auto &gd: v){
		integ+=gd.integral();
	}
	integ /= v.size();
	fixMinMax(min,max,integ);

        for(auto &gd: v){
		float px, py; bool first=true;
		x1 = position_x + frame_thickness;

    		for(int i=0;i< Spectrogram::resolution;i++){
       	     		float y1;
            		float r = column_thickness;
            		
			float relative_y;

			gd.setMode(typeShow);
			if (max == min) { 
				relative_y = 0.5; 
			} else {
				relative_y = (gd.getValue(i) - min) / (max - min);
			}

			y1 = position_y + height - frame_thickness - relative_y * height;

			al_draw_filled_rectangle(x1,position_y+height-frame_thickness, x1+r, y1, colorUnderGraph);
			al_draw_filled_rectangle(x1,y1-1, x1+r, y1+1, colorUnderGraph);
                    	al_draw_filled_circle(x1+r/2, y1, r*0.8, colorGraph);
			if (!first) {
				al_draw_line(x1,y1,px,py,colorGraph,r);
			}
	        	x1 += column_thickness;
			px=x1; py=y1; first = false;
        	}
    	}
}

void Graph::drawScale() const {
    float stick_y1 = position_y;
    float stick_y2 = position_y + height;
    al_draw_line(position_x + width + 10, stick_y1, position_x + width + 10, stick_y2, al_map_rgb(0, 0, 0), 2);  

	float integ=0;
	for (auto &gd: v){
		integ+=gd.integral();
	}
	integ /= v.size();

	float max = maxValue(), min = minValue();
	fixMinMax(min,max,integ);

    stringstream ss;
    int font_height = al_get_font_line_height(font);
    float stickLen = stick_y2 - stick_y1;
    
    	for(int i=0;i<5;i++){
		float value = (float) i * (max - min) / 4.0;
		float h = stickLen / (max - min) * value;

        	ss.str("");
        	ss << setw(4) << (min+value);
	
		al_draw_line(position_x + frame_thickness, stick_y2-h, 
			     position_x + width-frame_thickness,stick_y2-h, al_map_rgba(0,0,0,0x40),1);
        	al_draw_text(font, al_map_rgb(0,0,0),position_x + width + 2 * frame_thickness + 10, stick_y2 - h - font_height /2, 0, ss.str().c_str());

	}
}

Graph::Graph() {
	colorBoundary = al_map_rgb(0x00,0x00,0x30);
	colorBackground = al_map_rgb(0xF0, 0xF0, 0xF0);
	colorGraph = al_map_rgb(0x00, 0x00, 0x80);
	colorUnderGraph = al_map_rgba(0x00, 0x00, 0x80, 0x20);
	frame_thickness = 1;

    	width = 4*256+2;
    	height = 384;
    	position_x = 6;
	position_y = 8;

    	column_thickness = (float)(width - 2 * frame_thickness)/Spectrogram::resolution;
    	setShow(GraphData::modeA);
    	cursorAbove = false;
    	range = 1023;
    	live = true;

	GraphData gd;
	addGraphData(gd);
}
void Graph::mouseMoved(float x, float y, int z){
    if(x > position_x && x < position_x + width
    && y > position_y && y < position_y + height){
        cursorAbove = true;
        //cout<<"mouse wheel = " << z<<endl;
        range += 1.0 * z;
    } else {
        cursorAbove = false;
    }
}
/*
void Graph::changeData(size_t d, Spectrogram s) {
    	if(d >= v.size()) cout<<" próbuję dostać się do nieistniejącego spectrogramu\n";
    	v[d].setData(s); 
//	v[d].setReference(s);
}
*/

void Graph::changeGraphData(int d, GraphData &gd) {
    	if(d >= v.size()) cout<<" próbuję dostać się do nieistniejącego spectrogramu\n";
	v[d] = gd;
}

ALLEGRO_FONT * Graph::font;


