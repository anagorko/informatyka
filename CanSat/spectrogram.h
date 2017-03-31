#ifndef __SPECTROGRAM__
#define __SPECTROGRAM__

#include <iostream>
using namespace std;

class Spectrogram {
public:
	int moment;
	static const int resolution = 256;

	char id_serial;
	char id_measurement[2];

	int lfl[resolution];
	
	int temperature, pressure;

	std::string time;

	std::string tag;

	float getMoment() { return moment; }
	void setMoment(int a) { moment = a; }
};

#endif /* __SPECTROGRAM__ */

