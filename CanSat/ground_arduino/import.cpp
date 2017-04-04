#include<iostream>
#include<sstream>
using namespace std;

// Import "gołych" danych z wtorku 28.03. (same odczyty sensora)
// Wiele wartości jest odgadywanych
// Argument z linii komend: etykieta
// Brak mechanizmu przekazywania czasu początku pomiaru (TODO)

#include "../spectrogram.h"
#include "../datastore/datastore.h"
#include "../viewer/moment.h"

char serial = 0;
int moment = 0;
int measurement = 0;
string tag = "";

bool parse(string line, Spectrogram &s)
{
	s.id_serial = serial;
	s.id_measurement = measurement;
	s.temperature = 0;
	s.pressure = 0;
	s.timestamp = moment;
	s.tag = tag;

	stringstream ss; ss << line;
	string tmp;
	cin >> tmp; // ignorujemy Parsing;

	int i=0, lfl;

	while (ss>>lfl) {
		s.lfl[i] = lfl; cout<<lfl<<" ";
		char c; ss>>c; if(c!=';') return false;
		i++; if (i > 256) return false;
	}
	if (i < 256) return false;
	cout<<endl;
	moment++; measurement++;
	return true;
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		tag = string(argv[1]);
	}
	if (argc > 2) {
		moment = Moment::time_to_moment(argv[2]);
	}

	Datastore data;
	data.init("../CanSat.db", true);

	string line;
	while (!cin.eof()) {
		getline(cin, line, (char) 0x0D);
		Spectrogram s;
		if (parse(line, s)) {
			cout << "Parse ok" << endl;
			moment += 10;
			data.write(s);
		} else {
			cout << "Parse failed: " << line << endl;
		}
	}
	return 0;
}

