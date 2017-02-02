#include<iostream>
#include<math.h>

using namespace std;

bool pp[262145];
bool p[513];

bool cykliczna(string t)
{
	string w1, w2;

	if ( t.size() % 2 != 0 ) return false;

	w1 = t.substr(0,t.length()/2);
	w2 = t.substr(t.length()/2,t.length()/2);

	if ( w1 == w2 ) return true;

	return false;
}

bool jedynki(string t)
{
	for ( int i = 1; i < t.size(); i++ )
	{
		if ( t[i-1] == '1' && t[i] == '1') return false;
	}

	return true;
}

void pol_pierwsze()
{
	for(int i = 0; i < 262145; i++)
	{
		pp[i] = false;
		if( i < 513 ) p[i] = true;
	}
//pierwsze

	for ( int i = 2; i < 513; i++ )
	{
		if ( p[i] )
			for ( int j = i * 2; j < 513; j = j + i)
				p[j] = false;
	}

//polpierwsze
	for ( int i = 2; i < 513; i++)
	{
		for ( int j = i; j < 513; j++ )
		{
			if( p[i] && p[j] )
				pp[ i * j] = true;
		}
	}
}

int bin_dec(string s)
{
	int w = 0;

	for ( int p = 0; p < s.size(); p++ )
	{
		w = w * 2 + ( (int) s[p] - 48);
	}

	return w;
}


int main()
{
	string s;

	int min, max, r;

	int cykliczne = 0, jedynkowe = 0, polp = 0;

	pol_pierwsze();

	for ( int i = 0; i < 1000; i++ )
	{
		cin >> s;

		if ( cykliczna (s) ) cykliczne++;
		if ( jedynki (s) ) jedynkowe++;

		r = bin_dec(s);

		if ( i == 0 )
		{
			min = r;
			max = r;
		}

		if ( pp[r] )
		{
			polp++;
			if ( min > r ) min = r;
			if ( max < r ) max = r;
		}

	}

	cout << cykliczne << endl << jedynkowe << endl << polp << " " << max << " " << min;
}