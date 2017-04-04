#ifndef __GRAPH__
#define __GRAPH__

#include <allegro5/allegro.h>
#include "../spectrogram.h"
#include <vector>

class GraphData
{
	Spectrogram ref, data;
	int mode;

public:
	static const int modeA = 1;
	static const int modeD = 2;
	static const int modeP = 3;

	GraphData() {
		mode = modeA;
	}

	void setReference(const Spectrogram &_ref) { ref = _ref; }
	void setData(const Spectrogram &_data) { data = _data; }

	Spectrogram getData() { return data; }
	Spectrogram getReference() { return ref; }

	void setMode(int _mode) { mode = _mode; }
	int getMode() { return mode; }

	float integral() const
	{
		float s = 0;
		for (int i = 0; i < Spectrogram::resolution; i++) {
			s += getValue(i);
		}
		return s;
	}

	float maxValue() const
	{
		float max = getValue(0);

		for (int i=1; i < Spectrogram::resolution; i++) {
			if (getValue(i) > max) max = getValue(i);
		}
		return max;
	}

	float minValue() const
	{
		float min = getValue(0);

		for (int i=1; i < Spectrogram::resolution; i++) {
			if (getValue(i) < min) min = getValue(i);
		}
		return min;
	}

	float getValue(int x) const
	{
		switch (mode) {
		case modeA: return data.lfl[x];
		case modeD: return data.lfl[x] - ref.lfl[x];
		case modeP: if (ref.lfl[x] == 0) return 0;
			    return (float) data.lfl[x] / ref.lfl[x];
		}
		cout <<"error"<<endl;
		return 0.314159;
	}
};

class Graph {

	ALLEGRO_COLOR colorBoundary;
	ALLEGRO_COLOR colorBackground;
	ALLEGRO_COLOR colorGraph;
	ALLEGRO_COLOR colorUnderGraph;
    	float frame_thickness;
	float column_thickness;

    	float width, height;
    	float position_x, position_y;

	vector<GraphData> v;

	Spectrogram basis;

	int typeShow;

    	bool cursorAbove, live;
    	float range;

    	static ALLEGRO_FONT * font;

	float maxValue() const {
		float max = v[0].maxValue();

		for (auto gd: v) {
			if (gd.maxValue() > max) { max = gd.maxValue(); }
		}

		return max;
	}

	float minValue() const {
		float min = v[0].minValue();

		for (auto gd: v) {
			if (gd.minValue() < min) { min = gd.minValue(); }
		}

		return min;
	}

	void fixMinMax(float &, float &, float) const;

public:
    	Graph();

    	void mouseMoved(float x, float y, int z);
    	void draw(ALLEGRO_DISPLAY * display);

	void addGraphData(GraphData &gd) {
		v.push_back(gd);
	}
    	int countData() { return v.size(); }
	void changeGraphData(int d, GraphData &gd);

    	void changeLive() { live = (live == true)? false : true; }
    	bool isLive() { return live; }

    	void setShow(int d) { typeShow = d; };
    	void clearSet() { v.clear(); }
	void drawScale() const;

    	static void loadFont() {
        	font = al_load_ttf_font("Inconsolata-Regular.ttf", 10, 0);        
    	}
};

#endif /* __GRAPH__ */

