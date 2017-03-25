#include<iostream>
#include<sqlite3.h>


using namespace std;



struct spectrum
{
	int temperature;
	int preasure;

	int lfl[256];
};

spectrum SELECT( char *query )
{
	spectrum uncode;

	sqlite3 *database;

	sqlite3_open( "CanSat.db", &database );

//tu się zaczyna ctrl-c

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

//tu się kończy ctrl-v

	sqlite3_close( database );

	return uncode;
}

spectrum lastRecord()
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