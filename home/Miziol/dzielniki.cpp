#include<iostream>
using namespace std;

class liczba
{
public:
	int n;
	bool d[1000001];
	bool f = false;

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
	}
};

int main()
{
cout << "zaczynamy";
	int l1 = 0, l2 = 0, m = 0;

cout << "łykam inta";

	liczba t[200];
cout << "zmienne";

//wczytanie i podpunkt a

	for ( int i = 0; i < 200; i++ )
	{
		cin >> t[i].n;
cout << t[i].n << endl;
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
			for( int i = 1; i <= t[i].n; i++)
			{
				if( t[i].d[i] ) cout << " " << i;
			}
		}
		cout << endl;
	}
}