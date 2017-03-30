#ifndef __DATABASE__
#define __DATABASE__

#include <math.h>
#include <sqlite3.h>
#include <string>
using namespace std;

#include "../spectrogram.h"

using namespace std;

class Datastore
{
	string db_filename;

public:
	Datastore() {
	}

	int init(string _fn) {
		db_filename = _fn;
	}

	// Uwaga: moment to czas, jaki minal w 0.1s od 01.01.2017 00:00.1
	//  (moment 0 to dokladnie ta data)

	string moment2string(int moment) {
		// TODO: konwersja momentu na prawdziwy czas
		return "TODO";
	}

	int string2moment(string s) {
		// TODO: konwersja czasu na moment

		return -1;
	}

	Spectrogram readClosest(int moment) {
		// TODO: czytanie z bazy najblizszego odczytu
		Spectrogram dummy;

		//moment = moment - (moment % 50);	// symulowany odczyt co 5s

		for (int i = 0; i < Spectrogram::resolution; i++) {
			dummy.lfl[i] = sin((float)(i+moment)/Spectrogram::resolution * 1.67) * 512 + 512;
		}

		return dummy;
	}

	void write(Spectrogram s) {
		// TODO: zapisywanie w bazie odczytu
	}

	void measurementTable(int from, int to, int resolution, bool data[]) {
	}
};

int chars_to_int( char c1, char c2 );

std::ostream operator<< ( ostream& o, Spectrogram& in );

Spectrogram SELECT( char *query );

Spectrogram lastRecord();


//Kod z internetu
/*void getTableData();
*/

#endif /* __DATABASE__ */	
