#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

bool tylko_cyfry( string s )
{
	for ( int i = 0; i < s.size(); i++ )
	{
		if( (int) s[i] < '0' || (int) s[i] > '9' )
			return false;
	}

	return true;
}

bool kolejne_znaki( string s )
{
	if( s.size() < 4 )
		return false;

	for ( int i = 3; i < s.size(); i++ )
	{
		vector <int> wartosci;
		wartosci.push_back( (int) s[i] );
		wartosci.push_back( (int) s[i-1] );
		wartosci.push_back( (int) s[i-2] );
		wartosci.push_back( (int) s[i-3] );

		sort(wartosci.begin(), wartosci.end());

		if( wartosci[0] + 1 == wartosci[1] && wartosci[1] + 1 == wartosci[2] && wartosci[2] + 1 == wartosci[3] )
			return true;
	}

	return false;
}

bool trudne_haslo( string s )
{
	bool cyfra = false, mala = false, duza = false;

	for ( int i = 0; i < s.size(); i++ )
	{
		if( s[i] <= '9' && s[i] >= '0' )
			cyfra = true;

		if( s[i] <= 'z' && s[i] >= 'a' )
			mala = true;

		if( s[i] <= 'Z' && s[i] >= 'A' )
			duza = true;
	}

	return cyfra && mala && duza;
}


int main()
{
	int n = 200; //ilosc hasel

	vector <string> hasla;

	string s, ostatni_taki_sam;

	ifstream in;

	in.open("../../zbior_zadan/74/hasla.txt");

	int cyfrowe = 0, kolejne = 0, trudne = 0;

	for ( int i = 0; i < n; i++)
	{
		in >> s;
		hasla.push_back(s);
	
		if( tylko_cyfry(s) )
			cyfrowe++;

		if( kolejne_znaki(s) )
			kolejne++;

		if( trudne_haslo(s) )
			trudne++;
	}

	sort(hasla.begin(), hasla.end());



	cout << "a) " << cyfrowe << endl;

	cout << "b) " << endl;
	for ( int i = 1; i < n; i++)
	{
		if( hasla[i] == hasla[i-1] )
		{
			ostatni_taki_sam = hasla[i];
			cout << ostatni_taki_sam << endl;
		}
	}

	cout << "c) " << kolejne << endl;

	cout << "d) " << trudne << endl;
}