#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

//ABCDE FGHIJ KLMNO PQRST UVWXY Z
int ilosc = 26;
int litery[26], pary = 0;
long long int suma_liter = 0;
string podslowo;
int ilosc_podslow;

bool takie_same(string s)
{
	for (int i = 1; i < s.size(); i++)
	{
		if( s[i] == s[i-1] )
			return true;
	}

	return false;
}

void rozklad_na_litery(string s)
{
	for( int i = 0; i < s.size(); i++ )
	{
		litery[ (int) s[i] - 65 ]++;
	}

	return;
}

void pod_slowa(string s)
{
	//A E I O U Y

	for ( int i = 0; i < s.size(); i++ )
	{
		if( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' )
		{
			int l = 1;

			string odp = "";
			odp = odp + s[i];

			bool samogloska = true;

			for ( i++; i < s.size(); i++)
			{
				switch(s[i])
				{
					case 'A':
					case 'E':
					case 'I':
					case 'O':
					case 'U':
					case 'Y':
						odp = odp + s[i];
						l++;
						break;
					default:
						samogloska = false;
				}

				if( !samogloska )
					break;
			}

			if ( odp.size() > podslowo.size() )
			{
				podslowo = odp;
				ilosc_podslow = 1;
			}

			if ( odp.size() == podslowo.size() )
			{
				ilosc_podslow++;
			}
		}
	}
}

int main()
{
	string s;

	ifstream in;

	in.open( "../../zbior_zadan/73/tekst.txt" );

	int n = 1876; //ilość słów

	for (int i = 0; i < n; i++)
	{
		in >> s;

		suma_liter = suma_liter + s.size();

		if( takie_same(s) )
			pary++;

		rozklad_na_litery(s);

		takie_same(s);

		pod_slowa(s);
	}

	cout << "a) " << pary << endl;

	setprecision(2);

	cout << "b) A: " << litery[0] << " (" << fixed << setprecision(2) << (double) ( (double) litery[0] / (double) suma_liter ) * 100.00 << "%)" << endl;

	for( int i = 1; i < ilosc; i++ )
	{
		cout << "   " << (char) (i + 65) << ": " << litery[i] << " (" << fixed << setprecision(2) << (double) ( (double) litery[i] / (double) suma_liter ) * 100.00 << "%)" << endl;
	}

	cout << "c) " << podslowo.size() << " " << ilosc_podslow << " " << podslowo << endl;
}