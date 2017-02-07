#include<iostream>
#include<fstream>

using namespace std;

bool pierwsze[550000000];

void sito()
{
	for ( int i = 0; i < 550000000; i++ ) pierwsze[i] = true;

	for ( int i = 2; i < 550000000; i++ )
	{
		if( pierwsze[i] )
			for ( int j = 2 * i; j < 550000000; j = j + i )
				pierwsze[j] = false;
	}
}

int suma_cyfr(int a)
{
	int w = 0;

	while( a > 0 )
	{
		w = w + a % 10;
		a = a / 10;
	}

	return w;
}

bool trojkat_p( int a, int b, int c )
{
	if( (a*a) + (b*b) == (c*c) )
		return true;
	if( (a*a) + (c*c) == (b*b) )
		return true;
	if( (a*a) == (b*b) + (c*c) )
		return true;

	return false;
}

bool trojkat( int a, int b, int c )
{
	if( a + b > c && a + c > b && b + c > a )
		return true;
	else
		return false;
}


int main()
{
	ifstream in;

	in.open("../../zbior_zadan/66/trojki.txt");

	sito();

	int n = 1000; //rozmiar

	int dane[n][3];

//zmienne odpowiedzi
	bool suma[n], mnozenie[n], trojki[n];
	int trojkaty = 0, ciag = 0, naj_ciag = 0;

//czyszczenie
	for ( int i = 0; i < n; i++ )
	{
		suma[n] = false;
		mnozenie[n] = false;
	}

//wczytywanie
	for ( int i = 0; i < n; i++ )
	{
		in >> dane[i][0] >> dane[i][1] >> dane[i][2];

//66.1
		if( suma_cyfr( dane[i][0] ) + suma_cyfr( dane[i][1] ) == dane[i][2] )
			suma[i] = true;

//66.2
		if( pierwsze[dane[i][0]] && pierwsze[dane[i][1]] && dane[i][0] * dane[i][1] == dane[i][2] )
			mnozenie[i] = true;

//66.3
		if( i > 0 )
			if( trojkat_p( dane[i][0], dane[i][1], dane[i][2] ) && trojkat_p( dane[i-1][0], dane[i-1][1], dane[i-1][2] ) )
				trojki[i] = true;

//66.4
		if( trojkat( dane[i][0], dane[i][1], dane[i][2] ) )
		{
			trojkaty++;
			ciag++;
		}
		else
		{
			if( ciag > naj_ciag )
				naj_ciag = ciag;

			ciag = 0;
		}

	}

//wypisywanie
	cout << "a) " << endl;
	for (int i = 0; i < n; i++ )
		if( suma[i] )
			cout << dane[i][0] << " " << dane[i][1] << " " << dane[i][2] << endl;

	cout << "b) " << endl;
	for (int i = 0; i < n; i++ )
		if( mnozenie[i] )
			cout << dane[i][0] << " " << dane[i][1] << " " << dane[i][2] << endl;

	cout << "c) " << endl;
	for (int i = 0; i < n; i++ )
		if( trojki[i] )
		{
			cout << dane[i-1][0] << " " << dane[i-1][1] << " " << dane[i-1][2] << endl;
			cout << dane[i][0] << " " << dane[i][1] << " " << dane[i][2] << endl;
		}
	cout << "d) " << trojkaty << " " << naj_ciag << endl;
}