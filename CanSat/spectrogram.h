#ifndef __SPECTROGRAM__
#define __SPECTROGRAM__

#include <iostream>

using namespace std;

class Spectrogram {
public:
	static const int resolution = 256;

	char id_serial;

	int id_measurement;

	short int lfl[resolution];
	
	int temperature, pressure;

	int timestamp;

	std::string tag;
};

#endif /* __SPECTROGRAM__ */

