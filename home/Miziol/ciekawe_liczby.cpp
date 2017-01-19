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

int main()
{
	int t[1000];

	for (int i = 0; i < 1000; i++)
	{
		cin >> t[i];
	}

	sito();	

//a

	int r = 0, ile = 0, w = 0;

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
				w++;
				break;
			}
		}
	}

	cout << "a) " << w << endl;

//b

	


}