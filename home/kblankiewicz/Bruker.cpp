#include<iostream>
using namespace std;

class Rano
{
	int dzien, tyg;
	int zapas_g, zapas_b;
	int robota_g, robota_b;
	int dostawa_g, dostawa_b;

public:
	
	Rano(int dzien1, int tyg1, int zapas_g1, int zapas_b1, int robota_g1, int robota_b1, int dostawa_g1, int dostawa_b1)
	{
		dzien = dzien1 + 1;
		tyg = dzien % 7;
		zapas_g = zapas_g1 - robota_g1 + dostawa_g1 * 32;
		zapas_b = zapas_b1 - robota_b1 + dostawa_b1 * 28;
		if(tyg != 6 && tyg != 7) 
		{

		}
	}

};

int main()
{
	int liczba_dostaw_b;
	int data_dostwy_g;
	int zestawienie[];
	bool koniec;
}

