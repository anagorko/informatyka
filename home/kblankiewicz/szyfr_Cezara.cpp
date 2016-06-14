#include <iostream>
#include<fstream>
#include<cmath>
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
        ascii2 = ascii1 + klucz2;
        if(ascii2 > 90)
        {
            ascii2 = 65 + (klucz2 - (90 - ascii1));
        }
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
        ascii2 = ascii1 - klucz2;
        if(ascii2 < 65)
        {
            ascii2 = 91 - (klucz2 - (ascii1 - 65));
        }
        wynik[i] = (char) ascii2;
    }
    return wynik;
}

bool blad(string slowo, string szyfr)
{
	int klucz1;
	int klucz2;
	int ascii1;
	int ascii2;
	
	for(int i = 0; i < szyfr.length(); i++)
	{
		ascii1 = (int) slowo[i];
		ascii2 = (int) szyfr[i];
		
		if(ascii1 > ascii2)
		{
			klucz1 = ascii1 - ascii2;
		}
		else
		{
			klucz1 = (ascii1 - 65) + (91 - ascii2);
		}

		if(i > 0)
		{
			if(klucz1 != klucz2)
			{
				return true;
			}
		}
		klucz2 = klucz1;
	}
    return false;
}

void szyfrowanie(string dane, string wyniki)
{
    int klucz = 107;
    string dozrobienia;

    ifstream wejscie;
    wejscie.open(dane.c_str(), ios::in);

    ofstream wyjscie;
    wyjscie.open(wyniki.c_str(), ios::trunc);

    for(int i = 0; i < 100; i++)
    {
        wejscie >> dozrobienia;
        wyjscie << zaszyfruj(dozrobienia, klucz) << endl;
    }

    wejscie.close();
    wyjscie.close();
}

void rozszyfrowywanie(string dane, string wyniki)
{
    int aktualny_klucz;
    string do_zrobienia;

    ifstream wejscie;
    wejscie.open(dane.c_str(), ios::in);

    ofstream wyjscie;
    wyjscie.open(wyniki.c_str(), ios::trunc);

    for(int i = 0; i < 3000; i++)
    {
        wejscie >> do_zrobienia >> aktualny_klucz;
        wyjscie << rozszyfruj(do_zrobienia, aktualny_klucz) << endl;
    }

    wejscie.close();
    wyjscie.close();
}

void czy_blad(string dane, string wynik)
{

    string aktualne_slowo;
    string aktualny_szyfr;

    ifstream wejscie;
    wejscie.open(dane.c_str(), ios::in);

    ofstream wyjscie;
    wyjscie.open(wynik.c_str(), ios::trunc);

    for(int i = 0; i < 3000; i++)
    {
        wejscie >> aktualne_slowo >> aktualny_szyfr;
        if(blad(aktualne_slowo, aktualny_szyfr))
        {
            cout<<aktualne_slowo<<" "<<aktualny_szyfr<<endl;
            wyjscie << aktualne_slowo << endl;
        }
    }

    wejscie.close();
    wyjscie.close();
}

int main()
{
    
    szyfrowanie("dane_6_1.txt", "wyniki_6_1.txt");

    rozszyfrowywanie("dane_6_2.txt", "wynik_6_2.txt");

    czy_blad("dane_6_3.txt", "wynik_6_3.txt");
    
}
