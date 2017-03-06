#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	ifstream in;
	in.open( "../../zbior_zadan/76/szyfr1.txt" );

	int n1 = 6, l_haslo1 = 50;

	string szyfr1[n1];

	for ( int i = 0; i < n1; i++ )
		in >> szyfr1[i];

	for ( int j = 0; j < l_haslo1; j++ )
	{
		int p;

		in >> p;

		for( int i = 0; i < n1; i++ )
		{
			char r = szyfr1[i][j];
			szyfr1[i][j] = szyfr1[i][p];
			szyfr1[i][p] = r;
		}
	}

	cout << "a) ";
	for ( int i = 0; i < n1; i++ )
		cout << szyfr1[i] << endl;

	in.close();



	in.open( "../../zbior_zadan/76/szyfr2.txt" );

	int l_haslo2 = 15;
	int haslo2[15];

	string napis2;

	in >> napis2;

//cout << "\n\n" << napis2 << "\n\n";

	for ( int i = 0; i < l_haslo2; i++ )
		in >> haslo2[i];

	int p = 0;

	for (int i = 0; i < napis2.size(); i++ )
	{
		char r = napis2[i];
		napis2[i] = napis2[ haslo2[p] ];
		napis2[ haslo2[p] ] = r;

		p++;

		p = p % l_haslo2;
	}

	cout << "b) " << napis2 << endl;

	in.close();



	in.open( "../../zbior_zadan/76/szyfr3.txt" );

	int l_haslo3 = 6;
	int haslo3[ l_haslo3 ] = {6,2,4,1,5,3};

	string napis3;

	in >> napis3;

cout << napis3 << endl;

	p = (napis3.size() % l_haslo3) - 1;

	for( int i = napis3.size() - 1; i >= 0; i--)
	{
		if ( p < 0 )
			p = l_haslo3 + p;

		char r = napis3[i];
		napis3[i] = napis3[ haslo3[p] ];
		napis3[ haslo3[p] ] = r;

		p--;
	}

	cout << "c) " << napis3 << endl;
}