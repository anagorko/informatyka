#include<iostream>
using namespace std;

class liczba
{
public:
	int n;
	//bool d[2];
	bool d[1000001];
	bool f;

	void dzielniki()
	{
		int ile = 0;

		for( int i = 1; i <= n; i++)
		{
			if ( n % i == 0 )
			{
				d[i] = true;
				ile++;
			}
		}

		if( ile == 18 )
		{
			d[0] = true;
		}
	}

	liczba()
	{
		for ( int i = 0; i < 1000001; i++)
		{
			d[i] = false;
		}
		f = false;
	}
};


liczba t[200];


int main()
{
//cout << "zaczynamy";
	int l1 = 0, l2 = 0, m = 0;

//cout << "łykam inta";

//cout << "zmienne";

//wczytanie i podpunkt a

	for ( int i = 0; i < 200; i++ )
	{
		cin >> t[i].n;
//cout << t[i].n << endl;
		if( t[i].n < 1000 )
		{
			m++;
			l2 = l1;
			l1 = t[i].n;
		}
	}

	cout << m << " " << l1 << " " << l2 << endl;

// podpukt b

	for ( int i = 0; i < 200; i++)
	{
		t[i].dzielniki();

		if( t[i].d[0] )
		{
			cout << t[i].n;
			for( int j = 1; j <= t[i].n; j++)
			{
				if( t[i].d[j] ) cout << " " << j;
			}
			cout << endl;
		}		
	}

//podpuknt 3

	bool p[1000001][2];

	for (int i = 2; i < 1000001; i++ )
	{
		p[i][0] = false;
		p[i][1] = false;

		for ( int j = 0; j < 200; j++ )
		{
			if( t[j].d[i] && p[i][0] )
			{
				p[i][1] = true;
				break;
			}

			if( t[j].d[i] )
			{
				p[i][0] = true;
			}
		}
	}

	for ( int i = 0; i < 200; i++ )
	{
		for ( int j = 2; j <= t[i].n; j++ )
		{
			if ( t[i].n == j && p[j][1] == false )
				cout << t[i].n << endl;
			if ( t[i].d[j] && p[j][1])
				break;
		}
	}
}