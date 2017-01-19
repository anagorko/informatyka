//wymaga --std c++11

#include<iostream>

using namespace std;

bool p[100000];

void sito()
{
	for (int i = 0; i < 100000; i++)
	{
		p[i] = true;
	}

	for (int i = 2; i < 100000; i++)
	{
		if ( p[i] )
		{
			for ( int j = i * 2; j < 100000; j = j + i)
			{
				p[j] = false;
			}
		}
	}
	return;
}

int odwr( int nor )
{
	int pal = 0;

	while ( nor > 0 )
	{
		pal = pal * 10 + nor % 10;
		nor = nor / 10;
	}

	return pal;
}

bool palindrom( int src )
{
	string s = to_string( src );

	for ( int i = 0; i < s.size() - 1 - i; i++ )
	{
		if ( s[i] != s[ s.size() - 1 ]) return false;
	}
	return true;
}

int po( int n )
{
	int il = 1;

	while ( n > 0 )
	{
		il = il * ( n % 10 );
		n = n / 10;
	}

	if( il < 10 ) return 1;
	else 
	{
		int ret = 1 + po( il );
		return ret;
	}
}

int main()
{
	int t[1000];

	for (int i = 0; i < 1000; i++)
	{
		cin >> t[i];
	}

	sito();	

//a

	int r = 0, ile = 0, wa = 0;

	for (int i = 0; i < 1000; i++ )
	{
		r = t[i];
		ile = 0;

		for ( int j = 3; j < 100000; j = j + 2)
		{
			if ( r % j == 0 )
			{
				ile++;
				r = r / j;
			}
			if (ile == 3)
			{
				wa++;
				break;
			}
		}
	}

	cout << "a) " << wa << endl;

//b
	int wb = 0;

	for ( int i = 0; i < 1000; i++ )
	{
		if ( palindrom ( t[i] + odwr( t[i] ) ) ) wb++;
	}

	cout << "b) " << wb << endl;

//c

	int w1 = 0, w2 = 0, w3 = 0, w4 = 0, w5 = 0, w6 = 0, w7 = 0, w8 = 0;
	int min = 1000000000, max = 0;

	int powe, op;

	for ( int i = 0; i < 1000; i++ )
	{
		op = t[i];

		powe = po(t[i]);

		switch ( powe )
		{
			case 1: w1++; break;
			case 2: w2++; break;
			case 3: w3++; break;
			case 4: w4++; break;
			case 5: w5++; break;
			case 6: w6++; break;
			case 7: w7++; break;
			case 8: w8++; break;
		}

		if ( powe == 1 )
		{
			if ( t[i] < min ) min = t[i];
			if ( t[i] > max ) max = t[i];
		}
	}

	cout << "c) " << w1 << endl
			<< w2 << endl
			<< w3 << endl
			<< w4 << endl
			<< w5 << endl
			<< w6 << endl
			<< w7 << endl
			<< w8 << endl
			<< min << endl
			<< max << endl;

}