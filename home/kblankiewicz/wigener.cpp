#include<iostream>
#include<fstream>

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
		z = (int) slowo[i] + numer(klucz[i % klucz.length()]);
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
		z = (int) szyfr[i] - numer(klucz[i % klucz.length()]);
		if(z < 65) {z = z + 26;}
		s[i] = (char) z;
	}
	return s;
}

void zadanie_a(string slowa, string klucze)
{
    ifstream plik1;
    plik1.open(slowa.c_str(), ios::in);

    ifstream plik2;
    plik2.open(klucze.c_str(), ios::in);

    cout<<endl<<"zadanie a):"<<endl;
    string a, b, c;
    while(!plik1.eof())
    {
        plik1>>a;
        plik2>>b;
        c = zaszyfruj(a, b);
        cout<<c<<endl;
    }

}

void zadanie_b(string slowa, string klucze)
{
    ifstream plik1;
    plik1.open(slowa.c_str(), ios::in);

    ifstream plik2;
    plik2.open(klucze.c_str(), ios::in);

    cout<<endl<<"zadanie b): "<<endl;
    string a, b, c;
    while(!plik1.eof())
    {
        plik1>>a;
        plik2>>b;
        c = odszyfruj(a, b);
        cout<<c<<endl;
    }
}
int main()
{
    zadanie_a("tj.txt", "klucze1.txt");
    zadanie_b("sz.txt", "klucze2.txt");
	/*string x, y, a;
	cin>>x>>y;
	cout<<zaszyfruj(x, y)<<endl;*/
}
