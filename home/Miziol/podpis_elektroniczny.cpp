#include<iostream>
#include<fstream>

using namespace std;

bool podpunk1;

string skrot( string wiadomosc )
{
	string s = "ALGORYTM";

	for ( int i = wiadomosc.size() % 8; ; i++ )
	{
		if( i % 8 == 0 || i == 0 )
			break;
		wiadomosc = wiadomosc + ".";
	}

	if ( podpunk1 )
		cout << wiadomosc.size() << endl;

	for ( int i = 0; i < wiadomosc.size(); i++ )
	{
		s[ i % 8 ] = (char) ( ( (int) s[ i % 8 ] + (int) wiadomosc[i] ) % 128 );
	}

	string wynik = "";

	if ( podpunk1 )
	{
		for ( int i = 0; i < 8; i++ )
			cout << (int) s[i] << " ";

		cout << endl;
	}

	for ( int i = 0; i < 8; i++ )
	{
		wynik = wynik + (char) (65 + (int) s[i] % 26);
	}

	if( podpunk1 )
		cout << wynik << endl;

	return wynik;
}

string deszyfrowanie( int d, int n, int *s)
{
	string wynik = "";

	for ( int i = 0; i < 8; i++ )
		wynik = wynik + (char) ( (s[i] * d) %n );

	return wynik;
}

int main()
{
	int n = 11;

	ifstream in;

	in.open( "../../zbior_zadan/78/wiadomosci.txt" );

	string wiadomosci[n], podpisy_string[n];

	for ( int i = 0; i < n; i++ )
		getline ( in, wiadomosci[i] );

	in.close();

	in.open( "../../zbior_zadan/78/podpisy.txt" );

	int podpisy[n][8];

	for ( int i = 0; i < n; i++ )
		for( int j = 0; j < 8; j++ )
			in >> podpisy[i][j];

//podpunkt 1
	podpunk1 = true;

	cout << "78.1" << endl;

	skrot ( wiadomosci[0] );

	podpunk1 = false;

//podpunkt 2
	cout << "78.2" << endl;

	for ( int i = 0; i < 11; i++ )
	{
		podpisy_string[i] = deszyfrowanie( 3, 200, podpisy[i] );
		cout << podpisy_string[i] << endl;
	}

//podpunkt 3
	cout << "78.3" << endl;

	for ( int i = 0; i < 11; i++ )
	{
cout << skrot( wiadomosci[i] ) << " " << podpisy_string[i] << "koniec testu\n";
		if( skrot( wiadomosci[i] ) == podpisy_string[i] )
			cout << (i + 1) << " ";
	}

	cout << endl;

}