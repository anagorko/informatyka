#include <iostream>
#include<math.h>
using namespace std;

bool narcystyczna (int x, int b)
{
	int xp = x;
	int r;
	int suma = 0;
	int licznik = 0;//liczy cyfry
	while(xp > 0){
		r = xp % b;
		xp = (xp - r) / b;
		licznik++;
	}
	xp = x;
	while(xp > 0){
		r = xp % b;
		xp = (xp - r) / b;
		suma = suma + pow(r, licznik);
	}
	if(suma == x){return true;}
	else {return false;}
}

int main()
{
cout << "Podaj liczbe do sprawdzenia:" << endl;
int q;
cin >> q;
cout << "i system, w którym ją podałeś:" << endl;
int s;
cin >> s;
if(narcystyczna(q,s) == true) {cout<< "A i owszem" << endl;}
else{cout << "niestety..." << endl;}
}
