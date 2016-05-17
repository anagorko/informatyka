#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream plik;
    
    plik.open("test.txt", ios::app | ios::out | ios::in);
    
    plik << "TEST";
    
    plik.close();
    
    return 0;
}
