#include<iostream>
#include<math.h>
#include<iomanip>

#define _USE_MATH_DEFINES

using namespace std;

int main()
{
	
	int point[2][10000];
	const int r = 200, a = 200, b = 200;
	int w = 0;

	for(int i = 0; i < 10000; i++)
	{
		cin >> point [0][i] >> point [1][i];
	}

	cout << "\n\n";
	for (int i = 0; i < 10000; i++) //4.1
	{
		if(pow( (point[0][i] - a), 2) + pow( (point[1][i] - b), 2) == pow(r, 2) ) cout << point[0][i] << " " << point[1][i] << endl;
		if(pow( (point[0][i] - a), 2) + pow( (point[1][i] - b), 2) < pow(r, 2) ) w++;
	}
	cout << w << endl;

	cout << "\n\n";
	w = 0;
	for(int i = 0; i < 10000; i++) //4.2
	{
		if(pow( (point[0][i] - a), 2) + pow( (point[1][i] - b), 2) <= pow(r, 2) ) w++;
	}
	cout << setprecision(5);
	cout << (double)(w*400*400)/(10000*r*r) << endl;

	cout << "\n\n";
	w=0;
	for (int i = 0; i < 1700; i++)
	{
		if(pow( (point[0][i] - a), 2) + pow( (point[1][i] - b), 2) <= pow(r, 2) ) w++;
		
		if (i == 999 || i == 1699)
		{
			double pi = ((double)w*400.00*400.00)/(((double)i+1)*(double)r*(double)r);
			cout << (double) fabs(M_PI - pi) << endl;
		}
	}
}