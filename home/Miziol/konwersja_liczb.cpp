#include<iostream>
using namespace std;

string cyfry = "0123456789ABCDEF";

string na_system(int n, int b)
{
	string l;
	bool minus = false;

	if( n < 0)
	{
		minus = true;
		n = -n;
	}

	while( n != 0)
	{
		l = cyfry[n%b] + l;
		n = n / b;
	}

	if ( minus ) l = '-' + l;

	return l;
}

int z_systemu(string l, int b)
{
	int n = 0, j, i = 0;
	bool minus = false;

	if( l[0] == '-' )
	{
		minus = true;
		i = 1;
	}

	for ( ; i < l.size(); i++)
	{
		for ( j = 0; j < cyfry.size(); j++)
		{
			if ( cyfry[j] == l[i]) break;
		}

		n = n * b + j;
	}

	if( minus ) n = -n;

	return n;
}

int main()
{
	int n,b;
	string l;

	cout << "Na system" << endl;
	cin >> n >> b;
	cout << na_system(n,b) << endl;

	cout << "Z system" << endl;
	cin >> l >> b;
	cout << z_systemu(l,b) << endl;
}