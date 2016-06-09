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

int main()
{
    string s;
    int k;
    cin>>s>>k;
    cout << zaszyfruj(s, k);
    
    
    string x;
    int y;
    cin>>x>>y;
    cout<<zaszyfruj(x, y);

}
