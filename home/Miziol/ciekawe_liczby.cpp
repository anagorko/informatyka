#include<iostream>

using namespace std;

bool p[1000000000];

void sito()
{
	for (int i = 0; i < 1000000000; i++)
	{
		p[i] = true;
	}

	for (int i = 2; i < 1000000000; i++)
	{
		if ( p[i] )
		{
			for ( int j = i * 2; j < 1000000000; j = j + i)
			{
				p[j] = false;
			}
		}

		cout << i << endl;
	}
	return;
}

int main()
{
	int t[3];

	for (int i = 0; i < 3; i++)
	{
		cout << "Podaj" << i << endl;
		cin >> t[i];
	}

	sito();	

//a

	int r = 0, ile = 0, w = 0;

	for (int i = 0; i < 3; i++ )
	{
		r = t[i];
		ile = 0;

		for ( int j = 3; j < 1000000000; j = j + 2)
		{
			if ( r % j == 0 )
			{
				ile++;
				r = r / j;
			}
			if (ile == 3)
			{
				w++;
				break;
			}
		}
	}

	cout << "a)" << w << endl;




}