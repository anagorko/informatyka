#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int ilosc_okregow = 20;

	string nazwy_okregow[20];

	int glosy[20][5]; // komitety w kolejności K1 K2 K3 K4 K5

	int suma_glosow[20];


//wczytywanie
	for ( int i = 0; i < ilosc_okregow; i++ )
	{
		cin >> nazwy_okregow[i];

		for ( int j = 0; j < 5; j++ )
		{
			cin >> glosy[i][j];
		}
	}
//koniec wczytywanie

	for ( int i = 0; i < ilosc_okregow; i++ )
	{
		suma_glosow[i] = glosy[i][0] + glosy[i][1] + glosy[i][2] + glosy[i][3] + glosy[i][4];
	}

//86,2
	int m_k1 = 0, m_k2 = 0, m_k3 = 0, m_k4 = 0, m_k5 = 0;

	for ( int i = 1; i < ilosc_okregow; i++ )
	{
cout << (double) glosy[i][2] / (double) suma_glosow[i] << " " << (double) glosy[m_k2][2] / (double) suma_glosow[i] << " " << i << " " << m_k3 << endl;


		if( (double) glosy[i][0] / (double) suma_glosow[i] > (double) glosy[m_k1][0] / (double) suma_glosow[i] )
		{
			m_k1 = i;
		}
		if( (double) glosy[i][1] / (double) suma_glosow[i] > (double) glosy[m_k1][1] / (double) suma_glosow[i] )
		{
			m_k2 = i;
		}
		if( (double) glosy[i][2] / (double) suma_glosow[i] > (double) glosy[m_k2][2] / (double) suma_glosow[i] )
		{
			m_k3 = i;
		}
		if( (double) glosy[i][3] / (double) suma_glosow[i] > (double) glosy[m_k1][3] / (double) suma_glosow[i] )
		{
			m_k4 = i;
		}
		if( (double) glosy[i][4] / (double) suma_glosow[i] > (double) glosy[m_k1][4] / (double) suma_glosow[i] )
		{
			m_k5 = i;
		}
	}

	cout << "86.2" << endl << fixed << setprecision(2);
	cout << "K1 " << nazwy_okregow[m_k1] << endl;
	cout << "K2 " << nazwy_okregow[m_k2] << endl;
	cout << "K3 " << nazwy_okregow[m_k3] << endl;
	cout << "K4 " << nazwy_okregow[m_k4] << endl;
	cout << "K5 " << nazwy_okregow[m_k5] << endl;
}