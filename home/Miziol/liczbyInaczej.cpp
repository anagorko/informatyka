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

	int x=45;

	cout << base[x].bin
		<< base[x].dec
		<< base[x].div
		<< base[x].par
		<< "\n";

//rozwiazanie a i b

	int a = 0, b = 0;

	for (int i = 0; i < 1000; i++)
	{
		if ( base[i].par == true) a++;
		if ( base[i].dec > base[b].dec) b = i;
	}

	cout << "a) " << a << "\nb) " << base[b].bin << " " << base[b].dec << endl;

//rozwiazanie c

	int l9 = 0, sum = 0;

	for ( int i = 0; i < 1000; i++)
	{
		if( base[i].div == true)
		{
			l9++;

			sum = sum + base[i].dec;
			
		}
	}

	cout << "c) " << l9 << " ";

	while ( sum > 0)
	{
		if ( sum % 2 == 0) cout << 0;
		if ( sum % 2 == 1) cout << 1;
		sum = sum / 2;
	}

return 0;
}