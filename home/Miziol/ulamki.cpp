#include<iostream>
#include<fstream>

using namespace std;

bool skracalne(int t[][2], int id)
{
	int limit = (t[id][0] < t[id][1]) ? t[id][0] : t[id][1];
	for( int i = 0; i < limit; i++ )
	{
		if ( t[id][0] % i == 0 && t[id][1] % i == 0 )
			return true;
	}

	return false;
}


int main()
{
	fstream in;

	in.open("../../zbior_zadan/65/dane_ulamki.txt");

	int n = 1000; //ilość ułamków 

	int ulamki[n][2];

	double wartosc[n];

//zmienne odpowiedzi
	int min = 0, nieskracalne = 0;

//wczytywanie
	for ( int i = 0; i < n; i++ )
	{
		in >> ulamki[i][0] >> ulamki[i][1];

		wartosc[i] = (double) ulamki[i][0] / (double) ulamki[i][1];

//65.1
		if( wartosc[i] < wartosc[min] || ( wartosc[i] == wartosc[min] && ulamki[i][1] < ulamki[min][1] ) )
			min = i;

//65.2
		if( !skracalne( ulamki, i ) )
			nieskracalne++;
	}
	
//wypisane odpowiedzi
	cout << "a) " << ulamki[min][0] << " " << ulamki[min][1] << endl;
	cout << "b) " << nieskracalne << endl;

}