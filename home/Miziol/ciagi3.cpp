#include<iostream>
using namespace std;

int main()
{
	int r1, r2, r3, r4, n;
	int t[1000];

	for ( int i = 0; i < 20; i++ )
	{
		cin >> n;

		for ( int j = 0; j < n; j++ )
		{
			cin >> t[j];
			switch ( j )
			{
				case 1:
					r1 = t[j] - t[j-1];
				case 2:
					r2 = t[j] - t[j-1];
				case 3:
					r3 = t[j] - t[j-1];
				case 4:
					r4 = t[j] - t[j-1];
			}
		}

		if ( r1 != r2 && r2 == r3 )
		{
			cout << t[0] << endl;
			r1 = r2;
		}
		else if ( r1 != r2 && r2 != r3 && r3 == r4 )
		{
			cout << t[1] << endl;
			r1 = r4;
		}
		else if ( r1 != r2 && r2 != r3 && r1 == r4 )
		{
			cout << t[2] << endl;
		}
		else if ( r1 == r2 && r2 != r3 && r3 != r4 )
		{
			cout << t[3] << endl;
		}
		else 
		{
			for ( int j = 4; j < n; j++ )
			{
				if ( r1 != t[j-1] - t[j] )
				{
					cout << t[j] << endl;
					break;
				}
			}
		}
	}
}