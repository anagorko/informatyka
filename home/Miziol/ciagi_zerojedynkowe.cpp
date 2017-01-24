#include<iostream>

using namespace std;

bool cykliczna(string t)
{
	string w1, w2;

	if ( t.size() % 2 != 0 ) return false;

	w1 = t.substr(0,t.length()/2);
	w2 = t.substr(t.length()/2,t.length()/2);

	if ( w1 == w2 ) return true;

	return false;
}

bool jedynki(string t)
{
	for ( int i = 1; i < t.size(); i++ )
	{
		if ( t[i-1] == '1' && t[i] == '1') return false;
	}

	return true;
}



int main()
{
	string s;

	int cykliczne = 0, jedynkowe = 0;

	for ( int i = 0; i < 1000; i++ )
	{
		cin >> s;

		if ( cykliczna (s) ) cykliczne++;
		if ( jedynki (s) ) jedynkowe++;

	}

	cout << cykliczne << endl << jedynkowe << endl;
}