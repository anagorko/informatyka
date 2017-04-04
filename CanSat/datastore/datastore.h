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

	sqlite3 *database;
	
public:
	Datastore() {
		database = NULL;
	}
	~Datastore() {
		sqlite3_close_v2(database);
	}

	int init(string _fn, bool writable);

	// czytanie z bazy najblizszego odczytu
	Spectrogram readClosest(int moment);

	// zapisywanie w bazie odczytu
	int write(Spectrogram in);

	// TODO: zlicza odczyty w zadanym odcinku czasu
	int countSpectrograms(int from, int to);

	// TODO: zlicza odczyty z daną etykietą
	int countSpectrograms(string tag);

	// TODO: średni odczyt z danego odcinka czasu
	Spectrogram readInterval(int from, int to);

	// TODO: średni odczyt dla danej etykiety
	Spectrogram readTag(string tag);

	int nextMoment(int);
	int prevMoment(int);

	Spectrogram SELECT( const char *query );
	Spectrogram lastRecord();
};

int chars_to_int( char c1, char c2 );
std::ostream operator<< ( ostream& o, Spectrogram& in );

int time_to_moment( string time );
string moment_to_time( int moment );

#endif /* __DATABASE__ */	
