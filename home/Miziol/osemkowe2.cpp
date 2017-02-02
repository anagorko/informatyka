#include<iostream>

using namespace std;

int main()
{
	int t[1000];
	int p=0, l=1;
	int wp = 0, wl = 0;

	cin >> t[0];

	for ( int i = 1; i < 1000; i++ )
	{
		cin >> t[i];
		if ( t[i] >= t[i-1] )
		{
			l++;
		}
		if ( t[i] < t[i-1] )
		{
			if ( l > wl )
			{
				wp = p;
				wl = l;
			}

			p = i;
			l = 1;
		}
	}

	cout << t[wp] << " " << wl << endl;
}