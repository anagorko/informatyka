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
	Datastore();
	int init(string _fn);

	// TODO: czytanie z bazy najblizszego odczytu
	Spectrogram readClosest(int moment);

	// TODO: zapisywanie w bazie odczytu
	int write(Spectrogram in);

	// TODO: zlicza odczyty w zadanym odcinku czasu
	int countSpectrograms(int from, int to);

	// TODO: zlicza odczyty z daną etykietą
	int countSpectrograms(string tag);

	// TODO: średni odczyt z danego odcinka czasu
	Spectrogram readInterval(int from, int to);

	// TODO: średni odczyt dla danej etykiety
	Spectrogram readTag(string tag);
};

int chars_to_int( char c1, char c2 );
std::ostream operator<< ( ostream& o, Spectrogram& in );
Spectrogram SELECT( const char *query );
Spectrogram lastRecord();

int time_to_moment( string time );
string moment_to_time( int moment );

#endif /* __DATABASE__ */	
