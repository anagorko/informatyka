#include<iostream>
#include<string>
#include<sqlite3.h>
#include<sstream>
#include<time.h>
#include "../spectrogram.h"
#include "datastore.h"
#include "../viewer/moment.h"

using namespace std;

int Datastore::nextMoment(int m)
{
	stringstream ss;
	ss << "SELECT * FROM data WHERE timestamp > '"<<m<<"' ORDER BY timestamp LIMIT 1";
	Spectrogram s = SELECT(ss.str().c_str());

	cout << m<<" -> "<<s.timestamp<< "  " << moment_to_time(m)<<" "<<moment_to_time(s.timestamp)<<endl;

	if (s.timestamp<0) return m;


	return s.timestamp;
}

int Datastore::prevMoment(int m)
{
	stringstream ss;
	ss << "SELECT * FROM data WHERE timestamp < '" << m << "' ORDER BY timestamp DESC LIMIT 1";
	Spectrogram s = SELECT(ss.str().c_str());

	if (s.timestamp<0) return m;

	cout << m<<" -> "<<s.timestamp<< "  " << moment_to_time(m)<<" "<<moment_to_time(s.timestamp)<<endl;
	return s.timestamp;
}

int Datastore::init(string _fn, bool writable) {
	db_filename = _fn;

	int flags = writable ? SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE : SQLITE_OPEN_READONLY;
	
	if (sqlite3_open_v2(db_filename.c_str(), &database, flags, NULL) != SQLITE_OK) {
		cout << "Error opening database." << endl;
		return -1;
	}
	cout << "Opened " << db_filename <<endl;

	return 0;
}

// TODO: czytanie z bazy najblizszego odczytu
Spectrogram Datastore::readClosest(int moment) 
{
/*	static Spectrogram dummy;
	static int last_moment=0;

	if(moment-last_moment>30) {
		last_moment=moment;
		for (int i = 0; i < Spectrogram::resolution; i++) {
			dummy.lfl[i] = sin((float)(i)/Spectrogram::resolution * 4.0) * 512 + 512 + (rand() % 50) - 25;
		}
	}
	dummy.setMoment(moment);

	return dummy; 
*/
	Spectrogram earlier, later;

	stringstream select_earlier, select_later;

	select_earlier << "SELECT * FROM data WHERE timestamp < '" << moment  << "' ORDER BY timestamp DESC LIMIT 1";
	select_later << "SELECT * FROM data WHERE timestamp >= '" << moment  << "' ORDER BY timestamp LIMIT 1";

	earlier = SELECT( select_earlier.str().c_str() );

	later = SELECT( select_later.str().c_str() );

	if (earlier.timestamp==-1&&later.timestamp==-1) {cout<<"no data"<<endl;exit(1);}
	if (earlier.timestamp == -1) return later;
	if (later.timestamp == -1) return earlier;

	if ( moment - earlier.timestamp < later.timestamp - moment ) {
		return earlier;
	} else {
		return later;
	}
}


int Datastore::write(Spectrogram in)
{
	stringstream strm;

	strm << "INSERT INTO data VALUES ( \"" << (int) in.id_serial << "\", "<< (int) in.id_measurement << ", \""  << in.timestamp << "\", " << (int) in.temperature << ", " << (int) in.pressure << ", ";

	strm << "X'";
	for ( int i = 0; i < Spectrogram::resolution; i++ )
	{
		strm << hex << setw(2) << setfill('0') << (unsigned int) (in.lfl[i] & 0xFF);
		strm << hex << setw(2) << setfill('0') << (unsigned int) ((in.lfl[i]>>8) & 0xFF);
	}
	strm << "', ";

	strm << "\"" << in.tag << "\" );";

	string insert;
	getline(strm, insert);
	cout << insert<<endl;
	
	//tu zaczyna się ctrl-v

	sqlite3_stmt *statement;
	const char ** tail=NULL;

	int result;

	{
		if ( (result = sqlite3_prepare_v2( database, insert.c_str(), insert.size(), &statement, tail)) == SQLITE_OK ) 
		{
			cout << "INSIDE" << endl;

			int res=sqlite3_step(statement);
			result=res;
			cout << "res " << res << endl;
			sqlite3_finalize(statement);
			return result;
		}

		cout << "ERROR " << result << endl;
		sqlite3_finalize(statement);
	}
	return 0;

	//tu się kończyć ctrl-v

}

// TODO: zlicza odczyty w zadanym odcinku czasu
int Datastore::countSpectrograms(int from, int to) 
{
	return ((to-(to%5)) - (from-(from%5))) / 5; // symulowany odczyt co 0.5s
}

// TODO: zlicza odczyty z daną etykietą
int Datastore::countSpectrograms(string tag) 
{
	return 0;
}

// TODO: średni odczyt z danego odcinka czasu
Spectrogram Datastore::readInterval(int from, int to)
{
	stringstream q;
	q << "SELECT * FROM data WHERE timestamp >= " << from << " AND timestamp <= " << to;

	return SELECT(q.str().c_str());
}

// TODO: średni odczyt dla danej etykiety
Spectrogram Datastore::readTag(string tag) {
	stringstream q;
	q << "SELECT * FROM data WHERE tag='"<<tag<<"'";
	return SELECT(q.str().c_str());
}



int chars_to_int( char c1, char c2 )
{
	return ( (unsigned int) c1 * 256 ) + (unsigned int) c2;
}

std::ostream operator<< ( ostream& o, Spectrogram& in )
{
	o << in.id_serial << " " << in.id_measurement << " " << in.timestamp << " " << in.temperature << " " << in.pressure;

	for ( int i = 0; i < 256; i++ )
	{
		o << " " << in.lfl[i];
	}

	o << " " << in.tag << endl;
}


Spectrogram Datastore::SELECT( const char *query )
{
	Spectrogram uncode;

	uncode.timestamp=-1;

	string lfl_string;

	const char **tail = NULL;

	sqlite3_stmt *statement;

	if ( sqlite3_prepare_v2( database, query, 1000, &statement, tail ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		res = sqlite3_step(statement);

		int lfl_sum[256]; for (int i = 0; i < 256; i++) { lfl_sum[i] = 0; }
		int temp_sum = 0, press_sum = 0;
		int num_rows = 0;


		while ( res == SQLITE_ROW ) 
		{
			num_rows++;
			if (sqlite3_column_bytes(statement, 5) != 256*2) {
				cout << "Error: incorrect blob"<<endl;
			} else {
				short int *blob = (short int *) sqlite3_column_blob(statement, 5);
				for (int i = 0; i < 256; i++) {
					lfl_sum[i] += blob[i];
				}
			}

			for ( int i = 0; i < ctotal; i++ ) 
			{
				string s = (char*)sqlite3_column_text(statement, i);
				
				//ponieżej jest moja część
				switch ( i )
				{
					case 0:
						uncode.id_serial = s[0];
						break;
					case 1:
						uncode.id_measurement = stoi( s, nullptr, 0 );
						break;
					case 2:
						uncode.timestamp = stoi(s);
						break;
					case 3:
						temp_sum += stoi( s, nullptr, 0 );
						break;
					case 4:
						press_sum += stoi( s, nullptr, 0 );
						break;
					case 5:
						break;
					case 6:
						uncode.tag = s;
						break;
				}
				//wyżej jest moje :)

			}
			res = sqlite3_step(statement);
		}
		if (num_rows == 0) {
			uncode.timestamp = -1;
		} else {
			uncode.temperature = temp_sum / num_rows;
			uncode.pressure = press_sum / num_rows;

			for (int i = 0; i < 256; i++) {
				uncode.lfl[i] = lfl_sum[i]/num_rows;
			}
			if (num_rows>1) { cout<<"num_rows " <<num_rows<<" "<<query<<endl; }
		}
	} else {
		exit(1);
		uncode.timestamp = -1;
	}

	sqlite3_finalize(statement);

	return uncode;
}

Spectrogram Datastore::lastRecord()
{
	return SELECT( "SELECT * FROM data ORDER BY timestamp DESC LIMIT 1" );
}

	

int time_to_moment( string time )
{
	int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0, moment = 0;

	int controler = 0;

	for ( int i = 0; i < time.size(); i++ )
	{
		if ( time[i] == '-' || time[i] == ':' || time[i] == ' ' || time[i] == '.' )
			controler++;
		else
		{
			switch ( controler )
			{
				case 0:
					year = year * 10 + ( (int) time[i] - '0' );
					break;
				case 1:
					month = month * 10 + ( (int) time[i] - '0' );
					break;
				case 2:
					day = day * 10 + ( (int) time[i] - '0' );
					break;
				case 3:
					hour = hour * 10 + ( (int) time[i] - '0' );
					break;
				case 4:
					minute = minute * 10 + ( (int) time[i] - '0' );
					break;
				case 5:
					second = second * 10 + ( (int) time[i] - '0' );
					break;
				case 6:
					moment = moment * 10 + ( (int) time[i] - '0' );
					break;
			}
		}
	}

	struct tm now, zero;
	
	zero.tm_year = 117;
	zero.tm_mon = 0;
	zero.tm_mday = 1;
	zero.tm_hour = 0;
	zero.tm_min = 0;
	zero.tm_sec = 0;
	zero.tm_isdst = -1;

	now.tm_year = year - 1900;
	now.tm_mon = month - 1;
	now.tm_mday = day;
	now.tm_hour = hour;
	now.tm_min = minute;
	now.tm_sec = second;
	now.tm_isdst = -1;

	time_t now_mk = mktime(&now), zero_mk = mktime(&zero);
	
	int time_return = ( ( difftime( now_mk, zero_mk ) * 10 ) + moment );

	return time_return;
}

string moment_to_time( int moment )
{
	if (moment < 0) { moment = 0; }

	struct tm zero;
	zero.tm_year = 117;
	zero.tm_mon = 0;
	zero.tm_mday = 1;
	zero.tm_hour = 0;
	zero.tm_min = 0;
	zero.tm_sec = 0;

	time_t now = mktime( &zero ) + ( moment / 10 );

	char buff[100];
	strftime(buff, 100, "%Y-%m-%d %H:%M:%S", localtime( &now ) );

	string s = buff;

	return s + '.' + (char) ( (moment % 10) + '0' );
}
