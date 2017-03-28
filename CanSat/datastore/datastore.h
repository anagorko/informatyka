#include<iostream>
#include<string>
#include<sqlite3.h>
#include "../spectrogram.h"

using namespace std;


int chars_to_int( char c1, char c2 )
{
	return ( (unsigned int) c1 * 256 ) + (unsigned int) c2;
}

std::ostream operator<< ( ostream& o, Spectrogram& in )
{
	o << in.moment << " " << in.temperature << " " << in.pressure;

	for ( int i = 0; i < 256; i++ )
	{
		o << " " << i << "." << in.lfl[i];
	}

	o << endl;
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
							uncode.moment = stoi(s);
							break;
						case 1:
							uncode.temperature = stoi( s, nullptr, 0 );
							break;
						case 2:
							uncode.pressure = stoi( s, nullptr, 0 );
							break;
						case 3:
							lfl_string = s;
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

		cout << (unsigned int) lfl_string[2 * i] << " " << (unsigned int) lfl_string[2 * i + 1] << " " << uncode.lfl[i] << endl;
	}

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
