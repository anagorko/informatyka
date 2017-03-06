#include<iostream>
#include<fstream>

using namespace std;

int max_dlu = 0, max_gen = 0;


void geny( string s )
{
	int dlu = 0, gen = 0;

	bool w_genie = false;

	for( int i =0; i < s.size(); i++ )
	{
		if ( !w_genie && s[i] == 'A' && s[i+1] == 'A' )
		{
			i++;
			w_genie = true;
			dlu = 2;
		}

		if( w_genie && s[i] == 'B' && s[i+1] == 'B')
		{
			i++;
			w_genie = false;
			dlu = dlu + 2;
			if( dlu > max_dlu )
				max_dlu = dlu;
			gen++;
		}

		if ( w_genie )
			dlu++;
	}

	if ( gen > max_gen )
		max_gen = gen;

	return;
}

bool mutacja( string s )
{
	bool gen = false;

	for ( int i = 0; i < s.size(); i++ )
	{
		if( gen && s[i] == 'B'
			&& s[i+1] == 'C'
			&& s[i+2] == 'D'
			&& s[i+3] == 'D'
			&& s[i+4] == 'C' )
				return true;

		if( gen && s[i] == 'B' && s[i+1] == 'B' )
		{
			i++;
			gen = false;
		}

		if ( !gen && s[i] == 'A' && s[i+1] == 'A' )
		{
			i++;
			gen = true;
		}
	}

	return false;
}

bool palindorm( string s )
{
	for ( int i = 0; i < s.size() / 2; i++ )
	{
		if( s[i] != s[s.size() - i - 1] )
			return false;
	}

	return true;
}

bool odpornosc( string s )
{
	int poczatek = 0, koniec = 0;

	bool gen = false;

	for ( int i = 0; i < s.size(); i++ )
	{
		if ( s[i] == 'A' && s[i+1] == 'A' )
		{
			i++;
			poczatek = i;
			gen = true;
		}

		if ( s[i] == 'B' && s[i+1] == 'B' )
		{
			i++;
			koniec = i;

			bool gen_por = false;

			if( gen )
			{
				int pocz2 = 0;

				for ( int j = s.size() - 1; j >= 0; j-- )
				{
					if( s[j] == 'A' && s[j-1] == 'A' )
					{
						pocz2 = j;
						j = j - 2;
						gen_por = true;
					}

					if( s[j] == 'B' && s[j-1] == 'B' )
					{
						j--;
						gen_por = false;
					}
				}
			}

			if( gen_por )
				return true;
			
			gen = false;
		}
	}

	return false;
}



int main()
{
	int n = 1000;

	ifstream in;
	in.open( "../../zbior_zadan/69/dane_geny.txt");

	string s;

	int gatunki[501];

	int max = 0, ile = 0, mut = 0, silny = 0, odporny = 0;

	for ( int i = 0; i < 501; i++ )
	{
		gatunki[i] = 0;
	}

	for ( int i = 0; i < n; i++ )
	{
		in >> s;

//cout << s << endl;

		gatunki[s.size()]++;


		if ( mutacja( s ) )
			mut++;

		geny( s );

		if ( palindorm( s ) )
			silny++;
		else if (odpornosc( s ) )
			odporny++;
	}

	for ( int i = 1; i < 501; i++ )
	{
		if ( gatunki[i] > 0 )
			ile++;
		if ( gatunki[i]  > max )
			max = gatunki[i];
	}

	cout << "a) " << ile << " "<< max << endl;
	cout << "b) " << mut << endl;
	cout << "c) " << max_gen << " " << max_dlu << endl;
	cout << "d) " << odporny << " " << silny << endl;

	return 0;
}