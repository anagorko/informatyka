#include<iostream>
#include<fstream>

using namespace std;

bool jednolite(string a, string b)
{
	if( a.size() != b.size() || a[0] != b[0] )
		return false;

	for ( int i = 1; i < a.size(); i++ )
	{
		if( a[i] != a[i-1] || b[i] != b[i-1] )
			return false;
	}

	return true;
}

bool anagramy( string a, string b )
{
	if( a.size() != b.size() )
		return false;

	int literki[10][2];

	for ( int i = 0; i < 10; i++ )
	{
		literki[i][0] = 0;
		literki[i][1] = 0;
	}

	for ( int i = 0; i < a.size(); i++ )
	{
		literki[ a[i] - 65 ][0]++;
		literki[ b[i] - 65 ][1]++;
	}

	for ( int i = 0; i < 10; i++ )
	{
		if( literki[i][0] != literki[i][1] )
			return false;
	}

	return true;
}



int main()
{
	ifstream in;

	in.open( "../../zbior_zadan/68/dane_napisy.txt" );
	
	int n = 1000;

	string dane[n][2];

//odpowiedzi
	int jedno = 0, anag = 0, k = 0;
	int k_i = 0, k_j = 0;

//wczytywanie
	for ( int i = 0; i < n; i++ )
	{
		in >> dane[i][0] >> dane[i][1];

//68.1
		if( jednolite( dane[i][0], dane[i][1] ) )
			jedno++;

//68.2
		if( anagramy( dane[i][0], dane[i][1] ) )
			anag++;
	}

//68.3
	for( int i = 0; i < n; i++ )
	{
		k_i = 1;
		k_j = 1;

		for ( int j = 0; j < n; j++ )
		{
			if( i != j && anagramy( dane[i][0], dane[j][0] ) )
				k_i++;
			if( anagramy( dane[i][0], dane[j][1] ) )
				k_i++;

			if( i != j && anagramy( dane[i][1], dane[j][1] ) )
				k_j++;
			if( anagramy( dane[i][1], dane[j][0] ) )
				k_j++;
		}

		if( k_i > k )
			k = k_i;
		if( k_j > k )
			k = k_j;
	}	

	cout << "a) " << jedno << endl;
	cout << "b) " << anag << endl;
	cout << "c) " << k << endl;

}