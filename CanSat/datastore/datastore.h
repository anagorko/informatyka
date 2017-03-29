#ifndef __DATABASE__
#define __DATABASE__

#include<sqlite3.h>
#include "../spectrogram.h"

using namespace std;


int chars_to_int( char c1, char c2 );

std::ostream operator<< ( ostream& o, Spectrogram& in );

Spectrogram SELECT( char *query );

Spectrogram lastRecord();


//Kod z internetu
/*void getTableData();
*/

#include "datastore.cpp"

#endif /* __DATABASE__ */