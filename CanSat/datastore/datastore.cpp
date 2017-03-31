#include<iostream>
#include<string>
#include<sqlite3.h>
#include<sstream>
#include "../spectrogram.h"
#include "datastore.h"

using namespace std;

Datastore::Datastore() 
{
}

int Datastore::init(string _fn) {
	db_filename = _fn;
}

// TODO: czytanie z bazy najblizszego odczytu
Spectrogram Datastore::readClosest(int moment) 
{
	Spectrogram dummy;
	moment = moment - (moment % 5);	// symulowany odczyt co 0.5s
	for (int i = 0; i < Spectrogram::resolution; i++) {
		dummy.lfl[i] = sin((float)(i+moment)/Spectrogram::resolution * 1.67) * 512 + 512;
	}

	return dummy;
}

// TODO: zapisywanie w bazie odczytu
void Datastore::write(Spectrogram in) //samouczek chce żeby to była fukcja int
{
	sqlite3 *database;

	sqlite3_open( db_filename, &database );

	stringstream strm;

	strm << "INSERT INTO data VALUES ( \"" << in.id_serial << "\", "<< in.id_measurement << ", \""  << in.time << "\", " << in.temperature << ", " << in.pressure << ", ";

	for ( int i = 0; i < in.resolution; i++ )
	{
		strm << in.lfl[i] << ", ";
	}

	strm << "\"" << in.tag << "\" )";

	string insert = strm.str();

	//tu zaczyna się ctrl-v

	char *query = &insert[0];

	sqlite3_stmt *statement;

	int result;

	{
		if(sqlite3_prepare(database,query,-1,&statement,0)==SQLITE_OK)
		{
			int res=sqlite3_step(statement);
			result=res;
			sqlite3_finalize(statement);
		}
		return result;
	}
	return 0;

	//tu się kończyć ctrl-v

	sqlite3_close( database );
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
	return readClosest(from);
}

// TODO: średni odczyt dla danej etykiety
Spectrogram Datastore::readTag(string tag) {
	return readClosest(0);
}



int chars_to_int( char c1, char c2 )
{
	return ( (unsigned int) c1 * 256 ) + (unsigned int) c2;
}

std::ostream operator<< ( ostream& o, Spectrogram& in )
{
	o << in.id_serial << " " << in.id_measurement << " " << in.time << " " << in.temperature << " " << in.pressure;

	for ( int i = 0; i < 256; i++ )
	{
		o << " " << in.lfl[i];
	}

	o << " " << in.tag << endl;
}


Spectrogram SELECT( char *query )
{
	Spectrogram uncode;

	string lfl_string;

	sqlite3 *database;

	sqlite3_open( "CanSat.db", &database );

//tu się zaczyna ctrl-c, które działa ale nie do końca wiem jak

	sqlite3_stmt *statement;

	if ( sqlite3_prepare( database, query, -1, &statement, 0 ) == SQLITE_OK ) 
	{
		int ctotal = sqlite3_column_count(statement);
		int res = 0;

		while ( 1 )         
		{
			res = sqlite3_step(statement);

			if ( res == SQLITE_ROW ) 
			{
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
							uncode.time = s;
							break;
						case 3:
							uncode.temperature = stoi( s, nullptr, 0 );
							break;
						case 4:
							uncode.pressure = stoi( s, nullptr, 0 );
							break;
						case 5:
							lfl_string = s;
							break;
						case 6:
							uncode.tag = s;
							break;
					}
					//wyżej jest moje :)

					cout << s << " ";
				}
				cout << endl;
			}

			if ( res == SQLITE_DONE || res==SQLITE_ERROR)    
			{
				cout << "done " << endl;
				break;
			}
		}
	}

//tu się kończy ctrl-v

	sqlite3_close( database );

	for ( int i = 0; i < 256; i++ )
	{
		uncode.lfl[i] = chars_to_int( lfl_string[ 2 * i ], lfl_string[ 2 * i + 1 ] );

//cout << (unsigned int) lfl_string[2 * i] << " " << (unsigned int) lfl_string[2 * i + 1] << " " << uncode.lfl[i] << endl;
	}

	//TODO time => momnet

	return uncode;
}

Spectrogram lastRecord()
{
	return SELECT( "SELECT * FROM data ORDER BY time DESC LIMIT 1" );
}






//Kod z internetu
/*void getTableData()
{
    sqlite3_stmt *statement;    

    char *query = "select * from data";

    if ( sqlite3_prepare( database, query, -1, &statement, 0 ) == SQLITE_OK ) 
    {
        int ctotal = sqlite3_column_count(statement);
        int res = 0;

        while ( 1 )         
        {
            res = sqlite3_step(statement);

            if ( res == SQLITE_ROW ) 
            {
                for ( int i = 0; i < ctotal; i++ ) 
                {
                    string s = (char*)sqlite3_column_text(statement, i);
                    // print or format the output as you want 
                    cout << s << " " ;
                }
                cout << endl;
            }
            
            if ( res == SQLITE_DONE || res==SQLITE_ERROR)    
            {
                cout << "done " << endl;
                break;
            }    
        }
    }
}*/
