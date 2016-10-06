#include<iostream>
using namespace std;

int numer(char x)
{
	return ((int) x - 64);
}

string zaszyfruj(string slowo, string klucz)
{
	string p = slowo;
	int z;
	for(int i = 0; i < p.length(); i++)
	{
		z = (int) slowo[i] + numer(klucz[i]);
		if(z > 90) {z = z - 26;}
		p[i] = (char) z;
	}
	return p; 
}

string odszyfruj(string szyfr, string klucz)
{
	string s = szyfr;
	int z;
	for(int i = 0; i < s.length(); i++)
	{
		z = (int) szyfr[i] - numer(klucz[i]);
		if(z < 65) {z = z + 26;}
		s[i] = (char) z;
	}
	return s;
}

int main()
{
	string x, y, a;
	cin>>x>>y;
	cout<<zaszyfruj(x, y)<<endl;
}


