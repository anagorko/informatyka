#include<iostream>
#include<math.h>

using namespace std;

const double p = 1/3;

int main()
{
	double n, w, t;

	for ( int i = 0; i < 100; i++ )
	{
		cin >> n;

		w = -1;

		for ( int j = 0; j < n; j++ )
		{
			cin >> t;

			if ( fmod ( pow ( t, p ), 1.00 ) == 0)
			{
				w = t;
//cout << w << " ";
			}
		}
cout << pow ( w, p ) << endl;

		if ( w != -1 ) cout << w << endl;
	}
}