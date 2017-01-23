#include<iostream>

using namespace std;

int main()
{
	int t[1000];
	int min, max;

	cin >> t[0];
	min = t[0];
	max = t[0];

	for (int i = 1; i < 1000; i++ )
	{
		cin >> t[i];
		if( t[i] > max ) max = t[i];
		if( t[i] < min ) min = t[i];
	}

	cout << min << " " << max << endl;
}