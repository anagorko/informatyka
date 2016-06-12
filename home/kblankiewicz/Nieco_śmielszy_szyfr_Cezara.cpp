#include <iostream>
#include<fstream>
using namespace std;

string zaszyfruj(string slowo, int klucz)
{
    int klucz2 = klucz % 26;
    int ascii1;
    int ascii2;

    string wynik = slowo;

    for(int i = 0; i < slowo.length(); i++)
    {
        ascii1 = (int) slowo[i];
        cout<<"ascii1  "<<ascii1<<endl;
        ascii2 = ascii1 + klucz2;
        if(ascii2 > 90)
        {
            ascii2 = 64 + (klucz - (90 - ascii1));
        }
        cout<<"ascii2  "<<ascii2<<endl;
        wynik[i] = (char) ascii2;
    }
    return wynik;
}

string rozszyfruj(string szyfr, int klucz)
{
    int klucz2 = klucz % 26;
    int ascii1;
    int ascii2;

    string wynik = szyfr;

    for(int i = 0; i < szyfr.length(); i++)
    {
        ascii1 = (int) szyfr[i];
        cout<<"ascii1  "<<ascii1<<endl;
        ascii2 = ascii1 - klucz2;
        if(ascii2 < 65)
        {
            ascii2 = 91 - (klucz2 - (ascii1 - 65));
        }
        cout<<"ascii2  "<<ascii2<<endl;
        wynik[i] = (char) ascii2;
    }
    return wynik;
}

void szyfrowanie(string dane, string wyniki)
{
    int klucz = 107;
    string dozrobienia;

    ifstream bookfile;
    bookfile.open(dane.c_str(), ios::in);

    ofstream plik;
    ofstream.open(wyniki.c_str(), ios::trunc);

    for(int i = 0; i < 100; i++)
    {
        bookfile >> dozrobienia;
        plik << zaszyfruj(dozrobienia, klucz);
    }

    bookfile.close();
    plik.close;
}

int blad(string slowo, string szyfr)
{
	int klucz1;
	int klucz2;
	int ascii1;
	int ascii2;

	for(int i = 0; i < szyfr.length(); i++)
	{
		ascii1 = (int) slowo[i];
		ascii2 = (int) szyfr[i];

		klucz1 = ascii1 - ascii2;
		if(i > 0)
		{
			if(klucz1 != klucz2)
			{
				return 1;
			}
		}
		klucz2 = klucz1;
	}
}

int main()
{
   szyfrowanie("dane_6_1.txt", "wyniki_6_1.txt");

    /*for(int i = 0; i < 3000; i++)
    {
        string x;
        int y;
        cin>>x>>y;
        cout<<rozszyfruj(x, y);
    }

    for(int i = 0; i < 3000; i++)
    {
        string a, b;
        cin>>a>>b;
        cout<<blad(a, b); //zwrócenie 1 oznacza błąd
    }
*/
}
