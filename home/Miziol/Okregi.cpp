#include<iostream>
#include<fstream>

using namespace std;



bool odbicie( double x, double y, double r, double x2, double y2, double r2 )
{
	if ( r != r2 )
		return false;
	if ( ( x == x2 && y == -y2 ) || (x == -x2 && y == -y2) )
		return true;

	return false;
}


int main()
{
	int n = 2000;
	int I = 0, II = 0, III = 0, IV = 0, V = 0; //79.1
	int lustrzane = 0; //79.2

	double t[n][3];

	ifstream in;

	in.open( "../../zbior_zadan/79/okregi.txt" );

	for ( int i = 0; i < n; i++ )
	{
		in >> t[i][0] >> t[i][1] >> t[i][2];
cout << t[i][0] << " " << t[i][1] << " " << t[i][2] << endl;
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

cout << V << endl;


//79.2
	bool lustro[n];

	for ( int i = 0; i < n; i++ )
		lustro[i] = true;

	for ( int i = 0; i < n; i++ )
	{
		int parki = 0;

		for ( int j = i + 1; j < n; j++ )
			if ( lustro[j] == true && odbicie( t[i][0], t[i][1], t[i][2], t[j][0], t[j][1], t[j][2] ) )
			{
				lustro[j] = false;
				parki++;
			}

		if ( parki == 3 )
			parki++;

		lustrzane = lustrzane + parki;
	}

// wynik
	cout << "79.1 " << endl << I << endl << II << endl << III << endl << IV << endl << V << endl;
	cout << "79.2 " << lustrzane << endl;

}