#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;


double abs( double x)
{
	if ( x < 0 )
		return -x;

	return x;
}


bool odbicie( double x, double y, double r, double x2, double y2, double r2 )
{
	if ( r != r2 )
		return false;

	if ( ( x == x2 && y == -y2 ) || (x == -x2 && y == y2) )
		return true;

	return false;
}


bool punktowe( double x, double y, double r, double x2, double y2, double r2 )
{
	if ( x == -x2 && y == -y2 && r == r2 )
		return true;

	return false;
}

bool obr90( double x, double y, double r, double x2, double y2, double r2 )
{
	if ( r != r2 )
		return false;

	if ( ( x == y2 && y == -x2 ) || (x == -y2 && y == x2) )
		return true;

	return false;
}


bool obr180( double x, double y, double r, double x2, double y2, double r2 )
{
	if ( x == -y2 && y == -x2 && r == r2 )
		return true;

	return false;
}

bool wspolny_punkt( double x, double y, double r, double x2, double y2, double r2 )
{
	if ( ( sqrt ( pow( (x - x2), 2 ) + pow( (y - y2), 2 ) ) <= (r + r2) ) && ( sqrt ( pow( (x - x2), 2 ) + pow( (y - y2), 2 ) ) > abs( (double) r - r2) ) )
		return true;

	return false;
}


int main()
{
	int n = 2000;
	int I = 0, II = 0, III = 0, IV = 0, V = 0; //79.1
	int lustrzane = 0; //79.2
	int prostopadle = 0; //79.3
	int max = 1; //79.4

	double t[n][3];

	ifstream in;

	in.open( "../../zbior_zadan/79/okregi.txt" );

	for ( int i = 0; i < n; i++ )
	{
		in >> t[i][0] >> t[i][1] >> t[i][2];
//cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << endl;
	}

//79.1

	for ( int i = 0; i < n; i++ )
	{
		if ( t[i][0] - t[i][2] > 0.00 && t[i][1] - t[i][2] > 0.00 )
			I++;
		if ( t[i][0] + t[i][2] < 0.00 && t[i][1] - t[i][2] > 0.00 )
			II++;
		if ( t[i][0] + t[i][2] < 0.00 && t[i][1] + t[i][2] < 0.00 )
			III++;
		if ( t[i][0] - t[i][2] > 0.00 && t[i][1] + t[i][2] < 0.00 )
			IV++;
	}

	V = n - I - II - III - IV;

//cout << V << endl;


//79.2
	bool lustro[n];

	for ( int i = 0; i < n; i++ )
		lustro[i] = true;

	for ( int i = 0; i < n; i++ )
	{
		int parki = 0;

		int wzgledem_punktu = -1;

		for ( int j = i + 1; j < n; j++ )
		{
			if ( lustro[j] && odbicie( t[i][0], t[i][1], t[i][2], t[j][0], t[j][1], t[j][2] ) )
			{
//cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << " " << t[j][0] << " " << t[j][1] << " " << t[j][2] << endl;
				lustro[j] = false;
				parki++;
			}

			if( lustro[j] && punktowe( t[i][0], t[i][1], t[i][2], t[j][0], t[j][1], t[j][2] ) )
			{
				wzgledem_punktu = j;
			}
		}

		if( parki == 1 && wzgledem_punktu > 0 )
		{
			parki++;

			lustro[ wzgledem_punktu ] = false;
		}

		if ( parki == 3 )
			parki++;

		lustrzane = lustrzane + parki;
	}

//79.3
	bool obroty[n];

	for ( int i = 0; i < n; i++ )
		obroty[i] = true;

	for ( int i = 0; i < n; i++ )
	{
		int parki = 0;

		int wzgledem_punktu = -1;

		for ( int j = i + 1; j < n; j++ )
		{
			if ( obroty[j] && obr90( t[i][0], t[i][1], t[i][2], t[j][0], t[j][1], t[j][2] ) )
			{
//cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << " " << t[j][0] << " " << t[j][1] << " " << t[j][2] << endl;
				obroty[j] = false;
				parki++;
			}

			if( obroty[j] && obr180( t[i][0], t[i][1], t[i][2], t[j][0], t[j][1], t[j][2] ) )
			{
				wzgledem_punktu = j;
			}
		}

		if( parki == 1 && wzgledem_punktu > 0 )
		{
			parki++;

			obroty[ wzgledem_punktu ] = false;
		}

		if ( parki == 3 )
			parki++;

		prostopadle = prostopadle + parki;
	}


// wynik
	cout << "79.1 " << endl << I << endl << II << endl << III << endl << IV << endl << V << endl;
	cout << "79.2 " << lustrzane << endl;
	cout << "79.3 " << prostopadle << endl;

//79.4
	int ciag = 1;

	cout << "79.4 ";

	for ( int i = 1; i < 1000; i++ )
	{
		//cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << " " << t[i-1][0] << " " << t[i-1][1] << " " << t[i-1][2] << endl;

		if ( wspolny_punkt( t[i][0], t[i][1], t[i][2], t[i-1][0], t[i-1][1], t[i-1][2] ) )
			ciag++;

		else
		{
			if ( ciag > max )
				max = ciag;
			cout << ciag << ", ";
			ciag = 1;
		}

	}

	cout << "max: " << max<< endl;

}