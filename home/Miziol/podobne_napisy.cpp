#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int koncowka( string s1, string s2 )
{
	int r = 0, l = ( s1.size() < s2.size() ? s1.size() : s2.size() );

	for ( int i = 0; i < l; i++ )
	{
		if ( s1[ s1.size() - 1 - i ] != s2[ s2.size() - 1 - i ] )
			break;

		r++;
	}
	return r;
}


int main()
{
	int n = 200;

	ifstream in;

	in.open( "../../zbior_zadan/72/napisy.txt" );

	vector <string> napis1;
	vector <string> napis2;

	int dluzsze = 0, najdluzsze = 0;

	bool koncowki[n];

	for ( int i = 0; i < n; i++)
		koncowki[i] = false;

	for ( int i = 0; i < n; i++ )
	{
		string s1, s2;
		
		in >> s1 >> s2;

		napis1.push_back( s1 );
		napis2.push_back( s2 );

		if( s1.size() >= s2.size() * 3 || s2.size() >= s1.size() * 3 )
			dluzsze++;
	}

//rozwiązanie c)
	for ( int i = 0; i < n; i++ )
	{
		if( najdluzsze <= koncowka( napis1[i], napis2[i] ) )
			koncowki[i] = true;

		if( najdluzsze < koncowka( napis1[i], napis2[i] ) )
		{
			for ( int j = 0; j < i; j++ )
				koncowki[j] = false;

			najdluzsze = koncowka( napis1[i], napis2[i] );

cout << najdluzsze << " " << i << endl;
		}
	}

	cout << "a) " << dluzsze << endl;

	cout << "b) ";
	for ( int i = 0; i < n; i++ )
	{
		if ( napis1[i].size() < napis2[i].size() )
			for ( int j = 0; j < napis1[i].size(); j++ )
			{
				if( napis1[i][j] != napis2[i][j] )
					break;

				if( j == napis1[i].size() - 1 )
				{
					cout << napis1[i] << " " << napis2[i] << " ";
					
					for ( j++ ; j < napis2[i].size(); j++ )
						cout << napis2[i][j];

					cout << endl;
				}
			}
	}

	cout << "c) " << najdluzsze << endl;

	for ( int i = 0; i < n; i++ )
	{
		if( koncowki[i] )
			cout << napis1[i] << " " << napis2[i] << endl;
	}
}