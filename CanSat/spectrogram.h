#ifndef __SPECTROGRAM__
#define __SPECTROGRAM__

#include <string>
using namespace std;

class Spectrogram {
public:
	static const int resolution = 256;

	int lfl[resolution];

	int moment;
	
	int temperature, pressure;

	string time;
};

#endif /* __SPECTROGRAM__ */

