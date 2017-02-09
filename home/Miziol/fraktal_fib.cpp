#include<iostream>
#include<math.h>

using namespace std;

long long int F[41];

void Fib()
{
	for ( int i = 0; i < 41; i++ )
	{
		if ( i < 3 )
		{
			F[i] = 1;
		}
		else
		{
			F[i] = F[i-1] + F[i-2];
		}
	}

	return;
}

bool pierwsza(int a)
{
	double b;

	if( a <= 1 )
		return false;

	for ( int j = 2;  j <= sqrt(a); j++ )
	{
		b = (double) a / (double) j;

		if( a / j == (double) b )
			return false;
	}

	return true;
}

string binary(int a)
{
	string s;

	while( a != 0 )
	{
		if( a % 2 == 0 )
			s = '0' + s;
		else
			s = '1' + s;

		a = a / 2;
	}

	return s;
}

int suma_cyfr( string s )
{
	int ile = 0;
	
	for ( int i = 0; i < s.size(); i++ )
	{
		if ( s[i] == '1' )
			ile++;
	}

	return ile;
}


int main()
{
	Fib();

//67.1
	cout << "a)\n10. " << F[10] << endl;
	cout << "20. " << F[20] << endl;
	cout << "30. " << F[30] << endl;
	cout << "40. " << F[40] << endl;

//67.2
	cout << "b)" << endl;

	for ( int i = 1; i < 41; i++ )
	{
		if( pierwsza(F[i]) )
		{
			cout << i << ". " << F[i] << endl;
		}
	}

//67.3
	cout << "c)" << endl;

	for ( int i = 1; i < 41; i++ )
	{
		cout << binary(F[i]) << endl;
	}

//67.4
	cout << "c)" << endl;

	for ( int i = 1; i < 41; i++ )
	{
		if( suma_cyfr( binary( F[i] ) ) == 6 )
			cout << i << ". " << binary(F[i]) << endl;
	}
}