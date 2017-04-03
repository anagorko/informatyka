#include<iostream>
#include<sstream>
using namespace std;

// Import "gołych" danych z wtorku 28.03. (same odczyty sensora)
// Wiele wartości jest odgadywanych
// Argument z linii komend: etykieta
// Brak mechanizmu przekazywania czasu początku pomiaru (TODO)

#include "../spectrogram.h"
#include "../datastore/datastore.h"

char serial = 0;
int moment = 0;
int measurement = 0;
string tag = "";

bool parse(string line, Spectrogram &s)
{
	s.setMoment(moment);
	s.id_serial = serial;
	s.id_measurement = measurement;
	s.temperature = 0;
	s.pressure = 0;
	s.time = "";
	s.tag = tag;

	stringstream ss; ss << line;
	string tmp; char tmp2;
	cin >> tmp >> tmp2; // ignorujemy Parsing;

	int i=0, lfl;

	while (ss>>lfl) {
		s.lfl[i] = lfl;
		char c; ss>>c; if(c!=';') return false;
		i++; if (i > 256) return false;
	}
	if (i < 256) return false;

	moment++; measurement++;
	return true;
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		tag = string(argv[1]);
	}

	Datastore data;
	data.init("../CanSat.db", true);

	string line;
	while (!cin.eof()) {
		getline(cin, line, (char) 0x0D);
		Spectrogram s;
		if (parse(line, s)) {
			cout << "Parse ok" << endl;

			data.write(s);
		} else {
			cout << "Parse failed: " << line << endl;
		}
	}
	return 0;
}

