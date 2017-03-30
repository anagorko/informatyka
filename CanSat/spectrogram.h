#ifndef __SPECTROGRAM__
#define __SPECTROGRAM__
#include <iostream>
using namespace std;

class Spectrogram {
	int moment;
public:
	static const int resolution = 256;

	int lfl[resolution];
	
	int temperature, pressure;

	std::string time;

	float getMoment() { return moment; }
	void setMoment(int a) { moment = a; }
};

#endif /* __SPECTROGRAM__ */

