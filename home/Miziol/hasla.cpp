#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
	int n = 200; //ilosc hasel

	string hasla[n];

	ifstream in;

	in.open("../../zbior_zadan/74/hasla.txt");

	for ( int i = 0; i < n; i++)
		in >> hasla[i];

	sort(hasla[0], hasla[n]);
}
