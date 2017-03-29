#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	ifstream in;

	in.open( "../../zbior_zadan/77/dokad.txt" );

	string napis1, szyfr1 = "LUBIMYCZYTAC";

	int pozycja = 0, przebieg = 0;

	getline( in, napis1);

	for ( int i = 0; i < napis1.size(); i++ )
	{
		if( napis1[i] >= 'A' && napis1[i] <= 'Z' )
		{
			napis1[i] = ( ( napis1[i] - 'A' + szyfr1[pozycja] - 'A' ) % 26 ) + 'A';

			if( pozycja == 0 )
				przebieg++;

			pozycja = ( pozycja + 1 ) % ( szyfr1.size() - 1 );
		}
	}

	cout << "1. a) " << przebieg << endl << napis1 << endl;

	in.close();



	in.open( "../../zbior_zadan/77/szyfr.txt" );

	string napis2, szyfr2;

	string napis3, szyfr3;

	pozycja = 0;

	getline( in, napis2 );
	getline( in, szyfr2 );

	napis3 = napis2;
	szyfr3 = szyfr2;

	for ( int i = 0; i < napis2.size(); i++ )
	{
		if ( napis2[i] >= 'A' && napis2[i] <= 'Z' )
		{
			napis2[i] = ( napis2[i] - szyfr2[pozycja] + 26 ) % 26 + 'A';

			pozycja = ( pozycja + 1 ) % ( szyfr2.size() - 1 );
		}
	}

	cout << "2. " << napis2 << endl;



	double k = 0, n = 0, d = 0;

	int ile[26];
	for ( int i = 0; i < 26; i++ )
		ile[i] = 0;

	for ( int i = 0; i < napis3.size(); i++ )
	{
		if( napis3[i] >= 'A' && napis3[i] <= 'Z' )
		{
			ile[ napis3[i] - 'A' ]++;
		}
	}

	cout << "3.\n";

	for ( int i = 0; i < 26; i++ )
	{
		k = k + ( ile[i] * ( ile[i] - 1 ) );

		n = n + ile[i];

		cout << (char) (i + 'A') << ": " << ile[i] << endl;
	}

	k = k / ( n * (n-1) );

	d = 0.0285 / ( k - 0.0385 );

	cout << fixed << setprecision(2);

	cout << d << " " << szyfr3.size() << endl;
}