#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

bool skracalne(int t[][2], int id)
{
	int limit = (t[id][0] < t[id][1]) ? t[id][0] : t[id][1];

	limit++;
cout << "przed forem" << endl;
	for( int i = 2; i < limit; i++ )
	{
		if ( t[id][0] % i == 0 && t[id][1] % i == 0 )
			return true;
	}
cout << "po forze" << endl;

	return false;
}

int skrocony( int t[][2], int id )
{
	int limit = (t[id][0] < t[id][1]) ? t[id][0] : t[id][1];

	limit++;

	int s[1][2];
	s[0][0] = t[id][0];
	s[0][1] = t[id][1];

	while ( skracalne( s, 0) )
	{
		for ( int i = 2; i < limit; i++ )
		{
			if ( s[0][0] % i == 0 && s[0][1] % i == 0 )
			{
				s[0][0] = s[0][0] / i;
				s[0][1] = s[0][1] / i;
			}
		}
	}

	return s[0][0];
}


int main()
{
	fstream in;

	in.open("../../zbior_zadan/65/dane_ulamki.txt");

	int n = 1000; //ilość ułamków 

	const long long int b = 2*2*3*3*5*5*7*7*13;

	int ulamki[n][2];

	double wartosc[n];

//zmienne odpowiedzi
	int min = 0, nieskracalne = 0, suma_licznikow = 0;
	long long int ulamek_ab = 0;

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

//65.3
		suma_licznikow = suma_licznikow + skrocony( ulamki, i );

//65.4
		ulamek_ab = ulamek_ab + ( b * ulamki[i][0] / ulamki[i][1] );
	}
	
//wypisane odpowiedzi
	cout << "a) " << ulamki[min][0] << " " << ulamki[min][1] << endl;
	cout << "b) " << nieskracalne << endl;
	cout << "c) " << suma_licznikow << endl;
	cout << "d) " << ulamek_ab << endl;

}