#ifndef __SPECTROGRAM__
#define __SPECTROGRAM__

class Spectrogram {
public:
	static const int resolution = 256;

    int lfl[resolution];

    int moment;
	int temperature, pressure;
};

#endif /* __SPECTROGRAM__ */

