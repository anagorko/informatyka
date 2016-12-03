//Maj 2011 zad 6
#include<iostream>
#include<vector>

using namespace std;

class Liczba
{
public:

	string bin;
	int dec;
	bool div, par;

	void count()
	{
		dec = 0;
		div = 0;
		par = 0;

		if ( bin[bin.size() - 1] == '0') par = true;
		if ( bin.size() == 9 ) div = true;
		for ( int i = 0;  i < bin.size(); i++)
		{
			dec = dec * 2 + bin[i] - '0';
		}
	}
};

int main()
{
	Liczba base[1000];

	for ( int i = 0; i < 1000; i++ )
	{
		cin >> base[i].bin;

		base[i].count();
	}

//rozwiazanie a i b

	int a = 0, b = 0;

	for (int i = 0; i < 1000; i++)
	{
		if ( base[i].par == true) a++;
		if ( base[i].dec > base[b].dec) b = i;
	}

	cout << "a) " << a << "\nb) " << base[b].bin << " " << base[b].dec << endl;

//rozwiazanie c

	string c = "000000000",rs;

	char f = '0';

	int r, l9 = 0;

	for ( int i = 0; i < 1000; i++)
	{
		if( base[i].div == true)
		{
			l9++;
			r = 0;
			rs = c;
			c = "";

			for ( int j = 8; j >= 0; j--)
			{
				r = rs[j] - '0' + base[i].bin[j] - '0' + r;
				f = (r%2) + '0';

				cout << f << endl;

				c = f + c;
				r = r - 2;
			}
		}
	}

	cout << "c) " << l9 << " " << c << endl;


}