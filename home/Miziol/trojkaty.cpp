#include<iostream>
#include<fstream>
#include<math.h>


using namespace std;

bool prostokatny( int a, int b, int c )
{
	if ( a > b && a > c )
	{
		if ( pow( b, 2 ) + pow( c, 2 ) == pow( a, 2 ) )
		return true;
	}

	if ( b > a && b > c )
	{
		if ( pow( a, 2 ) + pow( c, 2 ) == pow( b, 2 ) )
		return true;
	}

	if ( c > a && c > b )
	{
		if ( pow( b, 2 ) + pow( a, 2 ) == pow( c, 2 ) )
		return true;
	}

	return false;
}


bool trojkat ( int a, int b, int c )
{
	if ( a + b > c && a + c > b && b + c > a )
		return true;

	return false;
}




int main()
{
	ifstream in;

	in.open( "../../zbior_zadan/80/dane_trojkaty.txt" );

	int n = 500;
	int boki[n];
	int obw_max = 0, ile_trojkatow = 0;

	for ( int i = 0; i < n; i++ )
	{
		in >> boki[i];
	}

//80.1
	cout << "80.1 ";

	for ( int i = 2; i < n; i++ )
	{
		if ( prostokatny( boki[i-2], boki[i-1], boki[i] ) )
			cout << boki[i-2] << " " << boki[i-1] << " " << boki[i] << endl;
	}

//80.2
	cout << "80.2 ";

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			for ( int k = j + 1; k < n; k++ )
			{
				if ( trojkat( boki[i], boki[j], boki[k] ) && boki[i] + boki[j] + boki[k] > obw_max )
					obw_max = boki[i] + boki[j] + boki[k];
			}
		}
	}

	cout << obw_max << endl;

//80.3
	cout << "80.3 ";

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = i + 1; j < n; j++ )
		{
			for ( int k = j + 1; k < n; k++ )
			{
				if ( trojkat( boki[i], boki[j], boki[k] ) )
					ile_trojkatow++;
			}
		}
	}

	cout << ile_trojkatow << endl;

}